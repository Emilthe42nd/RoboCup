#ifndef SENSORS_H
#define SENSORS_H
#include <array>

namespace Robot {
  namespace Sensors {

    // reads the Distance of one of the distance sensors
    void readDistance(std::array<int, 4>& distances);

    // reads the z rotation of the ABS
    void readAbsoluteOrientation(float& angle);


    // reads the (preprocessed) main sensor and signal strength from the IR Seeker
    void readIrSeeker(int& direction, int& strength);
  };
};

#endif // SENSORS_H