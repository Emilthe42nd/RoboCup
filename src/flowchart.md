# Robot Behavior Pipeline

## 1. Acquire Sensor Data
- Collect data from all relevant sensors:
  - IR Ring
  - Distance sensors 
  - ToF (Time-of-Flight) sensor

## 2. Cache Necessary Data
- Store essential sensor readings and computed values for quick access.
- Maintain a buffer of recent data for smoothing and filtering.

## 3. Precompute Key Values
- Precompute trigonometric values for efficiency:
  - cos(θ), sin(θ), and possibly tan(θ)
- Update:
  - Robot’s position and orientation.
  - Estimated ball position using previous cached data (interpolation or prediction).

## 4. Determine Current Phase of Play
- Identify tactical state:
  - Attack (we have the ball)
  - Getting the Ball
  - Defense (opponent has the ball, That'll be hard)

## 5. Compute Desired Movement
- Decide movement goal:
  - Drive toward the ball.
  - Navigate toward the goal.
  - Loop or circle around the ball.

## 6. Execute Movement
- Send appropriate commands to motors or actuators.
- Continuously adjust based on live sensor feedback.
