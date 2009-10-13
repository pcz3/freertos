/*
    FreeRTOS V6.0.0 - Copyright (C) 2009 Real Time Engineers Ltd.

    ***************************************************************************
    *                                                                         *
    * If you are:                                                             *
    *                                                                         *
    *    + New to FreeRTOS,                                                   *
    *    + Wanting to learn FreeRTOS or multitasking in general quickly       *
    *    + Looking for basic training,                                        *
    *    + Wanting to improve your FreeRTOS skills and productivity           *
    *                                                                         *
    * then take a look at the FreeRTOS eBook                                  *
    *                                                                         *
    *        "Using the FreeRTOS Real Time Kernel - a Practical Guide"        *
    *                  http://www.FreeRTOS.org/Documentation                  *
    *                                                                         *
    * A pdf reference manual is also available.  Both are usually delivered   *
    * to your inbox within 20 minutes to two hours when purchased between 8am *
    * and 8pm GMT (although please allow up to 24 hours in case of            *
    * exceptional circumstances).  Thank you for your support!                *
    *                                                                         *
    ***************************************************************************

    This file is part of the FreeRTOS distribution.

    FreeRTOS is free software; you can redistribute it and/or modify it under
    the terms of the GNU General Public License (version 2) as published by the
    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.
    ***NOTE*** The exception to the GPL is included to allow you to distribute
    a combined work that includes FreeRTOS without being obliged to provide the
    source code for proprietary components outside of the FreeRTOS kernel.
    FreeRTOS is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
    more details. You should have received a copy of the GNU General Public 
    License and the FreeRTOS license exception along with FreeRTOS; if not it 
    can be viewed here: http://www.freertos.org/a00114.html and also obtained 
    by writing to Richard Barry, contact details for whom are available on the
    FreeRTOS WEB site.

    1 tab == 4 spaces!

    http://www.FreeRTOS.org - Documentation, latest information, license and
    contact details.

    http://www.SafeRTOS.com - A version that is certified for use in safety
    critical systems.

    http://www.OpenRTOS.com - Commercial support, development, porting,
    licensing and training services.
*/

/*
 * Creates all the demo application tasks, then starts the scheduler.
 *
 * Main. c also creates a task called "Print".  This only executes every five 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.  
 * Nearly all the tasks in the demo application maintain a unique count that is 
 * incremented each time the task successfully completes its function.  Should any 
 * error occur within the task the count is permanently halted.  The print task 
 * checks the count of each task to ensure it has changed since the last time the 
 * print task executed.  If any count is found not to have changed the print task
 * displays an appropriate message, halts, and flashes the on board LED rapidly.
 * If all the tasks are still incrementing their unique counts the print task
 * displays an "OK" message.
 *
 * The LED flash tasks do not maintain a count as they already provide visual
 * feedback of their status.
 *
 * The print task blocks on the queue into which messages that require displaying
 * are posted.  It will therefore only block for the full 5 seconds if no messages
 * are posted onto the queue.
 *
 * Main. c also provides a demonstration of how the trace visualisation utility can
 * be used, and how the scheduler can be stopped.
 *
 * On the Flashlite it is preferable not to try to write to the console during
 * real time operation.  The built in LED is toggled every cycle of the print task
 * that does not encounter any errors, so the console IO may be removed if required.
 * The build in LED will start flashing rapidly if any task reports an error.
 */

/*
Changes from V1.01:

	+ Previously, if an error occurred in a task the on board LED was stopped from
	  toggling.  Now if an error occurs the check task enters an infinite loop,
	  toggling the LED rapidly.

Changes from V1.2.3

	+ The integer and comtest tasks are now used when the cooperative scheduler 
	  is being used.  Previously they were only used with the preemptive
	  scheduler.

Changes from V1.2.5

	+ Made the communications RX task a higher priority.

Changes from V2.0.0

	+ Delay periods are now specified using variables and constants of
	  portTickType rather than unsigned long.
*/

#include <stdlib.h>
#include <conio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "partest.h"
#include "serial.h"

/* Demo file headers. */
#include "BlockQ.h"
#include "PollQ.h"
#include "death.h"
#include "flash.h"
#include "integer.h"
#include "print.h"
#include "comtest.h"
#include "fileio.h"
#include "semtest.h"

/* Priority definitions for all the tasks in the demo application. */
#define mainLED_TASK_PRIORITY			( tskIDLE_PRIORITY + 1 )
#define mainCREATOR_TASK_PRIORITY		( tskIDLE_PRIORITY + 3 )
#define mainPRINT_TASK_PRIORITY			( tskIDLE_PRIORITY + 5 )
#define mainQUEUE_POLL_PRIORITY			( tskIDLE_PRIORITY + 2 )
#define mainQUEUE_BLOCK_PRIORITY		( tskIDLE_PRIORITY + 3 )
#define mainCOM_TEST_PRIORITY			( tskIDLE_PRIORITY + 3 )
#define mainSEMAPHORE_TASK_PRIORITY		( tskIDLE_PRIORITY + 1 )

#define mainPRINT_STACK_SIZE		( ( unsigned short ) 256 )
#define mainDEBUG_LOG_BUFFER_SIZE	( ( unsigned short ) 20480 )

/* Constant definitions for accessing the build in LED on the Flashlite 186. */
#define mainLED_REG_DIR 			( ( unsigned short ) 0xff78 )
#define mainLED_REG 				( ( unsigned short ) 0xff7a )

/* If an error is detected in a task then the vErrorChecks() task will enter
an infinite loop flashing the LED at this rate. */
#define mainERROR_FLASH_RATE		( ( portTickType ) 100 / portTICK_RATE_MS )

/* Task function for the "Print" task as described at the top of the file. */
static void vErrorChecks( void *pvParameters );

/* Function that checks the unique count of all the other tasks as described at
the top of the file. */
static void prvCheckOtherTasksAreStillRunning( void );

/* Functions to setup and use the built in LED on the Flashlite 186 board. */
static void prvToggleLED( void );
static void prvInitLED( void );

/* Key presses can be used to start/stop the trace visualisation utility or stop
the scheduler. */
static void	prvCheckForKeyPresses( void );

/* Buffer used by the trace visualisation utility. */
static char pcWriteBuffer[ mainDEBUG_LOG_BUFFER_SIZE ];

/*-----------------------------------------------------------*/
short main( void )
{
	/* Initialise hardware and utilities. */
	vParTestInitialise();
	vPrintInitialise();
	prvInitLED();

	/* CREATE ALL THE DEMO APPLICATION TASKS. */

	vStartComTestTasks( mainCOM_TEST_PRIORITY, serCOM2, ser38400 );
	vStartIntegerMathTasks( tskIDLE_PRIORITY );
	vStartPolledQueueTasks( mainQUEUE_POLL_PRIORITY );
	vStartBlockingQueueTasks( mainQUEUE_BLOCK_PRIORITY );
	vStartLEDFlashTasks( mainLED_TASK_PRIORITY );
	vStartSemaphoreTasks( mainSEMAPHORE_TASK_PRIORITY );

	/* Create the "Print" task as described at the top of the file. */
	xTaskCreate( vErrorChecks, "Print", mainPRINT_STACK_SIZE, NULL, mainPRINT_TASK_PRIORITY, NULL );

	/* This task has to be created last as it keeps account of the number of tasks
	it expects to see running. */
	vCreateSuicidalTasks( mainCREATOR_TASK_PRIORITY );

	/* Set the scheduler running.  This function will not return unless a task
	calls vTaskEndScheduler(). */
	vTaskStartScheduler();

	return 1;
}
/*-----------------------------------------------------------*/

static void vErrorChecks( void *pvParameters )
{
portTickType xExpectedWakeTime;
const portTickType xPrintRate = ( portTickType ) 5000 / portTICK_RATE_MS;
const long lMaxAllowableTimeDifference = ( long ) 0;
portTickType xWakeTime;
long lTimeDifference;
const char *pcReceivedMessage;
const char * const pcTaskBlockedTooLongMsg = "Print task blocked too long!\r\n";

	/* Stop warnings. */
    ( void ) pvParameters;

	/* Loop continuously, blocking, then checking all the other tasks are still
	running, before blocking once again.  This task blocks on the queue of messages
	that require displaying so will wake either by its time out expiring, or a
	message becoming available. */
	for( ;; )
	{
		/* Calculate the time we will unblock if no messages are received
		on the queue.  This is used to check that we have not blocked for too long. */
		xExpectedWakeTime = xTaskGetTickCount();
		xExpectedWakeTime += xPrintRate;

		/* Block waiting for either a time out or a message to be posted that
		required displaying. */
		pcReceivedMessage = pcPrintGetNextMessage( xPrintRate );

		/* Was a message received? */
		if( pcReceivedMessage == NULL )
		{
			/* A message was not received so we timed out, did we unblock at the
			expected time? */
			xWakeTime = xTaskGetTickCount();

			/* Calculate the difference between the time we unblocked and the
			time we should have unblocked. */
			if( xWakeTime > xExpectedWakeTime )
			{
				lTimeDifference = ( long ) ( xWakeTime - xExpectedWakeTime );
			}
			else
			{
				lTimeDifference = ( long ) ( xExpectedWakeTime - xWakeTime );
			}

			if( lTimeDifference > lMaxAllowableTimeDifference )
			{
				/* We blocked too long - create a message that will get
				printed out the next time around. */
				vPrintDisplayMessage( &pcTaskBlockedTooLongMsg );
			}

			/* Check the other tasks are still running, just in case. */
			prvCheckOtherTasksAreStillRunning();
		}
		else
		{
			/* We unblocked due to a message becoming available.  Send the message
			for printing. */
			vDisplayMessage( pcReceivedMessage );
		}

		/* Key presses are used to invoke the trace visualisation utility, or
		end the program. */
		prvCheckForKeyPresses();
	}
} /*lint !e715 !e818 pvParameters is not used but all task functions must take this form. */
/*-----------------------------------------------------------*/

static void	 prvCheckForKeyPresses( void )
{
	#ifdef USE_STDIO

	short sIn;

	
		taskENTER_CRITICAL();
			sIn = kbhit();
		taskEXIT_CRITICAL();

		if( sIn )
		{
			unsigned long ulBufferLength;

			/* Key presses can be used to start/stop the trace utility, or end the
			program. */
			sIn = getch();
			switch( sIn )
			{
				/* Only define keys for turning on and off the trace if the trace
				is being used. */
				#if configUSE_TRACE_FACILITY == 1
					case 't' :	vTaskList( pcWriteBuffer );
								vWriteMessageToDisk( pcWriteBuffer );
								break;

					case 's' :	vTaskStartTrace( pcWriteBuffer, mainDEBUG_LOG_BUFFER_SIZE );
								break;

					case 'e' :	ulBufferLength = ulTaskEndTrace();
								vWriteBufferToDisk( pcWriteBuffer, ulBufferLength );
								break;
				#endif

				default  :	vTaskEndScheduler();
							break;
			}
		}

	#else
		( void ) pcWriteBuffer;
	#endif
}
/*-----------------------------------------------------------*/

static void prvCheckOtherTasksAreStillRunning( void )
{
short sErrorHasOccurred = pdFALSE;

	if( xAreComTestTasksStillRunning() != pdTRUE )
	{
		vDisplayMessage( "Com test count unchanged!\r\n" );
		sErrorHasOccurred = pdTRUE;
	}

	if( xAreIntegerMathsTaskStillRunning() != pdTRUE )
	{
		vDisplayMessage( "Integer maths task count unchanged!\r\n" );
		sErrorHasOccurred = pdTRUE;
	}

	if( xAreBlockingQueuesStillRunning() != pdTRUE )
	{
		vDisplayMessage( "Blocking queues count unchanged!\r\n" );
		sErrorHasOccurred = pdTRUE;
	}

	if( xArePollingQueuesStillRunning() != pdTRUE )
	{
		vDisplayMessage( "Polling queue count unchanged!\r\n" );
		sErrorHasOccurred = pdTRUE;
	}

	if( xIsCreateTaskStillRunning() != pdTRUE )
	{
		vDisplayMessage( "Incorrect number of tasks running!\r\n" );
		sErrorHasOccurred = pdTRUE;
	}

	if( xAreSemaphoreTasksStillRunning() != pdTRUE )
	{
		vDisplayMessage( "Semaphore take count unchanged!\r\n" );
		sErrorHasOccurred = pdTRUE;
	}

	if( sErrorHasOccurred == pdFALSE )
	{
		vDisplayMessage( "OK " );
		/* Toggle the LED if everything is okay so we know if an error occurs even if not
		using console IO. */
		prvToggleLED();
	}
	else
	{
		for( ;; )
		{
			/* An error has occurred in one of the tasks.  Don't go any further and
			flash the LED rapidly in case console IO is not being used. */
			prvToggleLED();
			vTaskDelay( mainERROR_FLASH_RATE );
		}
	}
}
/*-----------------------------------------------------------*/

static void prvInitLED( void )
{
unsigned short usPortDirection;
const unsigned short usLEDOut = 0x400;

	/* Set the LED bit to an output. */

	usPortDirection = inpw( mainLED_REG_DIR );
	usPortDirection &= ~usLEDOut;
	outpw( mainLED_REG_DIR, usPortDirection );
}
/*-----------------------------------------------------------*/

static void prvToggleLED( void )
{
static short sLED = pdTRUE;
unsigned short usLEDState;
const unsigned short usLEDBit = 0x400;

	/* Flip the state of the LED. */
	usLEDState = inpw( mainLED_REG );
	if( sLED )
	{
		usLEDState &= ~usLEDBit;
	}
	else
	{
		usLEDState |= usLEDBit;
	}
	outpw( mainLED_REG, usLEDState );

	sLED = !sLED;
}


