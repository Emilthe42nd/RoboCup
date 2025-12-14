#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <Adafruit_VL6180X.h>
#include <utility/imumaths.h>
#include <array>

#include "constants.h"
#include "sensors.h"

using namespace Robot;

Adafruit_BNO055 bno = Adafruit_BNO055(55);
Adafruit_VL6180X vl = Adafruit_VL6180X();


namespace Robot {
  namespace Sensors {
    /*
    Pass distances by references, to read with:
    Sensors::readDistance(myvar)
    instead of
    myvar = Sensors::readDistance()
    */ 
   void initSensors() {
    // Init the ToF sensor:
    if (!vl.begin()) {
      Serial.println("ToF Init Failed!");
    }
   }

  
    void readDistance(std::array<int, 4>& distances) {
      // TODO: look at the datasheet for how to get the sensor data
    }

    void readAbsoluteOrientation(float& angle) {
      /*
      The BNO005 gives out euler angles in all 3 axis. This code should do it. 
      We need to also add calibration.
      We could TECNICALLY get the position data for sanity-checking or as a
      backup if the distance sensors fail
      */


      // This is the code for the sensor events - easy
      // TODO: If the function fails (sensor not connected, or whatever)
      // TODO: Test if that throws an error
      // We need to catch that nontheless, and mark the data as damaged.
      sensors_event_t event; 
      bno.getEvent(&event);


      // I'm not quite sure about the .z, but the rest should be right
      imu::Vector<3> euler = bno.getVector(Adafruit_BNO055::VECTOR_EULER);
      // Thats how you extract the z
      // euler.z()
      angle = euler.z();

    }

    // Reads the Distance of the Time-of-Flight sensor, again, using float& for easier acces.
    // Uses I2C
    void readToF(float& distance, bool& dataBroken) {
      // This is the actual Line for reading the distance:
      distance = vl.readRange();

      // Check for errors, 0 or > 200 means something is not right
      if (distance == 0 || distance > 200) {
        // Mark the data as broken
        dataBroken = true;

        // DEBUG: Deduce the error
        uint8_t status = vl.readRangeStatus();

        if ((status >= VL6180X_ERROR_SYSERR_1) && (status <= VL6180X_ERROR_SYSERR_5)) {
          Serial.println("System error");
        }
        else if (status == VL6180X_ERROR_ECEFAIL) {
          Serial.println("ECE failure");
        }
        else if (status == VL6180X_ERROR_NOCONVERGE) {
          Serial.println("No convergence");
        }
        else if (status == VL6180X_ERROR_RANGEIGNORE) {
          Serial.println("Ignoring range");
        }
        else if (status == VL6180X_ERROR_SNR) {
          Serial.println("Signal/Noise error");
        }
        else if (status == VL6180X_ERROR_RAWUFLOW) {
          Serial.println("Raw reading underflow");
        }
        else if (status == VL6180X_ERROR_RAWOFLOW) {
          Serial.println("Raw reading overflow");
        }
        else if (status == VL6180X_ERROR_RANGEUFLOW) {
          Serial.println("Range reading underflow");
        }
        else if (status == VL6180X_ERROR_RANGEOFLOW) {
          Serial.println("Range reading overflow");
        }
      }
      dataBroken = false;
    }

    void readDistanceSensor(int sensor, int& distance) {
      digitalWrite(PINS::DISTANCEPINS[sensor].TRIG, LOW);
      delayMicroseconds(2);
      digitalWrite(PINS::DISTANCEPINS[sensor].TRIG,  HIGH);
      delayMicroseconds(10);
      digitalWrite(PINS::DISTANCEPINS[sensor].TRIG, LOW);

      const unsigned long duration= pulseIn(PINS::DISTANCEPINS[sensor].ECHO, HIGH);
      int distance= duration/29/2;
      if (duration==0){
        Serial.println("Warning: no pulse from sensor");
      }
    }


    // Reads the IR Seeker using I2C
    void readIrSeeker(int& direction, int& strength) {
      // Ensure Wire is initialized (should already be done in setup, but safe to call multiple times)
      Wire.begin();
      
      // Get the raw data
      // This shitty sensor only gives Strogest sensor (in number from 1-12) and signal strength
      uint8_t bytesReceived = Wire.requestFrom(0x10 / 2, 2);
      delayMicroseconds(3);
      // Read the bytes if available
      if (bytesReceived >= 2) {
        direction = Wire.read(); // direction is the first byte    
        strength = Wire.read(); // smaller number the closer the ball
      } else {
        // If we didn't get 2 bytes, set default values
        direction = 0;
        strength = 0;
      }
      delay(250);
    }

  };
};