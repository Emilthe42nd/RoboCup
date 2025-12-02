#ifndef UTILS_H
#define UTILS_H

namespace Robot {
  namespace Helper {
    
    // Convert angle from radians to degrees
    float convertToDegrees(float& angleRad);
    
    // Convert angle from degrees to radians
    float convertToRad(float& angleDegrees);
    
    // Calculate magnitude of a 2D vector
    float getMagnitude2D(float Vector[2]);
    
    // Calculate magnitude of a 3D vector
    float getMagnitude3D(float Vector[3]);
    
    // Calculate scalar (dot) product of two 2D vectors
    float scalarProduct(float Vector1[2], float Vector2[2]);
    
    // Calculate angle between two 2D vectors
    float getVectorAngle(float Vector1[2], float Vector2[2]);
    
  }
}

#endif // UTILS_H
