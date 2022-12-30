#include <Arduino.h>
#include <ESPUI.h>
#include "FastAccelStepper.h"
#include <HardwareSerial.h>
#include <TMCStepper.h>
#include <SPI.h>
#include <Preferences.h>
#include "Memory.h"
#include "ResetButton.h"
#include "MotorControl.h"
#include "API.h"
#include "ESPUI.h"

static uint32_t previous_load_measuring_time = 0; //for timing the load measures
bool MeasuringLoadStarted = false; //the measuring process is started only when a movement command of the claw is sent via Bluetooth

int load_measures_counter = 0; //10 load measures will be averaged
unsigned long accumulated = 0; //this accumulates  the 10 load measures

void setup() {

  Serial.begin(115200);
  delay(1000);
  preferences.begin("local", false);
  load_preferences();
  setup_motors();

  setup_leds();
  API();
  ESPUIsetup();

  // Now set up tasks to run independently.
  xTaskCreatePinnedToCore(
    MotorTask //Motor Task
    ,  "MotorTask"   // A name just for humans
    ,  1024 * 4 // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  3  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL
    ,  1);


  xTaskCreatePinnedToCore(
    ButtonTask //Motor Task
    ,  "ButtonTask"   // A name just for humans
    ,  1024 * 4 // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  3  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL
    ,  0);

}


void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/


void ButtonTask(void *pvParameters)  // Motor Task
{
  (void) pvParameters;

  for (;;)
  {
    
    if (run_motor == true) 
    {
      int loadAngle = 255;
      int loadTrip = 0;
      Serial.println("Motor Running");
      delay(200); // only delay one time
          
        while(run_motor == true)
          { 
          
          loadAngle = driver.SG_RESULT();
              if (loadAngle == 0)
              {
               loadTrip++;
               loadAngle = 255;
              }
        
              if (loadTrip >= 3)
              {
               Serial.println("STALL DETECTED");
               stalled_motor = true;
               break;
              }
          }
        }

    else
    {
      vTaskDelay(1);

    }
  }
}


void MotorTask(void *pvParameters)  // Motor Task
{
  (void) pvParameters;

  for (;;)
  {

    if (run_motor == true)
    {
      Serial.println("Run Motor Function");
      move_motor();
      run_motor = false;
      stalled_motor = false; // Reset Stall flag 
      ESPUI.updateLabel(positionLabel, String(int(((float)current_position / (float)max_steps) * 100)));
      Serial.println("Motor Complete");
    }
    else if (set_zero == 1)
    {
      setZero();
      set_zero = 0;
    }
    else if (wifi_button == true)
    {
      button_change();
      wifi_button = false;
    }
    else
    {
      vTaskDelay(1);
    }
  }
}
