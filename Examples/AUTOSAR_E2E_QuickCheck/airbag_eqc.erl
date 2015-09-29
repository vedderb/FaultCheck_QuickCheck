%%% @author Thomas Arts <>
%%% @copyright (C) 2013, Thomas Arts
%%% @doc QuickCheck module for testing an application that uses E2E library
%%%      The idea is to have Benjamin make a special C mocking in which faults can be injected
%%%      Later on, it is worth showing that all that C code is unnecessary when we use
%%%      the component library and eqc_mocking_c.
%%%
%%%      The Airbag consists of two C applications that run separately and communicate via the Com stack
%%%      Application1 is the sensor. It sends data to A2. Whenever it sends the two bytes <<010101010 10101010>> to A2
%%%      the airbag should explode, otherwise, it should not.
%%%      Note that we assume that the same value is send continuously to A2 and that only after a few iterations A2
%%%      decides to explode.
%%%      Safety case: when NOT sending these bytes, the airbacg should NOT explode'
%%% 
%%% @end
%%% Created : 22 Aug 2013 by Thomas Arts <>

%%% @author Thomas Arts <>
%%% @copyright (C) 2013, Thomas Arts
%%% @doc
%%%
%%% @end
%%% Created : 22 Aug 2013 by Thomas Arts <>

-module(airbag_eqc).

% yes or no
-define(USE_E2E, yes).

-include_lib("eqc/include/eqc.hrl").
-include_lib("eqc/include/eqc_statem.hrl").

-compile(export_all).

-record(state, {data =[], faults = []}).

initial_state() ->
  #state{}.

byte() ->
  choose(0,255).

is_explode([B1,B2]) ->
  B1 == 85 andalso B2 == 170.

% The sensor command
sensor(Data) ->
  DataPtr = eqc_c:create_array(unsigned_char,Data),
  case ?USE_E2E of
    yes ->
      c_call:sensor_e2e(DataPtr),
      c_call:airbag_iteration_e2e();
    no ->
      c_call:sensor(DataPtr),
      c_call:airbag_iteration()
  end,
  eqc_c:value_of(airbag_active).

%sensor_args(_S) -> 
%  [[frequency([{40, byte()}, {60, 85}]), 
%    frequency([{40, byte()}, {60, 170}])]].

%sensor_args(_S) -> 
%  [[frequency([{10, 84},
%               {10, 87},
%               {10, 117},
%               {10, 213},
%               {10, 21}]),
%                
%                170]].

sensor_args(_S) -> 
  [[byte(), 170]].

sensor_pre(_S, [Data]) ->
  not is_explode(Data).


sensor_post(_S, [_Data], Res) ->
  Res == 0.

% The bitflip command
bit_flip(Byte,Bit) ->
    c_call:faultcheck_packet_addFaultCorruptionBitFlip("airbag", Byte, Bit).

bit_flip_args(_S) ->
    case ?USE_E2E of
      yes -> [ choose(0,3), choose(0,7) ];
      no -> [ choose(0,1), choose(0,7) ]
    end.

bit_flip_pre(S,[Byte,Bit]) ->
    length(S#state.faults) < 4 andalso
	not lists:member({bitflip,Byte,Bit},S#state.faults).

bit_flip_next(S, _, [Byte, Bit]) ->
    S#state{faults = S#state.faults ++ [{bitflip, Byte, Bit}]}.

% The repetition command
repetition(Num) ->
    c_call:faultcheck_packet_addFaultRepeat("airbag", Num).

repetition_args(_S) ->
    [ choose(1, 3) ].

repetition_pre(S, [Num]) ->
    length(S#state.faults) < 4 andalso
	not lists:member({repetition, Num}, S#state.faults).

repetition_next(S, _, [Num]) ->
    S#state{faults = S#state.faults ++ [{repetition, Num}]}.

% A command that tests if the explosin works without faults. This is to make
% sure that the E2E-library is not blocking everything for some reason.
explosion(Data) ->
  DataPtr = eqc_c:create_array(unsigned_char, Data),
  c_call:faultcheck_packet_removeAllFaults(),
  case ?USE_E2E of
    yes ->
      % Call the sensor function often enough for the E2E library
      % to recover (15 times)
      [ c_call:sensor_e2e(DataPtr) || _<-lists:seq(1,15) ], 
      c_call:airbag_iteration_e2e();
    no ->
      c_call:sensor(DataPtr),
      c_call:sensor(DataPtr),
      c_call:airbag_iteration()
  end,
  Res = eqc_c:value_of(airbag_active),
  c_call:application_init(),
  Res.

explosion_args(_S) -> 
  [[85, 170]].

explosion_post(_S, [_Data], Res) ->
  Res == 1.

%% @doc weight/2 - Distribution of calls
-spec weight(S :: eqc_statem:symbolic_state(), Command :: atom()) -> integer().
weight(_S, sensor) -> 10;
weight(_S, bit_flip) -> 1;
weight(_S, _Cmd) -> 1.

%% @doc Default generated property
-spec prop_safety() -> eqc:property().
prop_safety() ->
  ?FORALL(Cmds, commands(?MODULE), 
		    begin
			eqc_c:restart(),
			c_call:application_init(),
			{H, S, Res} = run_commands(?MODULE,Cmds),
			pretty_commands(?MODULE, Cmds, {H, S, Res},
					aggregate(command_names(Cmds), Res == ok))
		    end).

start_cfile() ->
    eqc_c:start(c_call, [{c_src, "./application.c"}, 
			{cppflags,
			" -std=gnu99"
			" -IE2E/inc" ++
			 case os:getenv("FAULTCHECK_PATH") of
			   false ->
			     "";
			   Path ->
			     " -I" ++ Path ++
			     " -L" ++ Path ++
			     " -LE2E -lautosare2e -lFaultCheck"
			     " -coverage"
			 end}]).

test(N) ->
    start_cfile(),
    eqc:quickcheck(eqc:numtests(N, airbag_eqc:prop_safety())).
    
test() ->
    test(100).

