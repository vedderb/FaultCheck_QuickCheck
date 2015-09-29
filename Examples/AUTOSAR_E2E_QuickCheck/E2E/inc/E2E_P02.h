#ifndef E2E_P02_H
#define E2E_P02_H

#include "E2E.h"

typedef enum {
  E2E_P02STATUS_OK,
  E2E_P02STATUS_NONEWDATA,
  E2E_P02STATUS_WRONGCRC,
  E2E_P02STATUS_INITAL,
  E2E_P02STATUS_REPEATED,
  E2E_P02STATUS_OKSOMELOST,
  E2E_P02STATUS_WRONGSEQUENCE
} E2E_P02ReceiverStatusType;

typedef struct {
  uint8 Counter;
} E2E_P02SenderStateType;

typedef struct {
  uint16 DataLength;
  uint8  DataIDList[16];
  uint8  MaxDeltaCounterInit;
} E2E_P02ConfigType; 

typedef struct {
  uint8 LastValidCounter;
  uint8 MaxDeltaCounter;
  boolean WaitForFirstData;
  boolean NewDataAvailable;
  uint8 LostData;
  E2E_P02ReceiverStatusType Status;
} E2E_P02ReceiverStateType;

Std_ReturnType E2E_P02Protect(E2E_P02ConfigType*, E2E_P02SenderStateType*, uint8*);

Std_ReturnType E2E_P02Check(E2E_P02ConfigType*, E2E_P02ReceiverStateType*, uint8*);

#endif
