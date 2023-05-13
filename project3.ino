#include "scheduler.h"

TaskHandle_t xHandle1 = NULL;
TaskHandle_t xHandle2 = NULL;
TaskHandle_t xHandle3 = NULL;
TaskHandle_t xHandle4 = NULL;


// the loop function runs over and over again forever
void loop() {}


static void testFunc1( void *pvParameters )
{
	(void) pvParameters;
	volatile int i,a;
	for( i = 0; i < 10000; i++ )
	{
		a = 1 + i*i*i*i;
	}	

}

static void testFunc2( void *pvParameters )
{ 
	(void) pvParameters;	
	volatile int i, a;	
	for(i = 0; i < 20000; i++ )
	{
		a = 1 + a * a * i;
	}	
}

static void testFunc3( void *pvParameters )
{
	(void) pvParameters;
	volatile int i,a;
	for( i = 0; i < 15000; i++ )
	{
		a = 1 + i*i*i*i;
	}	
}

static void testFunc4( void *pvParameters )
{ 
	(void) pvParameters;	
	volatile int i, a;	
	for(i = 0; i < 30000; i++ )
	{
		a = 1 + a * a * i;
	}	
}

int main( void )
{
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }
	char c1 = 'a';
	char c2 = 'b';			
	char c3 = 'c';
	char c4 = 'd';

	vSchedulerInit();

  // // TASK SET 1
  //Uncomment below 4 lines for task set 1

	// vSchedulerPeriodicTaskCreate(testFunc1, "t1", configMINIMAL_STACK_SIZE, &c1, 1, &xHandle1, pdMS_TO_TICKS(0), pdMS_TO_TICKS(400), pdMS_TO_TICKS(100), pdMS_TO_TICKS(400));
	// vSchedulerPeriodicTaskCreate(testFunc2, "t2", configMINIMAL_STACK_SIZE, &c2, 2, &xHandle2, pdMS_TO_TICKS(0), pdMS_TO_TICKS(800), pdMS_TO_TICKS(200), pdMS_TO_TICKS(700));
  // vSchedulerPeriodicTaskCreate(testFunc3, "t3", configMINIMAL_STACK_SIZE, &c3, 3, &xHandle3, pdMS_TO_TICKS(0), pdMS_TO_TICKS(1000), pdMS_TO_TICKS(150), pdMS_TO_TICKS(1000));
	// vSchedulerPeriodicTaskCreate(testFunc4, "t4", configMINIMAL_STACK_SIZE, &c4, 4, &xHandle4, pdMS_TO_TICKS(0), pdMS_TO_TICKS(5000), pdMS_TO_TICKS(300), pdMS_TO_TICKS(5000));

  // // TASK SET 2
  //Uncomment below 4 lines for task set 2

	vSchedulerPeriodicTaskCreate(testFunc1, "t1", configMINIMAL_STACK_SIZE, &c1, 1, &xHandle1, pdMS_TO_TICKS(0), pdMS_TO_TICKS(400), pdMS_TO_TICKS(100), pdMS_TO_TICKS(400));
	vSchedulerPeriodicTaskCreate(testFunc2, "t2", configMINIMAL_STACK_SIZE, &c2, 2, &xHandle2, pdMS_TO_TICKS(0), pdMS_TO_TICKS(500), pdMS_TO_TICKS(150), pdMS_TO_TICKS(200));
  vSchedulerPeriodicTaskCreate(testFunc3, "t3", configMINIMAL_STACK_SIZE, &c3, 3, &xHandle3, pdMS_TO_TICKS(0), pdMS_TO_TICKS(800), pdMS_TO_TICKS(200), pdMS_TO_TICKS(700));
	vSchedulerPeriodicTaskCreate(testFunc4, "t4", configMINIMAL_STACK_SIZE, &c4, 4, &xHandle4, pdMS_TO_TICKS(0), pdMS_TO_TICKS(1000), pdMS_TO_TICKS(150), pdMS_TO_TICKS(1000));

	vSchedulerStart();

	/* If all is well, the scheduler will now be running, and the following line
	will never be reached. */
	
	for( ;; );
}

