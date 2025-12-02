#include <cmath>
#include "utils.h"


using namespace Robot;

#define PI 3.14159

namespace Robot {
  namespace Helper {

    float convertToDegrees(float& angleRad) {
      return angleRad * (180.0f / PI);
    }

    float convertToRad(float& angleDegrees) {
      return angleDegrees * (PI / 180.0f);
    }

    float getMagnitude2D(float Vector[2]) {

      // Maybe remove sqareSum declaration if PROGMEM is tight.
      // NOTE: yes, this is the easiest way to sqare a number in c++
      // TODO: If it is more readable, maybe add a helper::sqare() function

      float sqareSum = Vector[0] * Vector[0] + Vector[1] * Vector[1];
      return sqrt(sqareSum);
    }

    float getMagnitude3D(float Vector[3]) {
      float sqareSum = Vector[0] * Vector[0] + Vector[1] * Vector[1] + Vector[2] * Vector[2];
      return sqrt(sqareSum);
    }

    float scalarProduct(float Vector1[2], float Vector2[2]) {
      return Vector1[0] * Vector2[0] + Vector1[1] * Vector2[1];
    }

    float getVectorAngle(float Vector1[2], float Vector2[2]) {
      float angleDeg = acos(scalarProduct(Vector1, Vector2) / (getMagnitude2D(Vector1) * getMagnitude2D(Vector2)));
      return angleDeg;
    }
  }
}