#include "E2E_P02.h"
extern int printf(const char *, ...);

Std_ReturnType E2E_P02Protect(E2E_P02ConfigType* Config, 
                              E2E_P02SenderStateType* State, 
                              uint8* Data){

  if(Config == NULL || State == NULL || Data == NULL) 
    return E2E_E_INPUTERR_NULL;

  Data[1] = (Data[1] & 0xF0) | (State->Counter & 0x0F);

  uint8 DataId = Config->DataIDList[State->Counter];

  uint8 CRC = Crc_CalculateCRC8H2F((Data + 1), Config->DataLength / 8 - 1, 0, 1);

  CRC = Crc_CalculateCRC8H2F(&DataId, 1, CRC, 0);

  Data[0] = CRC;

  State->Counter = (State->Counter + 1) % 16;

  return E2E_E_OK;
}

Std_ReturnType E2E_P02Check(E2E_P02ConfigType* Config, 
                            E2E_P02ReceiverStateType* State, 
                            uint8* Data){
  if(Config == NULL || State == NULL || Data == NULL) return E2E_E_INPUTERR_NULL;

  if(State->MaxDeltaCounter < 15)  State->MaxDeltaCounter = State->MaxDeltaCounter + 1;

  if(State->NewDataAvailable == TRUE){
    uint8 RcvdCounter = Data[1] & 0x0F;

    uint8 DataId = Config->DataIDList[RcvdCounter];
    
    uint8 RcvdCRC = Data[0];
    
    uint8 CalcCRC = Crc_CalculateCRC8H2F((Data + 1), Config->DataLength / 8 - 1, 0, 1);

    CalcCRC = Crc_CalculateCRC8H2F(&DataId, 1, CalcCRC, 0);

    if(RcvdCRC == CalcCRC){
      if(State->WaitForFirstData){
        State->WaitForFirstData = FALSE;
        State->MaxDeltaCounter = Config->MaxDeltaCounterInit;
        State->LastValidCounter = RcvdCounter;
        
        State->Status = E2E_P02STATUS_INITAL;
      } else {
        int DeltaCounter = ((16 + RcvdCounter) - State->LastValidCounter) % 16;

        if(DeltaCounter == 0){
          State->Status = E2E_P02STATUS_REPEATED;
        } else if(DeltaCounter > State->MaxDeltaCounter){
          State->Status = E2E_P02STATUS_WRONGSEQUENCE;
        } else {
          State->MaxDeltaCounter = Config->MaxDeltaCounterInit;
          State->LastValidCounter = RcvdCounter;
          State->LostData = DeltaCounter - 1;

          if(DeltaCounter == 1){
            State->Status = E2E_P02STATUS_OK;
          } else {
            State->Status = E2E_P02STATUS_OKSOMELOST;
          }
        }
      }
    } else {
      State->Status = E2E_P02STATUS_WRONGCRC;
    }
  } else {
    State->Status = E2E_P02STATUS_NONEWDATA;
  }

  return E2E_E_OK;
}
