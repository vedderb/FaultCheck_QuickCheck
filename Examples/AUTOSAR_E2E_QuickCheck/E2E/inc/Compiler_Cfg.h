/*------------------------------------------------------------------------------
-- Copyright   : (C) 2012 SP Technical Research Institute of Sweden
--------------------------------------------------------------------------------
-- File        : Compiler_Cfg.h
-- Author      : Rickard Svenningsson
-- Description : Header file (only complete for its purpose).
-- Purpose     : Cluster test
-- Autosar rev : R4.0 Rev 3
-- Reference   : AUTOSAR_SWS_CompilerAbstraction.pdf
--------------------------------------------------------------------------------
-- History     : 2012-02-22: First version       Rickard Svenningsson
------------------------------------------------------------------------------*/

#ifndef COMPILER_CFG_H // COMPILER047
#define COMPILER_CFG_H

#if (defined CAN_CODE)
#error CAN_CODE already defined
#endif
#define CAN_CODE

#if (defined CAN_CONST)
#error CAN_CONST already defined
#endif
#define CAN_CONST

#if (defined CAN_APPL_DATA)
#error CAN_APPL_DATA already defined
#endif
#define CAN_APPL_DATA

#if (defined CAN_APPL_CONST)
#error CAN_APPL_CONST already defined
#endif
#define CAN_APPL_CONST

#if (defined CAN_APPL_CODE)
#error CAN_APPL_CODE already defined
#endif
#define CAN_APPL_CODE

#if (defined CAN_VAR_NOINIT)
#error CAN_VAR_NOINIT already defined
#endif
#define CAN_VAR_NOINIT

#if (defined CAN_VAR_POWER_ON_INIT)
#error CAN_VAR_POWER_ON_INIT already defined
#endif
#define CAN_VAR_POWER_ON_INIT

#if (defined CAN_VAR_FAST)
#error CAN_VAR_FAST already defined
#endif
#define CAN_VAR_FAST

#if (defined CAN_VAR)
#error CAN_VAR already defined
#endif
#define CAN_VAR

#if (defined CANIF_CODE)
#error CANIF_CODE already defined
#endif
#define CANIF_CODE

#if (defined CANIF_CONST)
#error CANIF_CONST already defined
#endif
#define CANIF_CONST

#if (defined CANIF_APPL_DATA)
#error CANIF_APPL_DATA already defined
#endif
#define CANIF_APPL_DATA

#if (defined CANIF_APPL_CONST)
#error CANIF_APPL_CONST already defined
#endif
#define CANIF_APPL_CONST

#if (defined CANIF_APPL_CODE)
#error CANIF_APPL_CODE already defined
#endif
#define CANIF_APPL_CODE

#if (defined CANIF_VAR_NOINIT)
#error CANIF_VAR_NOINIT already defined
#endif
#define CANIF_VAR_NOINIT

#if (defined CANIF_VAR_POWER_ON_INIT)
#error CANIF_VAR_POWER_ON_INIT already defined
#endif
#define CANIF_VAR_POWER_ON_INIT

#if (defined CANIF_VAR_FAST)
#error CANIF_VAR_FAST already defined
#endif
#define CANIF_VAR_FAST

#if (defined CANIF_VAR)
#error CANIF_VAR already defined
#endif
#define CANIF_VAR

#if (defined CANNM_CODE)
#error CANNM_CODE already defined
#endif
#define CANNM_CODE

#if (defined CANNM_CONST)
#error CANNM_CONST already defined
#endif
#define CANNM_CONST

#if (defined CANNM_APPL_DATA)
#error CANNM_APPL_DATA already defined
#endif
#define CANNM_APPL_DATA

#if (defined CANNM_APPL_CONST)
#error CANNM_APPL_CONST already defined
#endif
#define CANNM_APPL_CONST

#if (defined CANNM_APPL_CODE)
#error CANNM_APPL_CODE already defined
#endif
#define CANNM_APPL_CODE

#if (defined CANNM_VAR_NOINIT)
#error CANNM_VAR_NOINIT already defined
#endif
#define CANNM_VAR_NOINIT

#if (defined CANNM_VAR_POWER_ON_INIT)
#error CANNM_VAR_POWER_ON_INIT already defined
#endif
#define CANNM_VAR_POWER_ON_INIT

#if (defined CANNM_VAR_FAST)
#error CANNM_VAR_FAST already defined
#endif
#define CANNM_VAR_FAST

#if (defined CANNM_VAR)
#error CANNM_VAR already defined
#endif
#define CANNM_VAR

#if (defined CANSM_CODE)
#error CANSM_CODE already defined
#endif
#define CANSM_CODE

#if (defined CANSM_CONST)
#error CANSM_CONST already defined
#endif
#define CANSM_CONST

#if (defined CANSM_APPL_DATA)
#error CANSM_APPL_DATA already defined
#endif
#define CANSM_APPL_DATA

#if (defined CANSM_APPL_CONST)
#error CANSM_APPL_CONST already defined
#endif
#define CANSM_APPL_CONST

#if (defined CANSM_APPL_CODE)
#error CANSM_APPL_CODE already defined
#endif
#define CANSM_APPL_CODE

#if (defined CANSM_VAR_NOINIT)
#error CANSM_VAR_NOINIT already defined
#endif
#define CANSM_VAR_NOINIT

#if (defined CANSM_VAR_POWER_ON_INIT)
#error CANSM_VAR_POWER_ON_INIT already defined
#endif
#define CANSM_VAR_POWER_ON_INIT

#if (defined CANSM_VAR_FAST)
#error CANSM_VAR_FAST already defined
#endif
#define CANSM_VAR_FAST

#if (defined CANSM_VAR)
#error CANSM_VAR already defined
#endif
#define CANSM_VAR

#if (defined CANTP_CODE)
#error CANTP_CODE already defined
#endif
#define CANTP_CODE

#if (defined CANTP_CONST)
#error CANTP_CONST already defined
#endif
#define CANTP_CONST

#if (defined CANTP_APPL_DATA)
#error CANTP_APPL_DATA already defined
#endif
#define CANTP_APPL_DATA

#if (defined CANTP_APPL_CONST)
#error CANTP_APPL_CONST already defined
#endif
#define CANTP_APPL_CONST

#if (defined CANTP_APPL_CODE)
#error CANTP_APPL_CODE already defined
#endif
#define CANTP_APPL_CODE

#if (defined CANTP_VAR_NOINIT)
#error CANTP_VAR_NOINIT already defined
#endif
#define CANTP_VAR_NOINIT

#if (defined CANTP_VAR_POWER_ON_INIT)
#error CANTP_VAR_POWER_ON_INIT already defined
#endif
#define CANTP_VAR_POWER_ON_INIT

#if (defined CANTP_VAR_FAST)
#error CANTP_VAR_FAST already defined
#endif
#define CANTP_VAR_FAST

#if (defined CANTP_VAR)
#error CANTP_VAR already defined
#endif
#define CANTP_VAR

#if (defined CANTP_ENTRY_JUMP_TABLE)
#error CANTP_ENTRY_JUMP_TABLE already defined
#endif
#define CANTP_ENTRY_JUMP_TABLE

#if (defined CANTP_EXIT_JUMP_TABLE)
#error CANTP_EXIT_JUMP_TABLE already defined
#endif
#define CANTP_EXIT_JUMP_TABLE

#if (defined CANTRCV_CODE)
#error CANTRCV_CODE already defined
#endif
#define CANTRCV_CODE

#if (defined CANTRCV_CONST)
#error CANTRCV_CONST already defined
#endif
#define CANTRCV_CONST

#if (defined CANTRCV_APPL_DATA)
#error CANTRCV_APPL_DATA already defined
#endif
#define CANTRCV_APPL_DATA

#if (defined CANTRCV_APPL_CONST)
#error CANTRCV_APPL_CONST already defined
#endif
#define CANTRCV_APPL_CONST

#if (defined CANTRCV_APPL_CODE)
#error CANTRCV_APPL_CODE already defined
#endif
#define CANTRCV_APPL_CODE

#if (defined CANTRCV_VAR_NOINIT)
#error CANTRCV_VAR_NOINIT already defined
#endif
#define CANTRCV_VAR_NOINIT

#if (defined CANTRCV_VAR_POWER_ON_INIT)
#error CANTRCV_VAR_POWER_ON_INIT already defined
#endif
#define CANTRCV_VAR_POWER_ON_INIT

#if (defined CANTRCV_VAR_FAST)
#error CANTRCV_VAR_FAST already defined
#endif
#define CANTRCV_VAR_FAST

#if (defined CANTRCV_VAR)
#error CANTRCV_VAR already defined
#endif
#define CANTRCV_VAR

#if (defined COM_CODE)
#error COM_CODE already defined
#endif
#define COM_CODE

#if (defined COM_CONST)
#error COM_CONST already defined
#endif
#define COM_CONST

#if (defined COM_APPL_DATA)
#error COM_APPL_DATA already defined
#endif
#define COM_APPL_DATA

#if (defined COM_APPL_CONST)
#error COM_APPL_CONST already defined
#endif
#define COM_APPL_CONST

#if (defined COM_APPL_CODE)
#error COM_APPL_CODE already defined
#endif
#define COM_APPL_CODE

#if (defined COM_VAR_NOINIT)
#error COM_VAR_NOINIT already defined
#endif
#define COM_VAR_NOINIT

#if (defined COM_VAR_POWER_ON_INIT)
#error COM_VAR_POWER_ON_INIT already defined
#endif
#define COM_VAR_POWER_ON_INIT

#if (defined COM_VAR_FAST)
#error COM_VAR_FAST already defined
#endif
#define COM_VAR_FAST

#if (defined COM_VAR)
#error COM_VAR already defined
#endif
#define COM_VAR

#if (defined COM_RTE_CODE)
#error COM_RTE_CODE already defined
#endif
#define COM_RTE_CODE

#if (defined COMM_CODE)
#error COMM_CODE already defined
#endif
#define COMM_CODE

#if (defined COMM_CONST)
#error COMM_CONST already defined
#endif
#define COMM_CONST

#if (defined COMM_APPL_DATA)
#error COMM_APPL_DATA already defined
#endif
#define COMM_APPL_DATA

#if (defined COMM_APPL_CONST)
#error COMM_APPL_CONST already defined
#endif
#define COMM_APPL_CONST

#if (defined COMM_APPL_CODE)
#error COMM_APPL_CODE already defined
#endif
#define COMM_APPL_CODE

#if (defined COMM_VAR_NOINIT)
#error COMM_VAR_NOINIT already defined
#endif
#define COMM_VAR_NOINIT

#if (defined COMM_VAR_POWER_ON_INIT)
#error COMM_VAR_POWER_ON_INIT already defined
#endif
#define COMM_VAR_POWER_ON_INIT

#if (defined COMM_VAR_FAST)
#error COMM_VAR_FAST already defined
#endif
#define COMM_VAR_FAST

#if (defined COMM_VAR)
#error COMM_VAR already defined
#endif
#define COMM_VAR

#if (defined DCM_CODE)
#error DCM_CODE already defined
#endif
#define DCM_CODE

#if (defined DCM_CONST)
#error DCM_CONST already defined
#endif
#define DCM_CONST

#if (defined DCM_APPL_DATA)
#error DCM_APPL_DATA already defined
#endif
#define DCM_APPL_DATA

#if (defined DCM_APPL_CONST)
#error DCM_APPL_CONST already defined
#endif
#define DCM_APPL_CONST

#if (defined DCM_APPL_CODE)
#error DCM_APPL_CODE already defined
#endif
#define DCM_APPL_CODE

#if (defined DCM_VAR_NOINIT)
#error DCM_VAR_NOINIT already defined
#endif
#define DCM_VAR_NOINIT

#if (defined DCM_VAR_POWER_ON_INIT)
#error DCM_VAR_POWER_ON_INIT already defined
#endif
#define DCM_VAR_POWER_ON_INIT

#if (defined DCM_VAR_FAST)
#error DCM_VAR_FAST already defined
#endif
#define DCM_VAR_FAST

#if (defined DCM_VAR)
#error DCM_VAR already defined
#endif
#define DCM_VAR

#if (defined DEM_CODE)
#error DEM_CODE already defined
#endif
#define DEM_CODE

#if (defined DEM_CONST)
#error DEM_CONST already defined
#endif
#define DEM_CONST

#if (defined DEM_APPL_DATA)
#error DEM_APPL_DATA already defined
#endif
#define DEM_APPL_DATA

#if (defined DEM_APPL_CONST)
#error DEM_APPL_CONST already defined
#endif
#define DEM_APPL_CONST

#if (defined DEM_APPL_CODE)
#error DEM_APPL_CODE already defined
#endif
#define DEM_APPL_CODE

#if (defined DEM_VAR_NOINIT)
#error DEM_VAR_NOINIT already defined
#endif
#define DEM_VAR_NOINIT

#if (defined DEM_VAR_POWER_ON_INIT)
#error DEM_VAR_POWER_ON_INIT already defined
#endif
#define DEM_VAR_POWER_ON_INIT

#if (defined DEM_VAR_FAST)
#error DEM_VAR_FAST already defined
#endif
#define DEM_VAR_FAST

#if (defined DEM_VAR)
#error DEM_VAR already defined
#endif
#define DEM_VAR

#if (defined FIM_CODE)
#error FIM_CODE already defined
#endif
#define FIM_CODE

#if (defined FIM_CONST)
#error FIM_CONST already defined
#endif
#define FIM_CONST

#if (defined FIM_APPL_DATA)
#error FIM_APPL_DATA already defined
#endif
#define FIM_APPL_DATA

#if (defined FIM_APPL_CONST)
#error FIM_APPL_CONST already defined
#endif
#define FIM_APPL_CONST

#if (defined FIM_APPL_CODE)
#error FIM_APPL_CODE already defined
#endif
#define FIM_APPL_CODE

#if (defined FIM_VAR_NOINIT)
#error FIM_VAR_NOINIT already defined
#endif
#define FIM_VAR_NOINIT

#if (defined FIM_VAR_POWER_ON_INIT)
#error FIM_VAR_POWER_ON_INIT already defined
#endif
#define FIM_VAR_POWER_ON_INIT

#if (defined FIM_VAR_FAST)
#error FIM_VAR_FAST already defined
#endif
#define FIM_VAR_FAST

#if (defined FIM_VAR)
#error FIM_VAR already defined
#endif
#define FIM_VAR

#if (defined FR_CODE)
#error FR_CODE already defined
#endif
#define FR_CODE

#if (defined FR_CONST)
#error FR_CONST already defined
#endif
#define FR_CONST

#if (defined FR_APPL_DATA)
#error FR_APPL_DATA already defined
#endif
#define FR_APPL_DATA

#if (defined FR_APPL_CONST)
#error FR_APPL_CONST already defined
#endif
#define FR_APPL_CONST

#if (defined FR_APPL_CODE)
#error FR_APPL_CODE already defined
#endif
#define FR_APPL_CODE

#if (defined FR_VAR_NOINIT)
#error FR_VAR_NOINIT already defined
#endif
#define FR_VAR_NOINIT

#if (defined FR_VAR_POWER_ON_INIT)
#error FR_VAR_POWER_ON_INIT already defined
#endif
#define FR_VAR_POWER_ON_INIT

#if (defined FR_VAR_FAST)
#error FR_VAR_FAST already defined
#endif
#define FR_VAR_FAST

#if (defined FR_VAR)
#error FR_VAR already defined
#endif
#define FR_VAR

#if (defined FRIF_CODE)
#error FRIF_CODE already defined
#endif
#define FRIF_CODE

#if (defined FRIF_CONST)
#error FRIF_CONST already defined
#endif
#define FRIF_CONST

#if (defined FRIF_APPL_DATA)
#error FRIF_APPL_DATA already defined
#endif
#define FRIF_APPL_DATA

#if (defined FRIF_APPL_CONST)
#error FRIF_APPL_CONST already defined
#endif
#define FRIF_APPL_CONST

#if (defined FRIF_APPL_CODE)
#error FRIF_APPL_CODE already defined
#endif
#define FRIF_APPL_CODE

#if (defined FRIF_VAR_NOINIT)
#error FRIF_VAR_NOINIT already defined
#endif
#define FRIF_VAR_NOINIT

#if (defined FRIF_VAR_POWER_ON_INIT)
#error FRIF_VAR_POWER_ON_INIT already defined
#endif
#define FRIF_VAR_POWER_ON_INIT

#if (defined FRIF_VAR_FAST)
#error FRIF_VAR_FAST already defined
#endif
#define FRIF_VAR_FAST

#if (defined FRIF_VAR)
#error FRIF_VAR already defined
#endif
#define FRIF_VAR

#if (defined FRNM_CODE)
#error FRNM_CODE already defined
#endif
#define FRNM_CODE

#if (defined FRNM_CONST)
#error FRNM_CONST already defined
#endif
#define FRNM_CONST

#if (defined FRNM_APPL_DATA)
#error FRNM_APPL_DATA already defined
#endif
#define FRNM_APPL_DATA

#if (defined FRNM_APPL_CONST)
#error FRNM_APPL_CONST already defined
#endif
#define FRNM_APPL_CONST

#if (defined FRNM_APPL_CODE)
#error FRNM_APPL_CODE already defined
#endif
#define FRNM_APPL_CODE

#if (defined FRNM_VAR_NOINIT)
#error FRNM_VAR_NOINIT already defined
#endif
#define FRNM_VAR_NOINIT

#if (defined FRNM_VAR_POWER_ON_INIT)
#error FRNM_VAR_POWER_ON_INIT already defined
#endif
#define FRNM_VAR_POWER_ON_INIT

#if (defined FRNM_VAR_FAST)
#error FRNM_VAR_FAST already defined
#endif
#define FRNM_VAR_FAST

#if (defined FRNM_VAR)
#error FRNM_VAR already defined
#endif
#define FRNM_VAR

#if (defined FRSM_CODE)
#error FRSM_CODE already defined
#endif
#define FRSM_CODE

#if (defined FRSM_CONST)
#error FRSM_CONST already defined
#endif
#define FRSM_CONST

#if (defined FRSM_APPL_DATA)
#error FRSM_APPL_DATA already defined
#endif
#define FRSM_APPL_DATA

#if (defined FRSM_APPL_CONST)
#error FRSM_APPL_CONST already defined
#endif
#define FRSM_APPL_CONST

#if (defined FRSM_APPL_CODE)
#error FRSM_APPL_CODE already defined
#endif
#define FRSM_APPL_CODE

#if (defined FRSM_VAR_NOINIT)
#error FRSM_VAR_NOINIT already defined
#endif
#define FRSM_VAR_NOINIT

#if (defined FRSM_VAR_POWER_ON_INIT)
#error FRSM_VAR_POWER_ON_INIT already defined
#endif
#define FRSM_VAR_POWER_ON_INIT

#if (defined FRSM_VAR_FAST)
#error FRSM_VAR_FAST already defined
#endif
#define FRSM_VAR_FAST

#if (defined FRSM_VAR)
#error FRSM_VAR already defined
#endif
#define FRSM_VAR

#if (defined FRTP_CODE)
#error FRTP_CODE already defined
#endif
#define FRTP_CODE

#if (defined FRTP_CONST)
#error FRTP_CONST already defined
#endif
#define FRTP_CONST

#if (defined FRTP_APPL_DATA)
#error FRTP_APPL_DATA already defined
#endif
#define FRTP_APPL_DATA

#if (defined FRTP_APPL_CONST)
#error FRTP_APPL_CONST already defined
#endif
#define FRTP_APPL_CONST

#if (defined FRTP_APPL_CODE)
#error FRTP_APPL_CODE already defined
#endif
#define FRTP_APPL_CODE

#if (defined FRTP_VAR_NOINIT)
#error FRTP_VAR_NOINIT already defined
#endif
#define FRTP_VAR_NOINIT

#if (defined FRTP_VAR_POWER_ON_INIT)
#error FRTP_VAR_POWER_ON_INIT already defined
#endif
#define FRTP_VAR_POWER_ON_INIT

#if (defined FRTP_VAR_FAST)
#error FRTP_VAR_FAST already defined
#endif
#define FRTP_VAR_FAST

#if (defined FRTP_VAR)
#error FRTP_VAR already defined
#endif
#define FRTP_VAR

#if (defined FRTRCV_CODE)
#error FRTRCV_CODE already defined
#endif
#define FRTRCV_CODE

#if (defined FRTRCV_CONST)
#error FRTRCV_CONST already defined
#endif
#define FRTRCV_CONST

#if (defined FRTRCV_APPL_DATA)
#error FRTRCV_APPL_DATA already defined
#endif
#define FRTRCV_APPL_DATA

#if (defined FRTRCV_APPL_CONST)
#error FRTRCV_APPL_CONST already defined
#endif
#define FRTRCV_APPL_CONST

#if (defined FRTRCV_APPL_CODE)
#error FRTRCV_APPL_CODE already defined
#endif
#define FRTRCV_APPL_CODE

#if (defined FRTRCV_VAR_NOINIT)
#error FRTRCV_VAR_NOINIT already defined
#endif
#define FRTRCV_VAR_NOINIT

#if (defined FRTRCV_VAR_POWER_ON_INIT)
#error FRTRCV_VAR_POWER_ON_INIT already defined
#endif
#define FRTRCV_VAR_POWER_ON_INIT

#if (defined FRTRCV_VAR_FAST)
#error FRTRCV_VAR_FAST already defined
#endif
#define FRTRCV_VAR_FAST

#if (defined FRTRCV_VAR)
#error FRTRCV_VAR already defined
#endif
#define FRTRCV_VAR

#if (defined IPDUM_CODE)
#error IPDUM_CODE already defined
#endif
#define IPDUM_CODE

#if (defined IPDUM_CONST)
#error IPDUM_CONST already defined
#endif
#define IPDUM_CONST

#if (defined IPDUM_APPL_DATA)
#error IPDUM_APPL_DATA already defined
#endif
#define IPDUM_APPL_DATA

#if (defined IPDUM_APPL_CONST)
#error IPDUM_APPL_CONST already defined
#endif
#define IPDUM_APPL_CONST

#if (defined IPDUM_APPL_CODE)
#error IPDUM_APPL_CODE already defined
#endif
#define IPDUM_APPL_CODE

#if (defined IPDUM_VAR_NOINIT)
#error IPDUM_VAR_NOINIT already defined
#endif
#define IPDUM_VAR_NOINIT

#if (defined IPDUM_VAR_POWER_ON_INIT)
#error IPDUM_VAR_POWER_ON_INIT already defined
#endif
#define IPDUM_VAR_POWER_ON_INIT

#if (defined IPDUM_VAR_FAST)
#error IPDUM_VAR_FAST already defined
#endif
#define IPDUM_VAR_FAST

#if (defined IPDUM_VAR)
#error IPDUM_VAR already defined
#endif
#define IPDUM_VAR

#if (defined LIN_CODE)
#error LIN_CODE already defined
#endif
#define LIN_CODE

#if (defined LIN_CONST)
#error LIN_CONST already defined
#endif
#define LIN_CONST

#if (defined LIN_APPL_DATA)
#error LIN_APPL_DATA already defined
#endif
#define LIN_APPL_DATA

#if (defined LIN_APPL_CONST)
#error LIN_APPL_CONST already defined
#endif
#define LIN_APPL_CONST

#if (defined LIN_APPL_CODE)
#error LIN_APPL_CODE already defined
#endif
#define LIN_APPL_CODE

#if (defined LIN_VAR_NOINIT)
#error LIN_VAR_NOINIT already defined
#endif
#define LIN_VAR_NOINIT

#if (defined LIN_VAR_POWER_ON_INIT)
#error LIN_VAR_POWER_ON_INIT already defined
#endif
#define LIN_VAR_POWER_ON_INIT

#if (defined LIN_VAR_FAST)
#error LIN_VAR_FAST already defined
#endif
#define LIN_VAR_FAST

#if (defined LIN_VAR)
#error LIN_VAR already defined
#endif
#define LIN_VAR

#if (defined LINIF_CODE)
#error LINIF_CODE already defined
#endif
#define LINIF_CODE

#if (defined LINIF_CONST)
#error LINIF_CONST already defined
#endif
#define LINIF_CONST

#if (defined LINIF_APPL_DATA)
#error LINIF_APPL_DATA already defined
#endif
#define LINIF_APPL_DATA

#if (defined LINIF_APPL_CONST)
#error LINIF_APPL_CONST already defined
#endif
#define LINIF_APPL_CONST

#if (defined LINIF_APPL_CODE)
#error LINIF_APPL_CODE already defined
#endif
#define LINIF_APPL_CODE

#if (defined LINIF_VAR_NOINIT)
#error LINIF_VAR_NOINIT already defined
#endif
#define LINIF_VAR_NOINIT

#if (defined LINIF_VAR_POWER_ON_INIT)
#error LINIF_VAR_POWER_ON_INIT already defined
#endif
#define LINIF_VAR_POWER_ON_INIT

#if (defined LINIF_VAR_FAST)
#error LINIF_VAR_FAST already defined
#endif
#define LINIF_VAR_FAST

#if (defined LINIF_VAR)
#error LINIF_VAR already defined
#endif
#define LINIF_VAR

#if (defined LINSM_CODE)
#error LINSM_CODE already defined
#endif
#define LINSM_CODE

#if (defined LINSM_CONST)
#error LINSM_CONST already defined
#endif
#define LINSM_CONST

#if (defined LINSM_APPL_DATA)
#error LINSM_APPL_DATA already defined
#endif
#define LINSM_APPL_DATA

#if (defined LINSM_APPL_CONST)
#error LINSM_APPL_CONST already defined
#endif
#define LINSM_APPL_CONST

#if (defined LINSM_APPL_CODE)
#error LINSM_APPL_CODE already defined
#endif
#define LINSM_APPL_CODE

#if (defined LINSM_VAR_NOINIT)
#error LINSM_VAR_NOINIT already defined
#endif
#define LINSM_VAR_NOINIT

#if (defined LINSM_VAR_POWER_ON_INIT)
#error LINSM_VAR_POWER_ON_INIT already defined
#endif
#define LINSM_VAR_POWER_ON_INIT

#if (defined LINSM_VAR_FAST)
#error LINSM_VAR_FAST already defined
#endif
#define LINSM_VAR_FAST

#if (defined LINSM_VAR)
#error LINSM_VAR already defined
#endif
#define LINSM_VAR

#if (defined NM_CODE)
#error NM_CODE already defined
#endif
#define NM_CODE

#if (defined NM_CONST)
#error NM_CONST already defined
#endif
#define NM_CONST

#if (defined NM_APPL_DATA)
#error NM_APPL_DATA already defined
#endif
#define NM_APPL_DATA

#if (defined NM_APPL_CONST)
#error NM_APPL_CONST already defined
#endif
#define NM_APPL_CONST

#if (defined NM_APPL_CODE)
#error NM_APPL_CODE already defined
#endif
#define NM_APPL_CODE

#if (defined NM_VAR_NOINIT)
#error NM_VAR_NOINIT already defined
#endif
#define NM_VAR_NOINIT

#if (defined NM_VAR_POWER_ON_INIT)
#error NM_VAR_POWER_ON_INIT already defined
#endif
#define NM_VAR_POWER_ON_INIT

#if (defined NM_VAR_FAST)
#error NM_VAR_FAST already defined
#endif
#define NM_VAR_FAST

#if (defined NM_VAR)
#error NM_VAR already defined
#endif
#define NM_VAR

#if (defined PDUR_CODE)
#error PDUR_CODE already defined
#endif
#define PDUR_CODE

#if (defined PDUR_CONST)
#error PDUR_CONST already defined
#endif
#define PDUR_CONST

#if (defined PDUR_APPL_DATA)
#error PDUR_APPL_DATA already defined
#endif
#define PDUR_APPL_DATA

#if (defined PDUR_APPL_CONST)
#error PDUR_APPL_CONST already defined
#endif
#define PDUR_APPL_CONST

#if (defined PDUR_APPL_CODE)
#error PDUR_APPL_CODE already defined
#endif
#define PDUR_APPL_CODE

#if (defined PDUR_VAR_NOINIT)
#error PDUR_VAR_NOINIT already defined
#endif
#define PDUR_VAR_NOINIT

#if (defined PDUR_VAR_POWER_ON_INIT)
#error PDUR_VAR_POWER_ON_INIT already defined
#endif
#define PDUR_VAR_POWER_ON_INIT

#if (defined PDUR_VAR_FAST)
#error PDUR_VAR_FAST already defined
#endif
#define PDUR_VAR_FAST

#if (defined PDUR_VAR)
#error PDUR_VAR already defined
#endif
#define PDUR_VAR

#endif  /* COMPILER_CFG_H */
