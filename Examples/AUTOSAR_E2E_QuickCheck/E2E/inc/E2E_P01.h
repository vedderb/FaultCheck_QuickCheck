#ifndef E2E_P01_H
#define E2E_P01_H

#include "E2E.h"

typedef enum {
  E2E_P01_DATAID_BOTH,
  E2E_P01_DATAID_ALT,
  E2E_P01_DATAID_LOW
} E2E_P01DataIDMode;

typedef enum {
  E2E_P01STATUS_OK,
  E2E_P01STATUS_NONEWDATA,
  E2E_P01STATUS_WRONGCRC,
  E2E_P01STATUS_INITAL,
  E2E_P01STATUS_REPEATED,
  E2E_P01STATUS_OKSOMELOST,
  E2E_P01STATUS_WRONGSEQUENCE
} E2E_P01ReceiverStatusType;

typedef struct {
  uint8 Counter;
} E2E_P01SenderStateType;

typedef struct {
  uint16 CounterOffset;
  uint16 CRCOffset;
  uint16 DataID;
  E2E_P01DataIDMode DataIDMode;
  uint16 DataLength;
  uint8 MaxDeltaCounterInit;
} E2E_P01ConfigType; 

typedef struct {
  uint8 LastValidCounter;
  uint8 MaxDeltaCounter;
  boolean WaitForFirstData;
  boolean NewDataAvailable;
  uint8 LostData;
  E2E_P01ReceiverStatusType Status;
} E2E_P01ReceiverStateType;

Std_ReturnType E2E_P01Protect(E2E_P01ConfigType*, E2E_P01SenderStateType*, uint8*);

Std_ReturnType E2E_P01Check(E2E_P01ConfigType*, E2E_P01ReceiverStateType*, uint8*);

#endif
