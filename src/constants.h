#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Robot {
  namespace Pins {
    // Struct for storing the pin layouts for the motors
    struct MotorPin {
      int PWM;
      int DIR_A;
      int DIR_B;
    };

    // TODO: Replace with actual Pins 
    const MotorPin MOTORPINS[3] = {{6, 5, 4}, 
                                   {6, 5, 4}, 
                                   {6, 5, 4}};



  };

  namespace Constants {
    //PLACEHOLDER
  };
};

#endif // CONSTANTS_H