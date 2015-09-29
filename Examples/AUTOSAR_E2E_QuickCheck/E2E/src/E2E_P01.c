#include "E2E_P01.h"
extern int printf(const char *, ...);

uint8 min_u8(uint8, uint8);
uint8 E2E_CalcCRC(E2E_P01ConfigType* Config, uint8 Counter, uint8* Data);

Std_ReturnType E2E_P01Protect(E2E_P01ConfigType* Config, 
                              E2E_P01SenderStateType* State, 
                              uint8* Data){

  if(Config == NULL || State == NULL || Data == NULL) 
    return E2E_E_INPUTERR_NULL;

  if(Config->CounterOffset % 8 == 0){
    *(Data+(Config->CounterOffset/8)) = 
      (*(Data+(Config->CounterOffset/8)) & 0xF0) | 
      (State->Counter & 0x0F);

  } else {
    *(Data + (Config->CounterOffset/8)) = 
      (*(Data + (Config->CounterOffset/8)) & 0x0F) | 
      ((State->Counter << 4) & 0xF0);
  }
  
  uint8 CRC = E2E_CalcCRC(Config, State->Counter, Data);
  
  *(Data + (Config->CRCOffset/8)) = CRC;

  State->Counter = (State->Counter + 1) % 15;

  return E2E_E_OK;
}

Std_ReturnType E2E_P01Check(E2E_P01ConfigType* Config, 
                            E2E_P01ReceiverStateType* State, 
                            uint8* Data){
  if(Config == NULL || State == NULL || Data == NULL) return E2E_E_INPUTERR_NULL;

  /* State->MaxDeltaCounter = min_u8(State->MaxDeltaCounter + 1, 15); */
  State->MaxDeltaCounter = min_u8(State->MaxDeltaCounter + 1, 14);

  if(State->NewDataAvailable == TRUE){
    uint8 RcvdCounter = *(Data + (Config->CounterOffset/8)) & 0x0F;
    if(Config->CounterOffset % 8 != 0){
      RcvdCounter = (*(Data + (Config->CounterOffset/8)) >> 4) & 0x0F;
    }
    
    uint8 RcvdCRC = *(Data + (Config->CRCOffset/8));
    
    uint8 CalcCRC = E2E_CalcCRC(Config, RcvdCounter, Data);

    if(RcvdCRC == CalcCRC){
      if(State->WaitForFirstData){
        State->WaitForFirstData = FALSE;
        State->MaxDeltaCounter = Config->MaxDeltaCounterInit;
        State->LastValidCounter = RcvdCounter;
        
        State->Status = E2E_P01STATUS_INITAL;
      } else {
        int DeltaCounter = ((15 + RcvdCounter) - State->LastValidCounter) % 15;

        if(DeltaCounter == 0){
          State->Status = E2E_P01STATUS_REPEATED;
        } else if(DeltaCounter > State->MaxDeltaCounter){
          State->Status = E2E_P01STATUS_WRONGSEQUENCE;
        } else {
          State->MaxDeltaCounter = Config->MaxDeltaCounterInit;
          State->LastValidCounter = RcvdCounter;
          State->LostData = DeltaCounter - 1;

          if(DeltaCounter == 1){
            State->Status = E2E_P01STATUS_OK;
          } else {
            State->Status = E2E_P01STATUS_OKSOMELOST;
          }
        } 
      }      
    } else {
      State->Status = E2E_P01STATUS_WRONGCRC;
    }      
  } else {
    State->Status = E2E_P01STATUS_NONEWDATA;
  }

  return E2E_E_OK;
}

uint8 E2E_CalculateCRC8(uint8 Data, uint8 CRCIn){
  return Crc_CalculateCRC8(&Data, 1, CRCIn, FALSE);
}

uint8 E2E_CalcCRC(E2E_P01ConfigType* Config, uint8 Counter, uint8* Data){
  uint8 CRC;
  
  switch(Config->DataIDMode){
  case E2E_P01_DATAID_BOTH:
    CRC = E2E_CalculateCRC8((uint8)Config->DataID, 0xFF);
    CRC = E2E_CalculateCRC8((uint8)(Config->DataID >> 8), CRC);
    break;
  case E2E_P01_DATAID_ALT:
    if(Counter % 2 == 0){
      CRC = E2E_CalculateCRC8((uint8)Config->DataID, 0xFF);
    } else {
      CRC = E2E_CalculateCRC8((uint8)(Config->DataID >> 8), 0xFF);
    }
    break;
  case E2E_P01_DATAID_LOW:
    CRC = E2E_CalculateCRC8((uint8)Config->DataID, 0xFF);
    break;
  }

  if(Config->CRCOffset >= 8){
    CRC = Crc_CalculateCRC8 (Data, (Config->CRCOffset / 8), CRC, FALSE);
  }

  if(Config->CRCOffset / 8 < (Config->DataLength / 8) - 1){
    CRC = Crc_CalculateCRC8 (& Data[Config->CRCOffset/8 + 1], 
                             (Config->DataLength / 8 - Config->CRCOffset / 8 - 1), 
                             CRC, FALSE);
  }

  CRC = CRC ^ 0xFF;

  return CRC;
}

uint8 min_u8(uint8 a, uint8 b){
  if(a < b) return a;
  return b;
}
