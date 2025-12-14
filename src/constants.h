#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Robot {
  namespace PINS {
    // Struct for storing the pin layouts for the motors
    struct MotorPin {
      int PWM;
      int DIR_A;
      int DIR_B;
    };

    // TODO: Replace with actual Pins 
    constexpr MotorPin MOTORPINS[3] = {{6, 5, 4}, 
                                   {6, 5, 4}, 
                                   {6, 5, 4}};


    struct DistancePin {
      int TRIG;
      int ECHO;
    };

    // TODO: CHANGE TO ACTUAL VALUES
    constexpr DistancePin DISTANCEPINS[4] = {{1, 2},
                                         {1, 2},
                                         {1, 2},
                                         {1, 2}};

  };

  namespace Constants {
    //PLACEHOLDER
  };
};

#endif // CONSTANTS_H