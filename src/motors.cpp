#include "utils.h"
#include <Arduino.h>
#include "constants.h"

#include "motors.h"

using namespace Robot; 

// TODO: WORKAROUND: 
int dir1Pin = 0;
int dir2Pin = 0;
int PWM_Pin = 0;

const int wheelRadius = 5;
std::array<int, 3> wheelAngles = {60, 180, 300};


namespace Robot {
  namespace Motor {
    // TODO: Implement handling of multiple motors (all three Motors)
    void rotateSingleMotor(float normalizedRate, bool reversed, int motor) {
      // de-normalize the rate
      int PWM_Rate = normalizedRate * 255.0f;

      // make sure that both direktion Pins and the PWM are set to zero before applying settings
      // This is to prevent shortages and similar errors

      digitalWrite(5, LOW);
      digitalWrite(4, LOW);

      // wait for a very short period, for extra safety
      // TODO: IF PERFORMANCE CRITICAL, CHANGE/REMOVE
      delay(2);

      // now apply direction settings and set the PWM Pin:
      if (reversed) {
        digitalWrite(5, LOW);
        digitalWrite(4, HIGH);
      } else {
        digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
      }

      analogWrite(6, PWM_Rate);
    }

    // Gives the speed of a single wheel using the formula '''vx * sin(θᵢ) - vy * cos(θᵢ) + ω * r'''
    float handleSingleWheel(float wheelAngle, float vx, float vy, float angularSpeed) {
      float wheelSpeed = vx * sin(wheelAngle) - vy * cos(wheelAngle) + angularSpeed * wheelRadius;
      return wheelSpeed;
    }

    // Wheel Spin indicated by {Back, Left, Right}

    void MoveRobot(float inputVector[2], float speed, float rotation) {
      /*This Function moves the Robot along the inputVector.
      speed controls the speed of which the Robot Moves,
      if speed is 0, the magnitude of the input vector will be used.
      else, the magnitude of the input vector will be fitted to the speed,
      so speed = mag(modified inputVector), while

      speed ∈ [0; 1]

      Rotation Controls the Roation of the robot with an arbitrory measurement scale.
      The output will be the speed, of which the Wheels shall move,

      output ∈ [-1; 1]

      */
      //Normalize speed in case of wrong input
      if (speed < 0.0f) {
        speed = 0.0f;
      }
      if (speed != 0.0f) {
        if (speed > 1.0f) {
          speed = 1.0f;
        }
        float scaling_factor = speed / sqrt(inputVector[0] * inputVector[0] + inputVector[1] * inputVector[1]);

        inputVector[0] = inputVector[0] * scaling_factor;
        inputVector[1] = inputVector[1] * scaling_factor;
      }

      std::array<float, 3> wheelSpeeds;

      for (int n = 0; n < 3; n++) {
        wheelSpeeds[n] = handleSingleWheel(wheelAngles[n], inputVector[0], inputVector[1], rotation);
      }

      // Normalize the wheel Speeds.

      // Find max element:
      float maxVal = -1000.0f; // Huge Val
      float minVal = 1000.0f;
      for (int n = 0; n < 3; n++) {
        if (wheelSpeeds[n] > maxVal) {
          maxVal = wheelSpeeds[n];
        }
        if (wheelSpeeds[n] < minVal) {
          minVal = wheelSpeeds[n];
        }
      }
      float extremeVal = (maxVal > -minVal) ? maxVal : -minVal;
      if (extremeVal > 1.0f) {
        for (int n = 0; n < 3; n++) {

          wheelSpeeds[n] = wheelSpeeds[n] / extremeVal;
        }
      }

      // TODO: IMPLEMENT SENDING THE VALUES TO THE MOTORS!
      // NOTE: Resolved.

      // We need to check if the rate is negative, negative PWM duty cycles would be bad.
      for (int n = 0; n < 3; n++) {
        if (wheelSpeeds[n] < 0) {
          Motor::rotateSingleMotor(-wheelSpeeds[n], true, n);
        } else {
          Motor::rotateSingleMotor(wheelSpeeds[n], false, n);
        }
      }



    };
  };
};