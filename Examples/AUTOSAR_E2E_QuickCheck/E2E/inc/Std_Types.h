/*------------------------------------------------------------------------------
-- Copyright   : (C) 2012 SP Technical Research Institute of Sweden
--------------------------------------------------------------------------------
-- File        : Std_Types.h
-- Author      : Rickard Svenningsson
-- Description : Header file (only complete for its purpose).
-- Purpose     : Cluster test
-- Autosar rev : R4.0 Rev 2
-- Reference   : AUTOSAR_SWS_StandardTypes.pdf
--------------------------------------------------------------------------------
-- History     : 2012-02-22: First version       Rickard Svenningsson
------------------------------------------------------------------------------*/

/* Note: ToBeChecked  r1 vs r2 */

#ifndef STD_TYPES_H  // STD014
#define STD_TYPES_H

#include "Platform_Types.h" // STD001
#include "Compiler.h"       // STD001

/* Type definitions */
typedef uint8 Std_ReturnType;    // STD005
typedef struct                   // STD015
{
   uint16   vendorID;
   uint16   moduleID;
   uint8    sw_major_version;
   uint8    sw_minor_version;
   uint8    sw_patch_version;
} Std_VersionInfoType;

/* Symbol definitions */
#ifndef STATUSTYPEDEFINED  // STD006
   #define STATUSTYPEDEFINED
   #define E_OK   0x00

   typedef unsigned char StatusType;
#endif

#define E_NOT_OK     0x01     // STD006

#define STD_HIGH     0x01     // STD007
#define STD_LOW      0x00

#define STD_ACTIVE   0x01     // STD013
#define STD_IDLE     0x00

#define STD_ON       0x01     // STD010
#define STD_OFF      0x00

#endif /* STD_TYPES_H */
