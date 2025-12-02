#ifndef MOTORS_H
#define MOTORS_H

namespace Robot {
  namespace Motor {

    // Little helper function meant to not be used externally
    void rotateSingleMotor(float normalizedRate, bool reversed);

    // Another helper funcion important for the moveRobot function
    float handleSingleWheel(float wheelAngle, float vx, float vy, float angularSpeed);

    // Function that moves the Robot along the input vector with a optional speed and rotation
    void MoveRobot(float inputVector[2], float speed, float rotation);

  };
};

#endif //MOTORS_H