/*
 *------------------------------------------------------------
 * Project:	cagOS
 * Goal:
 * Copyright (c) 2013, 2014 CAG Systems, Inc.
 *------------------------------------------------------------
 *
 *    @@@@     @@@      @@@@@       ####      ######
 *  @@       @@  @@    @@         ##    ##   ##
 * @@       @@    @@  @@   @@@@  ##      ## ######
 * @@      @@@@@@@@@@ @@    @@    ##    ##      ##
 *  @@@@@ @@@      @@@  @@@@@@      ####  #######
 *
 * The right to copy, distribute, modify or otherwise make use
 * of this software may be licensed only pursuant to the terms
 * of an applicable CAG license agreement.
 *
 * 1 tab == 4 spaces!
 *------------------------------------------------------------
 * modification history
 * --------------------
 * 03jun15,Jeff created
 *
 * DESCRIPTION
 * This file contains
 */

#ifndef   OS_H
#define   OS_H

#include "sysCpu.h"
#include "sysDef.h"
#include "sysOsConf.h"
#include "sysOsType.h"
#include "sysCore.h"

/*
************************************************************************************************************************
*                                               uC/OS-III VERSION NUMBER
************************************************************************************************************************
*/

#define  OS_VERSION  30404u                       /* Version of uC/OS-III (Vx.yy.zz mult. by 10000)                   */

/*
************************************************************************************************************************
*                                                 INCLUDE HEADER FILES
************************************************************************************************************************
*/

#define  OS_TASK_SW()           OSCtxSw()
#define  OS_TASK_SW_SYNC()      __asm__ __volatile__ ("sync" : : : "memory")

#if      OS_CFG_TS_EN == 1u
#define  OS_TS_GET()               (CPU_TS)getTblms()
#else
#define  OS_TS_GET()               (CPU_TS)0u
#endif

/*
************************************************************************************************************************
*                                               CRITICAL SECTION HANDLING
************************************************************************************************************************
*/

#define  OS_SCHED_LOCK_TIME_MEAS_START()

#define  OS_SCHED_LOCK_TIME_MEAS_STOP()

#define  OS_CRITICAL_ENTER()                    CPU_CRITICAL_ENTER()

#define  OS_CRITICAL_ENTER_CPU_EXIT()

#define  OS_CRITICAL_EXIT()                     CPU_CRITICAL_EXIT()

#define  OS_CRITICAL_EXIT_NO_SCHED()            CPU_CRITICAL_EXIT()

/*
************************************************************************************************************************
*                                                     MISCELLANEOUS
************************************************************************************************************************
*/

#define  OS_EXT

#define  OS_PRIO_TBL_SIZE          ((OS_CFG_PRIO_MAX - 1u) / (DEF_INT_CPU_NBR_BITS) + 1u)

#define  OS_MSG_EN                 (((OS_CFG_TASK_Q_EN > 0u) || (OS_CFG_Q_EN > 0u)) ? 1u : 0u)

#define  OS_OBJ_TYPE_REQ           1u

/*
************************************************************************************************************************
************************************************************************************************************************
*                                                   # D E F I N E S
************************************************************************************************************************
************************************************************************************************************************
*/

/*
========================================================================================================================
*                                                      TASK STATUS
========================================================================================================================
*/

#define  OS_STATE_OS_STOPPED                    (OS_STATE)(0u)
#define  OS_STATE_OS_RUNNING                    (OS_STATE)(1u)

#define  OS_STATE_NOT_RDY                    (CPU_BOOLEAN)(0u)
#define  OS_STATE_RDY                        (CPU_BOOLEAN)(1u)


                                                                /* ------------------- TASK STATES ------------------ */
#define  OS_TASK_STATE_BIT_DLY               (OS_STATE)(0x01u)  /*   /-------- SUSPENDED bit                          */
                                                                /*   |                                                */
#define  OS_TASK_STATE_BIT_PEND              (OS_STATE)(0x02u)  /*   | /-----  PEND      bit                          */
                                                                /*   | |                                              */
#define  OS_TASK_STATE_BIT_SUSPENDED         (OS_STATE)(0x04u)  /*   | | /---  Delayed/Timeout bit                    */
                                                                /*   | | |                                            */
                                                                /*   V V V                                            */

#define  OS_TASK_STATE_RDY                    (OS_STATE)(  0u)  /*   0 0 0     Ready                                  */
#define  OS_TASK_STATE_DLY                    (OS_STATE)(  1u)  /*   0 0 1     Delayed or Timeout                     */
#define  OS_TASK_STATE_PEND                   (OS_STATE)(  2u)  /*   0 1 0     Pend                                   */
#define  OS_TASK_STATE_PEND_TIMEOUT           (OS_STATE)(  3u)  /*   0 1 1     Pend + Timeout                         */
#define  OS_TASK_STATE_SUSPENDED              (OS_STATE)(  4u)  /*   1 0 0     Suspended                              */
#define  OS_TASK_STATE_DLY_SUSPENDED          (OS_STATE)(  5u)  /*   1 0 1     Suspended + Delayed or Timeout         */
#define  OS_TASK_STATE_PEND_SUSPENDED         (OS_STATE)(  6u)  /*   1 1 0     Suspended + Pend                       */
#define  OS_TASK_STATE_PEND_TIMEOUT_SUSPENDED (OS_STATE)(  7u)  /*   1 1 1     Suspended + Pend + Timeout             */
#define  OS_TASK_STATE_DEL                    (OS_STATE)(255u)

                                                                /* ----------------- PENDING ON ... ----------------- */
#define  OS_TASK_PEND_ON_NOTHING              (OS_STATE)(  0u)  /* Pending on nothing                                 */
#define  OS_TASK_PEND_ON_FLAG                 (OS_STATE)(  1u)  /* Pending on event flag group                        */
#define  OS_TASK_PEND_ON_TASK_Q               (OS_STATE)(  2u)  /* Pending on message to be sent to task              */
#define  OS_TASK_PEND_ON_MULTI                (OS_STATE)(  3u)  /* Pending on multiple semaphores and/or queues       */
#define  OS_TASK_PEND_ON_MUTEX                (OS_STATE)(  4u)  /* Pending on mutual exclusion semaphore              */
#define  OS_TASK_PEND_ON_Q                    (OS_STATE)(  5u)  /* Pending on queue                                   */
#define  OS_TASK_PEND_ON_SEM                  (OS_STATE)(  6u)  /* Pending on semaphore                               */
#define  OS_TASK_PEND_ON_TASK_SEM             (OS_STATE)(  7u)  /* Pending on signal  to be sent to task              */

/*
------------------------------------------------------------------------------------------------------------------------
*                                                    TASK PEND STATUS
*                                      (Status codes for OS_TCBs field .PendStatus)
------------------------------------------------------------------------------------------------------------------------
*/

#define  OS_STATUS_PEND_OK                   (OS_STATUS)(  0u)  /* Pending status OK, !pending, or pending complete   */
#define  OS_STATUS_PEND_ABORT                (OS_STATUS)(  1u)  /* Pending aborted                                    */
#define  OS_STATUS_PEND_DEL                  (OS_STATUS)(  2u)  /* Pending object deleted                             */
#define  OS_STATUS_PEND_TIMEOUT              (OS_STATUS)(  3u)  /* Pending timed out                                  */

/*
========================================================================================================================
*                                                   OS OBJECT TYPES
*
* Note(s) : (1) OS_OBJ_TYPE_&&& #define values specifically chosen as ASCII representations of the kernel
*               object types.  Memory displays of kernel objects will display the kernel object TYPEs with
*               their chosen ASCII names.
========================================================================================================================
*/

#define  OS_OBJ_TYPE_NONE                    (OS_OBJ_TYPE)CPU_TYPE_CREATE('N', 'O', 'N', 'E')
#define  OS_OBJ_TYPE_FLAG                    (OS_OBJ_TYPE)CPU_TYPE_CREATE('F', 'L', 'A', 'G')
#define  OS_OBJ_TYPE_MEM                     (OS_OBJ_TYPE)CPU_TYPE_CREATE('M', 'E', 'M', ' ')
#define  OS_OBJ_TYPE_MUTEX                   (OS_OBJ_TYPE)CPU_TYPE_CREATE('M', 'U', 'T', 'X')
#define  OS_OBJ_TYPE_Q                       (OS_OBJ_TYPE)CPU_TYPE_CREATE('Q', 'U', 'E', 'U')
#define  OS_OBJ_TYPE_SEM                     (OS_OBJ_TYPE)CPU_TYPE_CREATE('S', 'E', 'M', 'A')
#define  OS_OBJ_TYPE_TASK_MSG                (OS_OBJ_TYPE)CPU_TYPE_CREATE('T', 'M', 'S', 'G')
#define  OS_OBJ_TYPE_TASK_RESUME             (OS_OBJ_TYPE)CPU_TYPE_CREATE('T', 'R', 'E', 'S')
#define  OS_OBJ_TYPE_TASK_SIGNAL             (OS_OBJ_TYPE)CPU_TYPE_CREATE('T', 'S', 'I', 'G')
#define  OS_OBJ_TYPE_TASK_SUSPEND            (OS_OBJ_TYPE)CPU_TYPE_CREATE('T', 'S', 'U', 'S')
#define  OS_OBJ_TYPE_TICK                    (OS_OBJ_TYPE)CPU_TYPE_CREATE('T', 'I', 'C', 'K')
#define  OS_OBJ_TYPE_TMR                     (OS_OBJ_TYPE)CPU_TYPE_CREATE('T', 'M', 'R', ' ')

/*
========================================================================================================================
*                                           Possible values for 'opt' argument
========================================================================================================================
*/

#define  OS_OPT_NONE                         (OS_OPT)(0x0000u)

/*
------------------------------------------------------------------------------------------------------------------------
*                                                    DELETE OPTIONS
------------------------------------------------------------------------------------------------------------------------
*/

#define  OS_OPT_DEL_NO_PEND                  (OS_OPT)(0x0000u)
#define  OS_OPT_DEL_ALWAYS                   (OS_OPT)(0x0001u)

/*
------------------------------------------------------------------------------------------------------------------------
*                                                     PEND OPTIONS
------------------------------------------------------------------------------------------------------------------------
*/

#define  OS_OPT_PEND_FLAG_MASK               (OS_OPT)(0x000Fu)
#define  OS_OPT_PEND_FLAG_CLR_ALL            (OS_OPT)(0x0001u)  /* Wait for ALL    the bits specified to be CLR       */
#define  OS_OPT_PEND_FLAG_CLR_AND            (OS_OPT)(0x0001u)

#define  OS_OPT_PEND_FLAG_CLR_ANY            (OS_OPT)(0x0002u)  /* Wait for ANY of the bits specified to be CLR       */
#define  OS_OPT_PEND_FLAG_CLR_OR             (OS_OPT)(0x0002u)

#define  OS_OPT_PEND_FLAG_SET_ALL            (OS_OPT)(0x0004u)  /* Wait for ALL    the bits specified to be SET       */
#define  OS_OPT_PEND_FLAG_SET_AND            (OS_OPT)(0x0004u)

#define  OS_OPT_PEND_FLAG_SET_ANY            (OS_OPT)(0x0008u)  /* Wait for ANY of the bits specified to be SET       */
#define  OS_OPT_PEND_FLAG_SET_OR             (OS_OPT)(0x0008u)

#define  OS_OPT_PEND_FLAG_CONSUME            (OS_OPT)(0x0100u)  /* Consume the flags if condition(s) satisfied        */


#define  OS_OPT_PEND_BLOCKING                (OS_OPT)(0x0000u)
#define  OS_OPT_PEND_NON_BLOCKING            (OS_OPT)(0x8000u)

/*
------------------------------------------------------------------------------------------------------------------------
*                                                  PEND ABORT OPTIONS
------------------------------------------------------------------------------------------------------------------------
*/

#define  OS_OPT_PEND_ABORT_1                 (OS_OPT)(0x0000u)  /* Pend abort a single waiting task                   */
#define  OS_OPT_PEND_ABORT_ALL               (OS_OPT)(0x0100u)  /* Pend abort ALL tasks waiting                       */

/*
------------------------------------------------------------------------------------------------------------------------
*                                                     POST OPTIONS
------------------------------------------------------------------------------------------------------------------------
*/


#define  OS_OPT_POST_NONE                    (OS_OPT)(0x0000u)

#define  OS_OPT_POST_FLAG_SET                (OS_OPT)(0x0000u)
#define  OS_OPT_POST_FLAG_CLR                (OS_OPT)(0x0001u)

#define  OS_OPT_POST_FIFO                    (OS_OPT)(0x0000u)  /* Default is to post FIFO                            */
#define  OS_OPT_POST_LIFO                    (OS_OPT)(0x0010u)  /* Post to highest priority task waiting              */
#define  OS_OPT_POST_1                       (OS_OPT)(0x0000u)  /* Post message to highest priority task waiting      */
#define  OS_OPT_POST_ALL                     (OS_OPT)(0x0200u)  /* Broadcast message to ALL tasks waiting             */

#define  OS_OPT_POST_NO_SCHED                (OS_OPT)(0x8000u)  /* Do not call the scheduler if this is selected      */

/*
------------------------------------------------------------------------------------------------------------------------
*                                                     TASK OPTIONS
------------------------------------------------------------------------------------------------------------------------
*/

#define  OS_OPT_TASK_NONE                    (OS_OPT)(0x0000u)  /* No option selected                                 */
#define  OS_OPT_TASK_STK_CHK                 (OS_OPT)(0x0001u)  /* Enable stack checking for the task                 */
#define  OS_OPT_TASK_STK_CLR                 (OS_OPT)(0x0002u)  /* Clear the stack when the task is create            */
#define  OS_OPT_TASK_SAVE_FP                 (OS_OPT)(0x0004u)  /* Save the contents of any floating-point registers  */
#define  OS_OPT_TASK_NO_TLS                  (OS_OPT)(0x0008u)  /* Specifies the task DOES NOT require TLS support    */

/*
------------------------------------------------------------------------------------------------------------------------
*                                                     TIME OPTIONS
------------------------------------------------------------------------------------------------------------------------
*/

#define  OS_OPT_TIME_DLY                             DEF_BIT_NONE
#define  OS_OPT_TIME_TIMEOUT                ((OS_OPT)DEF_BIT_01)
#define  OS_OPT_TIME_MATCH                  ((OS_OPT)DEF_BIT_02)
#define  OS_OPT_TIME_PERIODIC               ((OS_OPT)DEF_BIT_03)

#define  OS_OPT_TIME_HMSM_STRICT            ((OS_OPT)DEF_BIT_NONE)
#define  OS_OPT_TIME_HMSM_NON_STRICT        ((OS_OPT)DEF_BIT_04)

#define  OS_OPT_TIME_MASK                   ((OS_OPT)(OS_OPT_TIME_DLY      | \
                                                      OS_OPT_TIME_TIMEOUT  | \
                                                      OS_OPT_TIME_PERIODIC | \
                                                      OS_OPT_TIME_MATCH))

#define  OS_OPT_TIME_OPTS_MASK                       (OS_OPT_TIME_DLY            | \
                                                      OS_OPT_TIME_TIMEOUT        | \
                                                      OS_OPT_TIME_PERIODIC       | \
                                                      OS_OPT_TIME_MATCH          | \
                                                      OS_OPT_TIME_HMSM_NON_STRICT)

/*
------------------------------------------------------------------------------------------------------------------------
*                                                    TIMER OPTIONS
------------------------------------------------------------------------------------------------------------------------
*/

#define  OS_OPT_TMR_NONE                          (OS_OPT)(0u)  /* No option selected                                 */

#define  OS_OPT_TMR_ONE_SHOT                      (OS_OPT)(1u)  /* Timer will not auto restart when it expires        */
#define  OS_OPT_TMR_PERIODIC                      (OS_OPT)(2u)  /* Timer will     auto restart when it expires        */

#define  OS_OPT_TMR_CALLBACK                      (OS_OPT)(3u)  /* OSTmrStop() option to call 'callback' w/ timer arg */
#define  OS_OPT_TMR_CALLBACK_ARG                  (OS_OPT)(4u)  /* OSTmrStop() option to call 'callback' w/ new   arg */

/*
------------------------------------------------------------------------------------------------------------------------
*                                                     TIMER STATES
------------------------------------------------------------------------------------------------------------------------
*/

#define  OS_TMR_STATE_UNUSED                    (OS_STATE)(0u)
#define  OS_TMR_STATE_STOPPED                   (OS_STATE)(1u)
#define  OS_TMR_STATE_RUNNING                   (OS_STATE)(2u)
#define  OS_TMR_STATE_COMPLETED                 (OS_STATE)(3u)

/*
------------------------------------------------------------------------------------------------------------------------
*                                                       PRIORITY
------------------------------------------------------------------------------------------------------------------------
*/
                                                                    /* Dflt prio to init task TCB                     */
#define  OS_PRIO_INIT                       (OS_PRIO)(OS_CFG_PRIO_MAX)

/*
------------------------------------------------------------------------------------------------------------------------
*                                                 TIMER TICK THRESHOLDS
------------------------------------------------------------------------------------------------------------------------
*/
                                                                    /* Threshold to init previous tick time           */
#define  OS_TICK_TH_INIT                    (OS_TICK)(DEF_BIT       ((sizeof(OS_TICK) * DEF_OCTET_NBR_BITS) - 1u))

                                                                    /* Threshold to check if tick time already ready  */
#define  OS_TICK_TH_RDY                     (OS_TICK)(DEF_BIT_FIELD(((sizeof(OS_TICK) * DEF_OCTET_NBR_BITS) / 2u), \
                                                                    ((sizeof(OS_TICK) * DEF_OCTET_NBR_BITS) / 2u)))


/*
************************************************************************************************************************
************************************************************************************************************************
*                                                E N U M E R A T I O N S
************************************************************************************************************************
************************************************************************************************************************
*/

/*
------------------------------------------------------------------------------------------------------------------------
*                                                      ERROR CODES
------------------------------------------------------------------------------------------------------------------------
*/

typedef  enum  os_err {
    OS_ERR_NONE                      =     0u,

    OS_ERR_A                         = 10000u,
    OS_ERR_ACCEPT_ISR                = 10001u,

    OS_ERR_B                         = 11000u,

    OS_ERR_C                         = 12000u,
    OS_ERR_CREATE_ISR                = 12001u,

    OS_ERR_D                         = 13000u,
    OS_ERR_DEL_ISR                   = 13001u,

    OS_ERR_E                         = 14000u,

    OS_ERR_F                         = 15000u,
    OS_ERR_FATAL_RETURN              = 15001u,

    OS_ERR_FLAG_GRP_DEPLETED         = 15101u,
    OS_ERR_FLAG_NOT_RDY              = 15102u,
    OS_ERR_FLAG_PEND_OPT             = 15103u,
    OS_ERR_FLUSH_ISR                 = 15104u,

    OS_ERR_G                         = 16000u,

    OS_ERR_H                         = 17000u,

    OS_ERR_I                         = 18000u,
    OS_ERR_ILLEGAL_CREATE_RUN_TIME   = 18001u,
    OS_ERR_INT_Q                     = 18002u,
    OS_ERR_INT_Q_FULL                = 18003u,
    OS_ERR_INT_Q_SIZE                = 18004u,
    OS_ERR_INT_Q_STK_INVALID         = 18005u,
    OS_ERR_INT_Q_STK_SIZE_INVALID    = 18006u,

    OS_ERR_J                         = 19000u,

    OS_ERR_K                         = 20000u,

    OS_ERR_L                         = 21000u,
    OS_ERR_LOCK_NESTING_OVF          = 21001u,

    OS_ERR_M                         = 22000u,

    OS_ERR_MEM_CREATE_ISR            = 22201u,
    OS_ERR_MEM_FULL                  = 22202u,
    OS_ERR_MEM_INVALID_P_ADDR        = 22203u,
    OS_ERR_MEM_INVALID_BLKS          = 22204u,
    OS_ERR_MEM_INVALID_PART          = 22205u,
    OS_ERR_MEM_INVALID_P_BLK         = 22206u,
    OS_ERR_MEM_INVALID_P_MEM         = 22207u,
    OS_ERR_MEM_INVALID_P_DATA        = 22208u,
    OS_ERR_MEM_INVALID_SIZE          = 22209u,
    OS_ERR_MEM_NO_FREE_BLKS          = 22210u,

    OS_ERR_MSG_POOL_EMPTY            = 22301u,
    OS_ERR_MSG_POOL_NULL_PTR         = 22302u,

    OS_ERR_MUTEX_NOT_OWNER           = 22401u,
    OS_ERR_MUTEX_OWNER               = 22402u,
    OS_ERR_MUTEX_NESTING             = 22403u,

    OS_ERR_N                         = 23000u,
    OS_ERR_NAME                      = 23001u,
    OS_ERR_NO_MORE_ID_AVAIL          = 23002u,

    OS_ERR_O                         = 24000u,
    OS_ERR_OBJ_CREATED               = 24001u,
    OS_ERR_OBJ_DEL                   = 24002u,
    OS_ERR_OBJ_PTR_NULL              = 24003u,
    OS_ERR_OBJ_TYPE                  = 24004u,

    OS_ERR_OPT_INVALID               = 24101u,

    OS_ERR_OS_NOT_RUNNING            = 24201u,
    OS_ERR_OS_RUNNING                = 24202u,

    OS_ERR_P                         = 25000u,
    OS_ERR_PEND_ABORT                = 25001u,
    OS_ERR_PEND_ABORT_ISR            = 25002u,
    OS_ERR_PEND_ABORT_NONE           = 25003u,
    OS_ERR_PEND_ABORT_SELF           = 25004u,
    OS_ERR_PEND_DEL                  = 25005u,
    OS_ERR_PEND_ISR                  = 25006u,
    OS_ERR_PEND_LOCKED               = 25007u,
    OS_ERR_PEND_WOULD_BLOCK          = 25008u,

    OS_ERR_POST_NULL_PTR             = 25101u,
    OS_ERR_POST_ISR                  = 25102u,

    OS_ERR_PRIO_EXIST                = 25201u,
    OS_ERR_PRIO                      = 25202u,
    OS_ERR_PRIO_INVALID              = 25203u,

    OS_ERR_PTR_INVALID               = 25301u,

    OS_ERR_Q                         = 26000u,
    OS_ERR_Q_FULL                    = 26001u,
    OS_ERR_Q_EMPTY                   = 26002u,
    OS_ERR_Q_MAX                     = 26003u,
    OS_ERR_Q_SIZE                    = 26004u,

    OS_ERR_R                         = 27000u,
    OS_ERR_REG_ID_INVALID            = 27001u,
    OS_ERR_ROUND_ROBIN_1             = 27002u,
    OS_ERR_ROUND_ROBIN_DISABLED      = 27003u,

    OS_ERR_S                         = 28000u,
    OS_ERR_SCHED_INVALID_TIME_SLICE  = 28001u,
    OS_ERR_SCHED_LOCK_ISR            = 28002u,
    OS_ERR_SCHED_LOCKED              = 28003u,
    OS_ERR_SCHED_NOT_LOCKED          = 28004u,
    OS_ERR_SCHED_UNLOCK_ISR          = 28005u,

    OS_ERR_SEM_OVF                   = 28101u,
    OS_ERR_SET_ISR                   = 28102u,

    OS_ERR_STAT_RESET_ISR            = 28201u,
    OS_ERR_STAT_PRIO_INVALID         = 28202u,
    OS_ERR_STAT_STK_INVALID          = 28203u,
    OS_ERR_STAT_STK_SIZE_INVALID     = 28204u,
    OS_ERR_STATE_INVALID             = 28205u,
    OS_ERR_STATUS_INVALID            = 28206u,
    OS_ERR_STK_INVALID               = 28207u,
    OS_ERR_STK_SIZE_INVALID          = 28208u,
    OS_ERR_STK_LIMIT_INVALID         = 28209u,

    OS_ERR_T                         = 29000u,
    OS_ERR_TASK_CHANGE_PRIO_ISR      = 29001u,
    OS_ERR_TASK_CREATE_ISR           = 29002u,
    OS_ERR_TASK_DEL                  = 29003u,
    OS_ERR_TASK_DEL_IDLE             = 29004u,
    OS_ERR_TASK_DEL_INVALID          = 29005u,
    OS_ERR_TASK_DEL_ISR              = 29006u,
    OS_ERR_TASK_INVALID              = 29007u,
    OS_ERR_TASK_NO_MORE_TCB          = 29008u,
    OS_ERR_TASK_NOT_DLY              = 29009u,
    OS_ERR_TASK_NOT_EXIST            = 29010u,
    OS_ERR_TASK_NOT_SUSPENDED        = 29011u,
    OS_ERR_TASK_OPT                  = 29012u,
    OS_ERR_TASK_RESUME_ISR           = 29013u,
    OS_ERR_TASK_RESUME_PRIO          = 29014u,
    OS_ERR_TASK_RESUME_SELF          = 29015u,
    OS_ERR_TASK_RUNNING              = 29016u,
    OS_ERR_TASK_STK_CHK_ISR          = 29017u,
    OS_ERR_TASK_SUSPENDED            = 29018u,
    OS_ERR_TASK_SUSPEND_IDLE         = 29019u,
    OS_ERR_TASK_SUSPEND_INT_HANDLER  = 29020u,
    OS_ERR_TASK_SUSPEND_ISR          = 29021u,
    OS_ERR_TASK_SUSPEND_PRIO         = 29022u,
    OS_ERR_TASK_WAITING              = 29023u,

    OS_ERR_TCB_INVALID               = 29101u,

    OS_ERR_TLS_ID_INVALID            = 29120u,
    OS_ERR_TLS_ISR                   = 29121u,
    OS_ERR_TLS_NO_MORE_AVAIL         = 29122u,
    OS_ERR_TLS_NOT_EN                = 29123u,
    OS_ERR_TLS_DESTRUCT_ASSIGNED     = 29124u,

    OS_ERR_TICK_PRIO_INVALID         = 29201u,
    OS_ERR_TICK_STK_INVALID          = 29202u,
    OS_ERR_TICK_STK_SIZE_INVALID     = 29203u,
    OS_ERR_TICK_WHEEL_SIZE           = 29204u,

    OS_ERR_TIME_DLY_ISR              = 29301u,
    OS_ERR_TIME_DLY_RESUME_ISR       = 29302u,
    OS_ERR_TIME_GET_ISR              = 29303u,
    OS_ERR_TIME_INVALID_HOURS        = 29304u,
    OS_ERR_TIME_INVALID_MINUTES      = 29305u,
    OS_ERR_TIME_INVALID_SECONDS      = 29306u,
    OS_ERR_TIME_INVALID_MILLISECONDS = 29307u,
    OS_ERR_TIME_NOT_DLY              = 29308u,
    OS_ERR_TIME_SET_ISR              = 29309u,
    OS_ERR_TIME_ZERO_DLY             = 29310u,

    OS_ERR_TIMEOUT                   = 29401u,

    OS_ERR_TMR_INACTIVE              = 29501u,
    OS_ERR_TMR_INVALID_DEST          = 29502u,
    OS_ERR_TMR_INVALID_DLY           = 29503u,
    OS_ERR_TMR_INVALID_PERIOD        = 29504u,
    OS_ERR_TMR_INVALID_STATE         = 29505u,
    OS_ERR_TMR_INVALID               = 29506u,
    OS_ERR_TMR_ISR                   = 29507u,
    OS_ERR_TMR_NO_CALLBACK           = 29508u,
    OS_ERR_TMR_NON_AVAIL             = 29509u,
    OS_ERR_TMR_PRIO_INVALID          = 29510u,
    OS_ERR_TMR_STK_INVALID           = 29511u,
    OS_ERR_TMR_STK_SIZE_INVALID      = 29512u,
    OS_ERR_TMR_STOPPED               = 29513u,

    OS_ERR_U                         = 30000u,

    OS_ERR_V                         = 31000u,

    OS_ERR_W                         = 32000u,

    OS_ERR_X                         = 33000u,

    OS_ERR_Y                         = 34000u,
    OS_ERR_YIELD_ISR                 = 34001u,

    OS_ERR_Z                         = 35000u
} OS_ERR;


/*
************************************************************************************************************************
************************************************************************************************************************
*                                                  D A T A   T Y P E S
************************************************************************************************************************
************************************************************************************************************************
*/

typedef  struct  os_mutex            OS_MUTEX;

typedef  struct  os_msg              OS_MSG;

typedef  struct  os_msg_pool         OS_MSG_POOL;

typedef  struct  os_msg_q            OS_MSG_Q;

typedef  struct  os_q                OS_Q;

typedef  struct  os_sem              OS_SEM;

typedef  void                      (*OS_TASK_PTR)(void *p_arg);

typedef  struct  os_tcb              OS_TCB;

typedef  struct  os_rdy_list         OS_RDY_LIST;

typedef  struct  os_tick_list        OS_TICK_LIST;

typedef  void                      (*OS_TMR_CALLBACK_PTR)(void *p_tmr, void *p_arg);
typedef  struct  os_tmr              OS_TMR;

typedef  struct  os_pend_data        OS_PEND_DATA;
typedef  struct  os_pend_list        OS_PEND_LIST;
typedef  struct  os_pend_obj         OS_PEND_OBJ;

#if OS_CFG_APP_HOOKS_EN > 0u
typedef  void                      (*OS_APP_HOOK_VOID)(void);
typedef  void                      (*OS_APP_HOOK_TCB)(OS_TCB *p_tcb);
#endif


/*
************************************************************************************************************************
************************************************************************************************************************
*                                          D A T A   S T R U C T U R E S
************************************************************************************************************************
************************************************************************************************************************
*/

/*
------------------------------------------------------------------------------------------------------------------------
*                                                    ISR POST DATA
------------------------------------------------------------------------------------------------------------------------
*/

/*
------------------------------------------------------------------------------------------------------------------------
*                                                      READY LIST
------------------------------------------------------------------------------------------------------------------------
*/

struct  os_rdy_list {
    OS_TCB              *HeadPtr;                           /* Pointer to task that will run at selected priority     */
    OS_TCB              *TailPtr;                           /* Pointer to last task          at selected priority     */
    OS_OBJ_QTY           NbrEntries;                        /* Number of entries             at selected priority     */
};


/*
------------------------------------------------------------------------------------------------------------------------
*                                                PEND DATA and PEND LIST
------------------------------------------------------------------------------------------------------------------------
*/

struct  os_pend_data {
    OS_PEND_DATA        *PrevPtr;
    OS_PEND_DATA        *NextPtr;
    OS_TCB              *TCBPtr;
    OS_PEND_OBJ         *PendObjPtr;
    OS_PEND_OBJ         *RdyObjPtr;
    void                *RdyMsgPtr;
    OS_MSG_SIZE          RdyMsgSize;
    CPU_TS               RdyTS;
};


struct  os_pend_list {
    OS_PEND_DATA        *HeadPtr;
    OS_PEND_DATA        *TailPtr;
    OS_OBJ_QTY           NbrEntries;
};


/*
------------------------------------------------------------------------------------------------------------------------
*                                                       PEND OBJ
*
* Note(s) : (1) The 'os_pend_obj' structure data type is a template/subset for specific kernel objects' data types:
*               'os_flag_grp', 'os_mutex', 'os_q', and 'os_sem'.  Each specific kernel object data type MUST define
*               ALL generic OS pend object parameters, synchronized in both the sequential order & data type of each
*               parameter.
*
*               Thus, ANY modification to the sequential order or data types of OS pend object parameters MUST be
*               appropriately synchronized between the generic OS pend object data type & ALL specific kernel objects'
*               data types.
------------------------------------------------------------------------------------------------------------------------
*/

struct  os_pend_obj {
#if OS_OBJ_TYPE_REQ > 0u
    OS_OBJ_TYPE          Type;
#endif
    OS_PEND_LIST         PendList;                          /* List of tasks pending on object                        */
};


/*
------------------------------------------------------------------------------------------------------------------------
*                                                     EVENT FLAGS
*
* Note(s) : See  PEND OBJ  Note #1'.
------------------------------------------------------------------------------------------------------------------------
*/


/*
------------------------------------------------------------------------------------------------------------------------
*                                                   MEMORY PARTITIONS
------------------------------------------------------------------------------------------------------------------------
*/


/*
------------------------------------------------------------------------------------------------------------------------
*                                                       MESSAGES
------------------------------------------------------------------------------------------------------------------------
*/

/*
------------------------------------------------------------------------------------------------------------------------
*                                                       MESSAGES
------------------------------------------------------------------------------------------------------------------------
*/

struct  os_msg {                                            /* MESSAGE CONTROL BLOCK                                  */
    OS_MSG              *NextPtr;                           /* Pointer to next message                                */
    void                *MsgPtr;                            /* Actual message                                         */
    OS_MSG_SIZE          MsgSize;                           /* Size of the message (in # bytes)                       */
    CPU_TS               MsgTS;                             /* Time stamp of when message was sent                    */
};

struct  os_msg_pool {                                       /* OS_MSG POOL                                            */
    OS_MSG              *NextPtr;                           /* Pointer to next message                                */
    OS_MSG_QTY           NbrFree;                           /* Number of messages available from this pool            */
    OS_MSG_QTY           NbrUsed;                           /* Current number of messages used                        */
};

struct  os_msg_q {                                          /* OS_MSG_Q                                               */
    OS_MSG              *InPtr;                             /* Pointer to next OS_MSG to be inserted  in   the queue  */
    OS_MSG              *OutPtr;                            /* Pointer to next OS_MSG to be extracted from the queue  */
    OS_MSG_QTY           NbrEntriesSize;                    /* Maximum allowable number of entries in the queue       */
    OS_MSG_QTY           NbrEntries;                        /* Current number of entries in the queue                 */
};

/*
------------------------------------------------------------------------------------------------------------------------
*                                              MUTUAL EXCLUSION SEMAPHORES
*
* Note(s) : See  PEND OBJ  Note #1'.
------------------------------------------------------------------------------------------------------------------------
*/

struct  os_mutex {                                          /* Mutual Exclusion Semaphore                             */
                                                            /* ------------------ GENERIC  MEMBERS ------------------ */
#if OS_OBJ_TYPE_REQ > 0u
    OS_OBJ_TYPE          Type;                              /* Should be set to OS_OBJ_TYPE_MUTEX                     */
#endif
    OS_PEND_LIST         PendList;                          /* List of tasks waiting on mutex                         */
                                                            /* ------------------ SPECIFIC MEMBERS ------------------ */
    OS_MUTEX            *MutexGrpNextPtr;
    OS_TCB              *OwnerTCBPtr;
    OS_NESTING_CTR       OwnerNestingCtr;                   /* Mutex is available when the counter is 0               */
    CPU_TS               TS;
};


/*
------------------------------------------------------------------------------------------------------------------------
*                                                    MESSAGE QUEUES
*
* Note(s) : See  PEND OBJ  Note #1'.
------------------------------------------------------------------------------------------------------------------------
*/

#if OS_CFG_Q_EN > 0u

void          OSQCreate                 (OS_Q                  *p_q,
                                         CPU_CHAR              *p_name,
                                         OS_MSG_QTY             max_qty,
                                         OS_ERR                *p_err);

#if OS_CFG_Q_DEL_EN > 0u
OS_OBJ_QTY    OSQDel                    (OS_Q                  *p_q,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);
#endif

#if OS_CFG_Q_FLUSH_EN > 0u
OS_MSG_QTY    OSQFlush                  (OS_Q                  *p_q,
                                         OS_ERR                *p_err);
#endif

void         *OSQPend                   (OS_Q                  *p_q,
                                         OS_TICK                timeout,
                                         OS_OPT                 opt,
                                         OS_MSG_SIZE           *p_msg_size,
                                         CPU_TS                *p_ts,
                                         OS_ERR                *p_err);

#if OS_CFG_Q_PEND_ABORT_EN > 0u
OS_OBJ_QTY    OSQPendAbort              (OS_Q                  *p_q,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);
#endif

void          OSQPost                   (OS_Q                  *p_q,
                                         void                  *p_void,
                                         OS_MSG_SIZE            msg_size,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);

/* ------------------------------------------------ INTERNAL FUNCTIONS ---------------------------------------------- */

void          OS_QClr                   (OS_Q                  *p_q);

#if OS_CFG_DBG_EN > 0u
void          OS_QDbgListAdd            (OS_Q                  *p_q);

void          OS_QDbgListRemove         (OS_Q                  *p_q);
#endif

void          OS_QInit                  (OS_ERR                *p_err);

void          OS_QPost                  (OS_Q                  *p_q,
                                         void                  *p_void,
                                         OS_MSG_SIZE            msg_size,
                                         OS_OPT                 opt,
                                         CPU_TS                 ts,
                                         OS_ERR                *p_err);
#endif

/*
------------------------------------------------------------------------------------------------------------------------
*                                                    MESSAGE QUEUES
*
* Note(s) : See  PEND OBJ  Note #1'.
------------------------------------------------------------------------------------------------------------------------
*/

struct  os_q {                                              /* Message Queue                                          */
                                                            /* ------------------ GENERIC  MEMBERS ------------------ */
#if OS_OBJ_TYPE_REQ > 0u
    OS_OBJ_TYPE          Type;                              /* Should be set to OS_OBJ_TYPE_Q                         */
#endif
    OS_PEND_LIST         PendList;                          /* List of tasks waiting on message queue                 */
                                                            /* ------------------ SPECIFIC MEMBERS ------------------ */
    OS_MSG_Q             MsgQ;                              /* List of messages                                       */
};

/*
------------------------------------------------------------------------------------------------------------------------
*                                                      SEMAPHORES
*
* Note(s) : See  PEND OBJ  Note #1'.
------------------------------------------------------------------------------------------------------------------------
*/

struct  os_sem {                                            /* Semaphore                                              */
                                                            /* ------------------ GENERIC  MEMBERS ------------------ */
#if OS_OBJ_TYPE_REQ > 0u
    OS_OBJ_TYPE          Type;                              /* Should be set to OS_OBJ_TYPE_SEM                       */
#endif
    OS_PEND_LIST         PendList;                          /* List of tasks waiting on semaphore                     */
                                                            /* ------------------ SPECIFIC MEMBERS ------------------ */
    OS_SEM_CTR           Ctr;
    CPU_TS               TS;
};


/*
------------------------------------------------------------------------------------------------------------------------
*                                                  TASK CONTROL BLOCK
------------------------------------------------------------------------------------------------------------------------
*/

struct os_tcb {
    CPU_STK             *StkPtr;                            /* Pointer to current top of stack                        */

    void                *ExtPtr;                            /* Pointer to user definable data for TCB extension       */

#if ((OS_CFG_DBG_EN > 0u) || (OS_CFG_STAT_TASK_STK_CHK_EN > 0u))
    CPU_STK             *StkLimitPtr;                       /* Pointer used to set stack 'watermark' limit            */
#endif

    OS_TCB              *NextPtr;                           /* Pointer to next     TCB in the TCB list                */
    OS_TCB              *PrevPtr;                           /* Pointer to previous TCB in the TCB list                */

    OS_TCB              *TickNextPtr;
    OS_TCB              *TickPrevPtr;

    OS_TICK_LIST        *TickListPtr;                       /* Pointer to tick list if task is in a tick list         */

#if ((OS_CFG_DBG_EN > 0u) || (OS_CFG_STAT_TASK_STK_CHK_EN > 0u))
    CPU_STK             *StkBasePtr;                        /* Pointer to base address of stack                       */
#endif

    OS_PEND_DATA        *PendDataTblPtr;                    /* Pointer to list containing objects pended on           */
    OS_STATE             PendOn;                            /* Indicates what task is pending on                      */
    OS_STATUS            PendStatus;                        /* Pend status                                            */

    OS_STATE             TaskState;                         /* See OS_TASK_STATE_xxx                                  */
    OS_PRIO              Prio;                              /* Task priority (0 == highest)                           */
#if OS_CFG_MUTEX_EN > 0u
    OS_PRIO              BasePrio;                          /* Base priority (Not inherited)                          */
    OS_MUTEX            *MutexGrpHeadPtr;                   /* Owned mutex group head pointer                         */
#endif

#if ((OS_CFG_DBG_EN > 0u) || (OS_CFG_STAT_TASK_STK_CHK_EN > 0u))
    CPU_STK_SIZE         StkSize;                           /* Size of task stack (in number of stack elements)       */
#endif
    OS_OPT               Opt;                               /* Task options as passed by OSTaskCreate()               */

    OS_OBJ_QTY           PendDataTblEntries;                /* Size of array of objects to pend on                    */

    CPU_TS               TS;                                /* Timestamp                                              */
    OS_SEM_CTR           SemCtr;                            /* Task specific semaphore counter                        */

                                                            /* DELAY / TIMEOUT                                        */
    OS_TICK              TickRemain;                        /* Number of ticks remaining (updated at by OS_TickTask() */
    OS_TICK              TickCtrPrev;                       /* Used by OSTimeDlyXX() in PERIODIC mode                 */

#if OS_CFG_SCHED_ROUND_ROBIN_EN > 0u
    OS_TICK              TimeQuanta;
    OS_TICK              TimeQuantaCtr;
#endif

#if OS_MSG_EN > 0u
    void                *MsgPtr;                            /* Message received                                       */
    OS_MSG_SIZE          MsgSize;
#endif

#if OS_CFG_TASK_REG_TBL_SIZE > 0u
    OS_REG               RegTbl[OS_CFG_TASK_REG_TBL_SIZE];  /* Task specific registers                                */
#endif

#if OS_CFG_FLAG_EN > 0u
    OS_FLAGS             FlagsPend;                         /* Event flag(s) to wait on                               */
    OS_FLAGS             FlagsRdy;                          /* Event flags that made task ready to run                */
    OS_OPT               FlagsOpt;                          /* Options (See OS_OPT_FLAG_xxx)                          */
#endif

#if OS_CFG_TASK_SUSPEND_EN > 0u
    OS_NESTING_CTR       SuspendCtr;                        /* Nesting counter for OSTaskSuspend()                    */
#endif

#if OS_CFG_TASK_PROFILE_EN > 0u
    OS_CPU_USAGE         CPUUsage;                          /* CPU Usage of task (0.00-100.00%)                       */
    OS_CPU_USAGE         CPUUsageMax;                       /* CPU Usage of task (0.00-100.00%) - Peak                */
    OS_CTX_SW_CTR        CtxSwCtr;                          /* Number of time the task was switched in                */
    CPU_TS               CyclesDelta;                       /* value of OS_TS_GET() - .CyclesStart                    */
    CPU_TS               CyclesStart;                       /* Snapshot of cycle counter at start of task resumption  */
    OS_CYCLES            CyclesTotal;                       /* Total number of # of cycles the task has been running  */
    OS_CYCLES            CyclesTotalPrev;                   /* Snapshot of previous # of cycles                       */

    CPU_TS               SemPendTime;                       /* Time it took for signal to be received                 */
    CPU_TS               SemPendTimeMax;                    /* Max amount of time it took for signal to be received   */
#endif

#if OS_CFG_STAT_TASK_STK_CHK_EN > 0u
    CPU_STK_SIZE         StkUsed;                           /* Number of stack elements used from the stack           */
    CPU_STK_SIZE         StkFree;                           /* Number of stack elements free on   the stack           */
#endif
    CPU_INT32U          Tconsuming;
    CPU_CHAR            *t_name;
};


/*
------------------------------------------------------------------------------------------------------------------------
*                                                    TICK DATA TYPE
------------------------------------------------------------------------------------------------------------------------
*/

struct  os_tick_list {
    OS_TCB              *TCB_Ptr;                           /* Pointer to list of tasks in tick list                 */
};


/*
------------------------------------------------------------------------------------------------------------------------
*                                                   TIMER DATA TYPES
------------------------------------------------------------------------------------------------------------------------
*/


/*
************************************************************************************************************************
************************************************************************************************************************
*                                           G L O B A L   V A R I A B L E S
************************************************************************************************************************
************************************************************************************************************************
*/

#if OS_CFG_APP_HOOKS_EN > 0u
OS_EXT           OS_APP_HOOK_TCB            OS_AppTaskCreateHookPtr;    /* Application hooks                          */
OS_EXT           OS_APP_HOOK_TCB            OS_AppTaskDelHookPtr;
OS_EXT           OS_APP_HOOK_TCB            OS_AppTaskReturnHookPtr;

OS_EXT           OS_APP_HOOK_VOID           OS_AppIdleTaskHookPtr;
OS_EXT           OS_APP_HOOK_VOID           OS_AppStatTaskHookPtr;
OS_EXT           OS_APP_HOOK_VOID           OS_AppTaskSwHookPtr;
OS_EXT           OS_APP_HOOK_VOID           OS_AppTimeTickHookPtr;
#endif

                                                                        /* IDLE TASK -------------------------------- */
OS_EXT            OS_IDLE_CTR               OSIdleTaskCtr;
OS_EXT            OS_TCB                    OSIdleTaskTCB;

                                                                        /* MISCELLANEOUS ---------------------------- */
OS_EXT            OS_NESTING_CTR            OSIntNestingCtr;            /* Interrupt nesting level                    */

OS_EXT            OS_STATE                  OSRunning;                  /* Flag indicating that kernel is running     */


                                                                        /* OS_MSG POOL ------------------------------ */
#if OS_MSG_EN > 0u
OS_EXT            OS_MSG_POOL               OSMsgPool;                  /* Pool of OS_MSG                             */
#endif
                                                                        /* MUTEX MANAGEMENT ------------------------- */
#if OS_CFG_MUTEX_EN > 0u
OS_EXT            OS_OBJ_QTY                OSMutexQty;                 /* Number of mutexes created                  */
#endif

                                                                        /* PRIORITIES ------------------------------- */
OS_EXT            OS_PRIO                   OSPrioCur;                  /* Priority of current task                   */
OS_EXT            OS_PRIO                   OSPrioHighRdy;              /* Priority of highest priority task          */
OS_EXT            OS_PRIO                   OSPrioSaved;                /* Saved priority level when Post Deferred    */
extern            CPU_DATA                  OSPrioTbl[OS_PRIO_TBL_SIZE];

                                                                        /* QUEUES ----------------------------------- */
#if OS_CFG_Q_EN   > 0u
#if OS_CFG_DBG_EN > 0u
OS_EXT            OS_Q                     *OSQDbgListPtr;
#endif
OS_EXT            OS_OBJ_QTY                OSQQty;                     /* Number of message queues created           */
#endif
                                                                        /* READY LIST ------------------------------- */
OS_EXT            OS_RDY_LIST               OSRdyList[OS_CFG_PRIO_MAX]; /* Table of tasks ready to run                */


                                                                        /* SCHEDULER -------------------------------- */

OS_EXT            OS_NESTING_CTR            OSSchedLockNestingCtr;      /* Lock nesting level                         */
#if OS_CFG_SCHED_ROUND_ROBIN_EN > 0u
OS_EXT            OS_TICK                   OSSchedRoundRobinDfltTimeQuanta;
OS_EXT            CPU_BOOLEAN               OSSchedRoundRobinEn;        /* Enable/Disable round-robin scheduling      */
#endif
                                                                        /* SEMAPHORES ------------------------------- */
#if OS_CFG_SEM_EN > 0u
OS_EXT            OS_OBJ_QTY                OSSemQty;                   /* Number of semaphores created               */
#endif

                                                                        /* TASKS ------------------------------------ */
OS_EXT            OS_CTX_SW_CTR             OSTaskCtxSwCtr;             /* Number of context switches                 */
OS_EXT            OS_OBJ_QTY                OSTaskQty;                  /* Number of tasks created                    */

#if OS_CFG_TASK_REG_TBL_SIZE > 0u
OS_EXT            OS_REG_ID                 OSTaskRegNextAvailID;       /* Next available Task Register ID            */
#endif

                                                                        /* TICK TASK -------------------------------- */
OS_EXT            OS_TICK                   OSTickCtr;                  /* Cnts the #ticks since startup or last set  */
OS_EXT            CPU_TS                    OSTickTaskTimeMax;
OS_EXT            OS_TICK_LIST              OSTickListDly;
OS_EXT            OS_TICK_LIST              OSTickListTimeout;


                                                                        /* TCBs ------------------------------------- */
OS_EXT            OS_TCB                   *OSTCBCurPtr;                /* Pointer to currently running TCB           */
OS_EXT            OS_TCB                   *OSTCBHighRdyPtr;            /* Pointer to highest priority  TCB           */


/*
************************************************************************************************************************
************************************************************************************************************************
*                                                   E X T E R N A L S
************************************************************************************************************************
************************************************************************************************************************
*/

extern  CPU_STK     * const OSCfg_IdleTaskStkBasePtr;
extern  CPU_STK_SIZE  const OSCfg_IdleTaskStkLimit;
extern  CPU_STK_SIZE  const OSCfg_IdleTaskStkSize;
extern  CPU_INT32U    const OSCfg_IdleTaskStkSizeRAM;

extern  OS_OBJ_QTY    const OSCfg_IntQSize;
extern  CPU_INT32U    const OSCfg_IntQSizeRAM;
extern  CPU_STK     * const OSCfg_IntQTaskStkBasePtr;
extern  CPU_STK_SIZE  const OSCfg_IntQTaskStkLimit;
extern  CPU_STK_SIZE  const OSCfg_IntQTaskStkSize;
extern  CPU_INT32U    const OSCfg_IntQTaskStkSizeRAM;

extern  OS_MSG_SIZE   const OSCfg_MsgPoolSize;
extern  CPU_INT32U    const OSCfg_MsgPoolSizeRAM;
extern  OS_MSG      * const OSCfg_MsgPoolBasePtr;

extern  OS_PRIO       const OSCfg_StatTaskPrio;
extern  OS_RATE_HZ    const OSCfg_StatTaskRate_Hz;
extern  CPU_STK     * const OSCfg_StatTaskStkBasePtr;
extern  CPU_STK_SIZE  const OSCfg_StatTaskStkLimit;
extern  CPU_STK_SIZE  const OSCfg_StatTaskStkSize;
extern  CPU_INT32U    const OSCfg_StatTaskStkSizeRAM;

extern  CPU_STK_SIZE  const OSCfg_StkSizeMin;

extern  OS_RATE_HZ    const OSCfg_TickRate_Hz;

extern  CPU_STK        OSCfg_IdleTaskStk[];

extern  CPU_STK        OSCfg_ISRStk[];

#if (OS_MSG_EN > 0u)
extern  OS_MSG         OSCfg_MsgPool[];
#endif

/*
************************************************************************************************************************
************************************************************************************************************************
*                                        F U N C T I O N   P R O T O T Y P E S
************************************************************************************************************************
************************************************************************************************************************
*/

/* ================================================================================================================== */
/*                                                    EVENT FLAGS                                                     */
/* ================================================================================================================== */


/* ================================================================================================================== */
/*                                          FIXED SIZE MEMORY BLOCK MANAGEMENT                                        */
/* ================================================================================================================== */


/* ================================================================================================================== */
/*                                             MUTUAL EXCLUSION SEMAPHORES                                            */
/* ================================================================================================================== */

#if OS_CFG_MUTEX_EN > 0u

void          OSMutexCreate             (OS_MUTEX              *p_mutex,
                                         CPU_CHAR              *p_name,
                                         OS_ERR                *p_err);

#if OS_CFG_MUTEX_DEL_EN > 0u
OS_OBJ_QTY    OSMutexDel                (OS_MUTEX              *p_mutex,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);
#endif

void          OSMutexPend               (OS_MUTEX              *p_mutex,
                                         OS_TICK                timeout,
                                         OS_OPT                 opt,
                                         CPU_TS                *p_ts,
                                         OS_ERR                *p_err);

#if OS_CFG_MUTEX_PEND_ABORT_EN > 0u
OS_OBJ_QTY    OSMutexPendAbort          (OS_MUTEX              *p_mutex,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);
#endif

void          OSMutexPost               (OS_MUTEX              *p_mutex,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);


/* ------------------------------------------------ INTERNAL FUNCTIONS ---------------------------------------------- */

void          OS_MutexClr               (OS_MUTEX              *p_mutex);

void          OS_MutexInit              (OS_ERR                *p_err);
#endif

void          OS_MutexGrpAdd            (OS_TCB                *p_tcb,
                                         OS_MUTEX              *p_mutex);

void          OS_MutexGrpRemove         (OS_TCB                *p_tcb,
                                         OS_MUTEX              *p_mutex);

OS_PRIO       OS_MutexGrpPrioFindHighest(OS_TCB                *p_tcb);

void          OS_MutexGrpPostAll        (OS_TCB                *p_tcb);


/* ================================================================================================================== */
/*                                                    MULTI PEND                                                      */
/* ================================================================================================================== */

/* ================================================================================================================== */
/*                                                   MESSAGE QUEUES                                                   */
/* ================================================================================================================== */

/* ================================================================================================================== */
/*                                                     SEMAPHORES                                                     */
/* ================================================================================================================== */

#if OS_CFG_SEM_EN > 0u

void          OSSemCreate               (OS_SEM                *p_sem,
                                         CPU_CHAR              *p_name,
                                         OS_SEM_CTR             cnt,
                                         OS_ERR                *p_err);

#if OS_CFG_SEM_DEL_EN > 0u
OS_OBJ_QTY    OSSemDel                  (OS_SEM                *p_sem,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);
#endif

OS_SEM_CTR    OSSemPend                 (OS_SEM                *p_sem,
                                         OS_TICK                timeout,
                                         OS_OPT                 opt,
                                         CPU_TS                *p_ts,
                                         OS_ERR                *p_err);

#if OS_CFG_SEM_PEND_ABORT_EN > 0u
OS_OBJ_QTY    OSSemPendAbort            (OS_SEM                *p_sem,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);
#endif

OS_SEM_CTR    OSSemPost                 (OS_SEM                *p_sem,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);

#if OS_CFG_SEM_SET_EN > 0u
void          OSSemSet                  (OS_SEM                *p_sem,
                                         OS_SEM_CTR             cnt,
                                         OS_ERR                *p_err);
#endif

/* ------------------------------------------------ INTERNAL FUNCTIONS ---------------------------------------------- */

void          OS_SemClr                 (OS_SEM                *p_sem);

void          OS_SemInit                (OS_ERR                *p_err);

OS_SEM_CTR    OS_SemPost                (OS_SEM                *p_sem,
                                         OS_OPT                 opt,
                                         CPU_TS                 ts,
                                         OS_ERR                *p_err);
#endif


/* ================================================================================================================== */
/*                                                 TASK MANAGEMENT                                                    */
/* ================================================================================================================== */

#if OS_CFG_TASK_CHANGE_PRIO_EN > 0u
void          OSTaskChangePrio          (OS_TCB                *p_tcb,
                                         OS_PRIO                prio_new,
                                         OS_ERR                *p_err);
#endif

void          OSTaskCreate              (OS_TCB                *p_tcb,
                                         CPU_CHAR              *p_name,
                                         OS_TASK_PTR            p_task,
                                         void                  *p_arg,
                                         OS_PRIO                prio,
                                         CPU_STK               *p_stk_base,
                                         CPU_STK_SIZE           stk_limit,
                                         CPU_STK_SIZE           stk_size,
                                         OS_MSG_QTY             q_size,
                                         OS_TICK                time_quanta,
                                         void                  *p_ext,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);

#if OS_CFG_TASK_DEL_EN > 0u
void          OSTaskDel                 (OS_TCB                *p_tcb,
                                         OS_ERR                *p_err);
#endif


#if OS_CFG_TASK_REG_TBL_SIZE > 0u
OS_REG        OSTaskRegGet              (OS_TCB                *p_tcb,
                                         OS_REG_ID              id,
                                         OS_ERR                *p_err);

OS_REG_ID     OSTaskRegGetID            (OS_ERR                *p_err);

void          OSTaskRegSet              (OS_TCB                *p_tcb,
                                         OS_REG_ID              id,
                                         OS_REG                 value,
                                         OS_ERR                *p_err);
#endif

#if OS_CFG_TASK_SUSPEND_EN > 0u
void          OSTaskResume              (OS_TCB                *p_tcb,
                                         OS_ERR                *p_err);

void          OSTaskSuspend             (OS_TCB                *p_tcb,
                                         OS_ERR                *p_err);
#endif

OS_SEM_CTR    OSTaskSemPend             (OS_TICK                timeout,
                                         OS_OPT                 opt,
                                         CPU_TS                *p_ts,
                                         OS_ERR                *p_err);

#if (OS_CFG_TASK_SEM_PEND_ABORT_EN > 0u)
CPU_BOOLEAN   OSTaskSemPendAbort        (OS_TCB                *p_tcb,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);
#endif

OS_SEM_CTR    OSTaskSemPost             (OS_TCB                *p_tcb,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);

OS_SEM_CTR    OSTaskSemSet              (OS_TCB                *p_tcb,
                                         OS_SEM_CTR             cnt,
                                         OS_ERR                *p_err);

#if OS_CFG_STAT_TASK_STK_CHK_EN > 0u
void          OSTaskStkChk              (OS_TCB                *p_tcb,
                                         CPU_STK_SIZE          *p_free,
                                         CPU_STK_SIZE          *p_used,
                                         OS_ERR                *p_err);
#endif

#if OS_CFG_SCHED_ROUND_ROBIN_EN > 0u
void          OSTaskTimeQuantaSet       (OS_TCB                *p_tcb,
                                         OS_TICK                time_quanta,
                                         OS_ERR                *p_err);
#endif

/* ------------------------------------------------ INTERNAL FUNCTIONS ---------------------------------------------- */

void          OS_TaskBlock              (OS_TCB                *p_tcb,
                                         OS_TICK                timeout);

void          OS_TaskInit               (OS_ERR                *p_err);

void          OS_TaskInitTCB            (OS_TCB                *p_tcb);

void          OS_TaskQPost              (OS_TCB                *p_tcb,
                                         void                  *p_void,
                                         OS_MSG_SIZE            msg_size,
                                         OS_OPT                 opt,
                                         CPU_TS                 ts,
                                         OS_ERR                *p_err);

#if OS_CFG_TASK_SUSPEND_EN > 0u
void          OS_TaskResume             (OS_TCB                *p_tcb,
                                         OS_ERR                *p_err);
#endif

void          OS_TaskReturn             (void);

OS_SEM_CTR    OS_TaskSemPost            (OS_TCB                *p_tcb,
                                         OS_OPT                 opt,
                                         CPU_TS                 ts,
                                         OS_ERR                *p_err);

#if OS_CFG_TASK_SUSPEND_EN > 0u
void          OS_TaskSuspend            (OS_TCB                *p_tcb,
                                         OS_ERR                *p_err);
#endif

void          OS_TaskChangePrio(         OS_TCB                *p_tcb,
                                         OS_PRIO                prio_new);

/* ================================================================================================================== */
/*                                          TASK LOCAL STORAGE (TLS) SUPPORT                                          */
/* ================================================================================================================== */

/* ================================================================================================================== */
/*                                                 TIME MANAGEMENT                                                    */
/* ================================================================================================================== */

void          OSTimeDly                 (OS_TICK                dly,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);

#if OS_CFG_TIME_DLY_RESUME_EN > 0u
void          OSTimeDlyResume           (OS_TCB                *p_tcb,
                                         OS_ERR                *p_err);
#endif

OS_TICK       OSTimeGet                 (OS_ERR                *p_err);

void          OSTimeSet                 (OS_TICK                ticks,
                                         OS_ERR                *p_err);

void          OSTimeTick                (void);


/* ================================================================================================================== */
/*                                                 TIMER MANAGEMENT                                                   */
/* ================================================================================================================== */

/* ================================================================================================================== */
/*                                                    MISCELLANEOUS                                                   */
/* ================================================================================================================== */

void          OSInit                    (OS_ERR                *p_err);

void          OSIntEnter                (void);
void          OSIntExit                 (void);

#if OS_CFG_SCHED_ROUND_ROBIN_EN > 0u
void          OSSchedRoundRobinCfg      (CPU_BOOLEAN            en,
                                         OS_TICK                dflt_time_quanta,
                                         OS_ERR                *p_err);

void          OSSchedRoundRobinYield    (OS_ERR                *p_err);

#endif

void          OSSched                   (void);

void          OSSchedLock               (OS_ERR                *p_err);
void          OSSchedUnlock             (OS_ERR                *p_err);

void          OSStart                   (OS_ERR                *p_err);

void        OSCtxSw                             (void);
void        OSIntCtxSw                          (void);
void        OSStartHighRdy                      (void);

CPU_INT16U    OSVersion                 (OS_ERR                *p_err);

/* ------------------------------------------------ INTERNAL FUNCTIONS ---------------------------------------------- */

void          OS_IdleTask               (void                  *p_arg);

void          OS_IdleTaskInit           (OS_ERR                *p_err);

/*
************************************************************************************************************************
************************************************************************************************************************
*                                    T A R G E T   S P E C I F I C   F U N C T I O N S
************************************************************************************************************************
************************************************************************************************************************
*/

#ifdef __cplusplus
extern  "C" {
#endif

void          OSInitHook                (void);

void          OSTaskCreateHook          (OS_TCB                *p_tcb);
void          OSTaskDelHook             (OS_TCB                *p_tcb);

void          OSIdleTaskHook            (void);

void          OSTaskReturnHook          (OS_TCB                *p_tcb);

void          OSStatTaskHook            (void);

CPU_STK      *OSTaskStkInit             (OS_TASK_PTR            p_task,
                                         void                  *p_arg,
                                         CPU_STK               *p_stk_base,
                                         CPU_STK               *p_stk_limit,
                                         CPU_STK_SIZE           stk_size,
                                         OS_OPT                 opt);

void          OSTaskSwHook              (void);

void          OSTimeTickHook            (void);

#ifdef __cplusplus
}
#endif


/*
************************************************************************************************************************
************************************************************************************************************************
*                   u C / O S - I I I   I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
************************************************************************************************************************
************************************************************************************************************************
*/

void          OSCfg_Init                (void);

/* ----------------------------------------------- MESSAGE MANAGEMENT ----------------------------------------------- */

void          OS_MsgPoolInit            (OS_ERR                *p_err);

OS_MSG_QTY    OS_MsgQFreeAll            (OS_MSG_Q              *p_msg_q);

void         *OS_MsgQGet                (OS_MSG_Q              *p_msg_q,
                                         OS_MSG_SIZE           *p_msg_size,
                                         CPU_TS                *p_ts,
                                         OS_ERR                *p_err);

void          OS_MsgQInit               (OS_MSG_Q              *p_msg_q,
                                         OS_MSG_QTY             size);

void          OS_MsgQPut                (OS_MSG_Q              *p_msg_q,
                                         void                  *p_void,
                                         OS_MSG_SIZE            msg_size,
                                         OS_OPT                 opt,
                                         CPU_TS                 ts,
                                         OS_ERR                *p_err);

/* ---------------------------------------------- PEND/POST MANAGEMENT ---------------------------------------------- */

void          OS_Pend                   (OS_PEND_DATA          *p_pend_data,
                                         OS_PEND_OBJ           *p_obj,
                                         OS_STATE               pending_on,
                                         OS_TICK                timeout);

void          OS_PendAbort              (OS_PEND_OBJ           *p_obj,
                                         OS_TCB                *p_tcb,
                                         CPU_TS                 ts);

void          OS_PendAbort1             (OS_PEND_OBJ           *p_obj,
                                         OS_TCB                *p_tcb,
                                         CPU_TS                 ts);

void          OS_PendObjDel             (OS_PEND_OBJ           *p_obj,
                                         OS_TCB                *p_tcb,
                                         CPU_TS                 ts);

void          OS_PendObjDel1            (OS_PEND_OBJ           *p_obj,
                                         OS_TCB                *p_tcb,
                                         CPU_TS                 ts);

void          OS_Post                   (OS_PEND_OBJ           *p_obj,
                                         OS_TCB                *p_tcb,
                                         void                  *p_void,
                                         OS_MSG_SIZE            msg_size,
                                         CPU_TS                 ts);

void          OS_Post1                  (OS_PEND_OBJ           *p_obj,
                                         OS_TCB                *p_tcb,
                                         void                  *p_void,
                                         OS_MSG_SIZE            msg_size,
                                         CPU_TS                 ts);

/* ----------------------------------------------- PRIORITY MANAGEMENT ---------------------------------------------- */

void          OS_PrioInit               (void);

void          OS_PrioInsert             (OS_PRIO                prio);

void          OS_PrioRemove             (OS_PRIO                prio);

OS_PRIO       OS_PrioGetHighest         (void);

/* --------------------------------------------------- SCHEDULING --------------------------------------------------- */

#if OS_CFG_SCHED_ROUND_ROBIN_EN > 0u
void          OS_SchedRoundRobin        (OS_RDY_LIST           *p_rdy_list);
#endif

/* --------------------------------------------- READY LIST MANAGEMENT ---------------------------------------------- */

void          OS_RdyListInit            (void);

void          OS_RdyListInsert          (OS_TCB                *p_tcb);

void          OS_RdyListInsertHead      (OS_TCB                *p_tcb);

void          OS_RdyListInsertTail      (OS_TCB                *p_tcb);

void          OS_RdyListMoveHeadToTail  (OS_RDY_LIST           *p_rdy_list);

void          OS_RdyListRemove          (OS_TCB                *p_tcb);

/* ---------------------------------------------- PEND LIST MANAGEMENT ---------------------------------------------- */

void          OS_PendDataInit           (OS_TCB                *p_tcb,
                                         OS_PEND_DATA          *p_pend_data_tbl,
                                         OS_OBJ_QTY             tbl_size);

OS_PEND_LIST *OS_PendListGetPtr         (OS_PEND_OBJ           *p_obj);

void          OS_PendListInit           (OS_PEND_LIST          *p_pend_list);

void          OS_PendListInsertHead     (OS_PEND_LIST          *p_pend_list,
                                         OS_PEND_DATA          *p_pend_data);

void          OS_PendListInsertPrio     (OS_PEND_LIST          *p_pend_list,
                                         OS_PEND_DATA          *p_pend_data);

void          OS_PendListChangePrio     (OS_TCB                *p_tcb);

void          OS_PendListRemove         (OS_TCB                *p_tcb);

void          OS_PendListRemove1        (OS_PEND_LIST          *p_pend_list,
                                         OS_PEND_DATA          *p_pend_data);

/* ---------------------------------------------- TICK LIST MANAGEMENT ---------------------------------------------- */

void          OS_TickListInsert         (OS_TICK_LIST          *p_list,
                                         OS_TCB                *p_tcb,
                                         OS_TICK                time);

void          OS_TickListInsertDly      (OS_TCB                *p_tcb,
                                         OS_TICK                time,
                                         OS_OPT                 opt,
                                         OS_ERR                *p_err);

void          OS_TickListRemove         (OS_TCB                *p_tcb);

void          OS_TickListResetPeak      (void);


/*
************************************************************************************************************************
*                                          LOOK FOR MISSING #define CONSTANTS
*
* This section is used to generate ERROR messages at compile time if certain #define constants are
* MISSING in OS_CFG.H.  This allows you to quickly determine the source of the error.
*
* You SHOULD NOT change this section UNLESS you would like to add more comments as to the source of the
* compile time error.
************************************************************************************************************************
*/

/*
************************************************************************************************************************
*                                                     MISCELLANEOUS
************************************************************************************************************************
*/

#ifndef OS_CFG_APP_HOOKS_EN
#error  "OS_CFG.H, Missing OS_CFG_APP_HOOKS_EN: Enable (1) or Disable (0) application specific hook functions"
#endif


#ifndef OS_CFG_ARG_CHK_EN
#error  "OS_CFG.H, Missing OS_CFG_ARG_CHK_EN: Enable (1) or Disable (0) argument checking"
#endif

#ifndef OS_CFG_CALLED_FROM_ISR_CHK_EN
#error  "OS_CFG.H, Missing OS_CFG_CALLED_FROM_ISR_CHK_EN: Enable (1) or Disable (0) checking whether in an ISR in kernel services"
#endif


#ifndef OS_CFG_OBJ_TYPE_CHK_EN
#error  "OS_CFG.H, Missing OS_CFG_OBJ_TYPE_CHK_EN: Enable (1) or Disable (0) checking for proper object types in kernel services"
#endif

#if     OS_CFG_PRIO_MAX < 8u
#error  "OS_CFG.H,         OS_CFG_PRIO_MAX must be >= 8"
#endif


#ifndef OS_CFG_SCHED_LOCK_TIME_MEAS_EN
#error  "OS_CFG.H, Missing OS_CFG_SCHED_LOCK_TIME_MEAS_EN: Include code to measure scheduler lock time"
#else
    #if    (OS_CFG_SCHED_LOCK_TIME_MEAS_EN > 0u) && \
           (OS_CFG_TS_EN                   < 1u)
    #error  "OS_CFG.H,         OS_CFG_TS_EN must be Enabled (1) to measure scheduler lock time"
    #endif
#endif


#ifndef OS_CFG_SCHED_ROUND_ROBIN_EN
#error  "OS_CFG.H, Missing OS_CFG_SCHED_ROUND_ROBIN_EN: Include code for Round Robin Scheduling"
#endif


#ifndef OS_CFG_STK_SIZE_MIN
#error  "OS_CFG.H, Missing OS_CFG_STK_SIZE_MIN: Determines the minimum size for a task stack"
#endif

/*
************************************************************************************************************************
*                                              MUTUAL EXCLUSION SEMAPHORES
************************************************************************************************************************
*/

#ifndef OS_CFG_MUTEX_EN
#error  "OS_CFG.H, Missing OS_CFG_MUTEX_EN: Enable (1) or Disable (0) code generation for MUTEX"
#else
    #ifndef OS_CFG_MUTEX_DEL_EN
    #error  "OS_CFG.H, Missing OS_CFG_MUTEX_DEL_EN: Include code for OSMutexDel()"
    #endif

    #ifndef OS_CFG_MUTEX_PEND_ABORT_EN
    #error  "OS_CFG.H, Missing OS_CFG_MUTEX_PEND_ABORT_EN: Include code for OSMutexPendAbort()"
    #endif
#endif

/*
************************************************************************************************************************
*                                                    MESSAGE QUEUES
************************************************************************************************************************
*/

#ifndef OS_CFG_Q_EN
#error  "OS_CFG.H, Missing OS_CFG_Q_EN: Enable (1) or Disable (0) code generation for QUEUES"
#else
    #ifndef OS_CFG_Q_DEL_EN
    #error  "OS_CFG.H, Missing OS_CFG_Q_DEL_EN: Include code for OSQDel()"
    #endif

    #ifndef OS_CFG_Q_FLUSH_EN
    #error  "OS_CFG.H, Missing OS_CFG_Q_FLUSH_EN: Include code for OSQFlush()"
    #endif

    #ifndef OS_CFG_Q_PEND_ABORT_EN
    #error  "OS_CFG.H, Missing OS_CFG_Q_PEND_ABORT_EN: Include code for OSQPendAbort()"
    #endif
#endif


/*
************************************************************************************************************************
*                                                      SEMAPHORES
************************************************************************************************************************
*/

#ifndef OS_CFG_SEM_EN
#error  "OS_CFG.H, Missing OS_CFG_SEM_EN: Enable (1) or Disable (0) code generation for SEMAPHORES"
#else
    #ifndef OS_CFG_SEM_DEL_EN
    #error  "OS_CFG.H, Missing OS_CFG_SEM_DEL_EN: Include code for OSSemDel()"
    #endif

    #ifndef OS_CFG_SEM_PEND_ABORT_EN
    #error  "OS_CFG.H, Missing OS_CFG_SEM_PEND_ABORT_EN: Include code for OSSemPendAbort()"
    #endif

    #ifndef OS_CFG_SEM_SET_EN
    #error  "OS_CFG.H, Missing OS_CFG_SEM_SET_EN: Include code for OSSemSet()"
    #endif
#endif

/*
************************************************************************************************************************
*                                                   TASK MANAGEMENT
************************************************************************************************************************
*/

#ifndef OS_CFG_STAT_TASK_STK_CHK_EN
#error  "OS_CFG.H, Missing OS_CFG_STAT_TASK_STK_CHK_EN: Check task stacks from statistics task"
#endif

#ifndef OS_CFG_TASK_DEL_EN
#error  "OS_CFG.H, Missing OS_CFG_TASK_DEL_EN: Include code for OSTaskDel()"
#endif

#ifndef OS_CFG_TASK_Q_EN
#error  "OS_CFG.H, Missing OS_CFG_TASK_Q_EN: Include code for OSTaskQxxx()"
#endif

#ifndef OS_CFG_TASK_Q_PEND_ABORT_EN
#error  "OS_CFG.H, Missing OS_CFG_TASK_Q_PEND_ABORT_EN: Include code for OSTaskQPendAbort()"
#endif

#ifndef OS_CFG_TASK_PROFILE_EN
#error  "OS_CFG.H, Missing OS_CFG_TASK_PROFILE_EN: Include code for task profiling"
#endif

#ifndef OS_CFG_TASK_REG_TBL_SIZE
#error  "OS_CFG.H, Missing OS_CFG_TASK_REG_TBL_SIZE: Include support for task specific registers"
#endif

#ifndef OS_CFG_TASK_SEM_PEND_ABORT_EN
#error  "OS_CFG.H, Missing OS_CFG_TASK_SEM_PEND_ABORT_EN: Include code for OSTaskSemPendAbort()"
#endif

#ifndef OS_CFG_TASK_SUSPEND_EN
#error  "OS_CFG.H, Missing OS_CFG_TASK_SUSPEND_EN: Include code for OSTaskSuspend() and OSTaskResume()"
#endif

/*
************************************************************************************************************************
*                                                  TIME MANAGEMENT
************************************************************************************************************************
*/

#ifndef OS_CFG_TIME_DLY_RESUME_EN
#error  "OS_CFG.H, Missing OS_CFG_TIME_DLY_RESUME_EN: Include code for OSTimeDlyResume()"
#endif

/*
************************************************************************************************************************
*                                                 uC/OS-III MODULE END
************************************************************************************************************************
*/

#endif
