#include <Arduino.h>

using namespace Robot;

namespace Robot {
  namespace rgbLight {

    void lightRGB(bool red, bool green, bool blue) {
      /*
      Lights the tiny RGB on the Board
      */

      if (red) {
        digitalWrite(LEDR, HIGH);
      } else {
        digitalWrite(LEDR, LOW);
      }


      if (green) {
        digitalWrite(LEDG, HIGH);
      } else {
        digitalWrite(LEDG, LOW);
      }


      if (blue) {
        digitalWrite(LEDB, HIGH);
      } else {
        digitalWrite(LEDB, LOW);
      }
    
    }

  }; 
};