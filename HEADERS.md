# Header Files in C/C++

## What are Header Files?

Header files (`.h` or `.hpp`) contain declarations of functions, classes, variables, and constants that you want to share across multiple source files (`.cpp`). They act as an interface, telling other parts of your code what's available without including the actual implementation.

## Why Use Header Files?

1. **Code Organization**: Separate interface (what) from implementation (how)
2. **Reusability**: Share declarations across multiple source files
3. **Compilation Speed**: Only declarations need to be parsed by files that include them
4. **Maintainability**: Changes to implementation don't require recompiling all dependent files

## Include Guards

### The Problem

Without protection, if a header file is included multiple times (directly or indirectly), the compiler will see duplicate declarations and throw errors.

### The Solution: Include Guards

Include guards prevent a header file from being processed more than once during compilation.

### Traditional Method (Preprocessor Guards)

```cpp
#ifndef FILENAME_H
#define FILENAME_H

// Your declarations here

#endif // FILENAME_H
```

**How it works:**
1. `#ifndef FILENAME_H` - "If FILENAME_H is not defined..."
2. `#define FILENAME_H` - "...then define it now"
3. Your code goes here
4. `#endif` - End of the conditional block

If the file is included again, `FILENAME_H` is already defined, so the entire block is skipped.

### Modern Alternative: `#pragma once`

```cpp
#pragma once

// Your declarations here
```

This is simpler and supported by all modern compilers (GCC, Clang, MSVC). However, it's technically non-standard, though widely adopted.

## Naming Convention for Guards

Use uppercase with underscores, typically:
- `FILENAME_H` or `FILENAME_HPP`
- `PROJECT_FILENAME_H` (for larger projects)
- `NAMESPACE_FILENAME_H` (to match your code structure)

**Example:**
- `utils.h` → `UTILS_H`
- `motors.cpp` → `MOTORS_H`
- `rgbLight.cpp` → `RGB_LIGHT_H` or `RGBLIGHT_H`

## Creating Your Own Header File

### Step-by-Step Process

1. **Create the header file** with the same base name as your `.cpp` file
   - `myfile.cpp` → `myfile.h`

2. **Add include guards** at the very top and bottom

3. **Include necessary dependencies** that your declarations need

4. **Declare your functions, classes, and constants**
   - Function declarations (prototypes) without the body
   - Class definitions
   - Extern variable declarations
   - Constants and macros

5. **Add comments** to explain what each function does

### Example: Creating a Header for `motors.cpp`

**motors.h:**
```cpp
#ifndef MOTORS_H
#define MOTORS_H

namespace Robot {
  namespace Motors {
    
    // Initialize motor pins and settings
    void init();
    
    // Set motor speed (-255 to 255)
    void setSpeed(int leftSpeed, int rightSpeed);
    
    // Stop all motors
    void stop();
    
    // Move forward at given speed
    void forward(int speed);
    
    // Move backward at given speed
    void backward(int speed);
    
  }
}

#endif // MOTORS_H
```

**motors.cpp:**
```cpp
#include "motors.h"
#include <Arduino.h>

namespace Robot {
  namespace Motors {
    
    void init() {
      // Implementation here
    }
    
    void setSpeed(int leftSpeed, int rightSpeed) {
      // Implementation here
    }
    
    // ... other implementations
  }
}
```

## What Goes in a Header vs Source File?

### Header File (.h)
- Function declarations (prototypes)
- Class/struct definitions
- Template definitions (must be in header!)
- Inline functions
- Constant declarations (`extern const` or `constexpr`)
- Macro definitions
- Type definitions (`typedef`, `using`)

### Source File (.cpp)
- Function implementations
- Global variable definitions
- Static variables
- Non-inline member function implementations

## Common Mistakes to Avoid

1. **Don't put function implementations in headers** (unless inline or template)
   - This causes "multiple definition" errors

2. **Don't forget include guards**
   - Leads to redefinition errors

3. **Don't use `using namespace` in headers**
   - Pollutes the namespace for everyone who includes your header

4. **Don't include unnecessary headers**
   - Slows down compilation
   - Use forward declarations when possible

5. **Don't define variables in headers** (unless `extern`, `static`, or `constexpr`)
   - Each file that includes it will create a separate copy

## Best Practices

1. **Always use include guards** (or `#pragma once`)

2. **Include your own header first** in the `.cpp` file
   ```cpp
   #include "myfile.h"  // This first!
   #include <Arduino.h>
   #include <other_headers.h>
   ```

3. **Use forward declarations** when possible to reduce dependencies

4. **Keep headers minimal** - only include what's necessary

5. **Document your interface** with comments in the header

6. **Match names**: `utils.cpp` should have `utils.h`

7. **Use relative paths** for your own headers: `#include "utils.h"`

8. **Use angle brackets** for system/library headers: `#include <Arduino.h>`

## Example: Complete Header File Template

```cpp
#ifndef MY_MODULE_H
#define MY_MODULE_H

// Include only necessary system headers
#include <Arduino.h>

// Forward declarations (if needed)
class SomeClass;

// Constants
#define MY_CONSTANT 42

namespace MyNamespace {
  
  // Function declarations
  void initialize();
  int calculate(int x, int y);
  
  // Class declaration
  class MyClass {
  public:
    MyClass();
    void doSomething();
    
  private:
    int value;
  };
  
}

#endif // MY_MODULE_H
```

## Quick Reference

| Task | Syntax |
|------|--------|
| Start guard | `#ifndef FILENAME_H` |
| Define guard | `#define FILENAME_H` |
| End guard | `#endif // FILENAME_H` |
| Modern guard | `#pragma once` |
| Include own header | `#include "myfile.h"` |
| Include system header | `#include <Arduino.h>` |
| Declare function | `void myFunction(int param);` |
| Declare extern variable | `extern int myVariable;` |

---

**Remember:** Header files are about *declarations* (telling the compiler what exists), while source files are about *definitions* (telling the compiler how it works).
