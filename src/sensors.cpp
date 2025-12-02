#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <array>

#include "sensors.h"

using namespace Robot;

Adafruit_BNO055 bno = Adafruit_BNO055(55);


namespace Robot {
  namespace Sensors {
    /*
    Pass distances by references, to read with:
    Sensors::readDistance(myvar)
    instead of
    myvar = Sensors::readDistance()
    */ 

  
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
  };
};