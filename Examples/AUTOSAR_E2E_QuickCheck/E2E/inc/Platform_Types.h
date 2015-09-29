/*------------------------------------------------------------------------------
-- Copyright   : (C) 2012 SP Technical Research Institute of Sweden
--------------------------------------------------------------------------------
-- File        : Platform_Types.h
-- Author      : Rickard Svenningsson
-- Description : Header file (only complete for its purpose).
-- Purpose     : Cluster test
-- Autosar rev : R4.0 Rev 2
-- Reference   : AUTOSAR_SWS_PlatformTypes.pdf
--------------------------------------------------------------------------------
-- History     : 2012-02-22: First version       Rickard Svenningsson
------------------------------------------------------------------------------*/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

// PLATFORM057
#define CPU_TYPE_8      8
#define CPU_TYPE_16     16
#define CPU_TYPE_32     32

#define MSB_FIRST       0
#define LSB_FIRST       1

#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST  1


#define CPU_TYPE           CPU_TYPE_32       // PLATFORM044, PLATFORM045
#define CPU_BIT_ORDER      LSB_FIRST         // PLATFORM043, PLATFORM049
#define CPU_BYTE_ORDER     LOW_BYTE_FIRST    // PLATFORM046, PLATFORM051

// PLATFORM056
#ifndef TRUE
   #define TRUE 1
#endif
#ifndef FALSE
   #define FALSE 0
#endif

/* Type definitions */
typedef unsigned char boolean;   // PLATFORM060
typedef unsigned char uint8;     // PLATFORM013
typedef unsigned short uint16;   // PLATFORM014
typedef unsigned int uint32;     // PLATFORM015
typedef char sint8;              // PLATFORM016
typedef short sint16;            // PLATFORM017
typedef int  sint32;             // PLATFORM018

typedef uint8 uint8_least;       // PLATFORM020
typedef uint16 uint16_least;     // PLATFORM021
typedef uint32 uint32_least;     // PLATFORM022
typedef sint8 sint8_least;       // PLATFORM023
typedef sint16 sint16_least;     // PLATFORM024
typedef sint32 sint32_least;     // PLATFORM025

typedef float float32;           // PLATFORM041
typedef double float64;          // PLATFORM042


#endif /* PLATFORM_TYPES_H */
