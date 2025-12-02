#ifndef SENSORS_H
#define SENSORS_H
#include <array>

namespace Robot {
  namespace Sensors {

    // reads the Distance of one of the distance sensors
    void readDistance(std::array<int, 4>& distances);

    // reads the z rotation of the ABS
    void readAbsoluteOrientation(float& angle);

  };
};

#endif // SENSORS_H