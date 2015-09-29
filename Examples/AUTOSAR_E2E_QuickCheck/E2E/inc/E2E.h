#ifndef E2E_H
#define E2E_H

#include "Crc.h"
#include "Std_Types.h"

#define E2E_E_OK 0x00
#define E2E_E_INPUTERR_NULL 0x13
#define E2E_E_INPUTERR_WRONG 0x17
#define E2E_E_INTERR 0x19
#define E2E_E_INVALID 0xFF

#ifndef NULL
#define NULL (void *)0
#endif

#endif
