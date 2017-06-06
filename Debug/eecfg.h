#ifndef RTDH_EECFG_H
#define RTDH_EECFG_H


#define RTDRUID_CONFIGURATOR_NUMBER 1278



/***************************************************************************
 *
 * Common defines ( CPU 0 )
 *
 **************************************************************************/

    /* TASK definition */
    #define EE_MAX_TASK 3
    #define CC 0
    #define LKAS 1
    #define RCV 2

    /* MUTEX definition */
    #define EE_MAX_RESOURCE 1U
    #define RES_SCHEDULER 0U

    /* ALARM definition */
    #define EE_MAX_ALARM 3U
    #define cyclic_alarm1 0U
    #define cyclic_alarm2 1U
    #define cyclic_alarm3 2U

    /* SCHEDULING TABLE definition */
    #define EE_MAX_SCHEDULETABLE 0U

    /* COUNTER OBJECTS definition */
    #define EE_MAX_COUNTER_OBJECTS (EE_MAX_ALARM + EE_MAX_SCHEDULETABLE)

    /* COUNTER definition */
    #define EE_MAX_COUNTER 1U
    #define SysTimerCnt 0U

    /* APPMODE definition */
    #define EE_MAX_APPMODE 2U
    #define appmode1 1

    /* CPUs */
    #define EE_MAX_CPU 1
    #define EE_CURRENTCPU 0

    /* Number of isr 2 */
    #define EE_MAX_ISR2   1
    #define EE_MAX_ISR_ID 1

#ifndef __DISABLE_EEOPT_DEFINES__


/***************************************************************************
 *
 * User options
 *
 **************************************************************************/
#define __ARDUINO_SDK__
#define __ARDUINO_UNO_328__
#define __ADD_LIBS__
#define __OO_STARTOS_OLD__


/***************************************************************************
 *
 * Automatic options
 *
 **************************************************************************/
#define __RTD_CYGWIN__
#define __ATMEGA__
#define __AVR8__
#define __OO_BCC2__
#define __MONO__
#define __OO_HAS_USERESSCHEDULER__
#define __OO_AUTOSTART_ALARM__
#define __ALLOW_NESTED_IRQ__

#endif



/***************************************************************************
 *
 * ISR definition
 *
 **************************************************************************/
#define EE_AVR8_TIMER2_COMPA_ISR isr
#define EE_AVR8_TIMER2_COMPA_ISR_PRI EE_ISR_PRI_1
#define EE_AVR8_TIMER2_COMPA_ISR_CAT 2


/***************************************************************************
 *
 * Counter defines
 *
 **************************************************************************/
#define OSMAXALLOWEDVALUE_SysTimerCnt 10000U
#define OSTICKSPERBASE_SysTimerCnt    1U
#define OSMINCYCLE_SysTimerCnt        1U



/***************************************************************************
 *
 * Vector size defines
 *
 **************************************************************************/
    #define EE_ACTION_ROM_SIZE 3
    #define EE_ALARM_ROM_SIZE 3
    #define EE_COUNTER_OBJECTS_ROM_SIZE 3
    #define EE_COUNTER_ROM_SIZE 1
    #define EE_OO_AUTOSTART_ALARM_MODE_APPMODE1_SIZE 3
    #define EE_OO_AUTOSTART_ALARM_MODE_OSDEFAULTAPPMODE_SIZE 0
    #define EE_RQ_PAIRS_NEXT_SIZE 3
    #define EE_RQ_PAIRS_TID_SIZE 3
    #define EE_RQ_QUEUES_HEAD_SIZE 8
    #define EE_RQ_QUEUES_TAIL_SIZE 8


#endif

