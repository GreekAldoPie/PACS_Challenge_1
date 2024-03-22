# PACS_Challenge_1

# Gradient Descent Library for C++

This repository contains a C++ implementation of the gradient descent algorithm designed for optimizing functions of two variables. The code is structured into different components for easy integration and use. It includes a custom vector class, a function struct to encapsulate mathematical functions and their gradients, a minimizer class for the gradient descent algorithm, and a structure for holding gradient descent hyperparameters.

## Features

- **Vec Class**: Custom vector class for mathematical operations.
- **Function Structure**: Template structure for mathematical functions and gradients.
- **Minimizer Class**: Implements the gradient descent algorithm with Armijo rule for step size adjustment.
- **GradientDescentHp Structure**: Contains hyperparameters for the gradient descent algorithm.

## Installation

To use this library, clone the repository into your project folder:

```bash
git clone https://your-repository-link-here.git
```

Ensure your compiler supports C++11 or newer versions as the code utilizes modern C++ features.

## Usage

1. Include the header files in your C++ source file:

   ```cpp
   #include "vec.h"
   #include "function.h"
   #include "descent.h"
   ```

2. Define your function and its gradient. For a function of two variables, use `Function<2>`:

   ```cpp
   Function<2> myFunction(
       [](Vec<2> x) { return x[0] * x[1] + 4 * std::pow(x[0], 4) + std::pow(x[1], 2) + 3 * x[0]; },
       [](Vec<2> x) { return Vec<2>({x[1] + 16 * std::pow(x[0], 3) + 3, x[0] + 2 * x[1]}); }
   );
   ```

3. Initialize the gradient descent parameters and create a `Minimizer` object:

   ```cpp
   GradientDescentHp<2> params = {Vec<2>({0,0}), 1e-6, 1e-6, 0.5, 0.0001, 1000};
   Minimizer<2> minimizer(myFunction, params);
   ```

4. Execute the minimization and obtain the result:

   ```cpp
   Vec<2> minimum = minimizer.minimize();
   std::cout << "Minimum found at: " << minimum << std::endl;
   ```

This example demonstrates the basic workflow with a predefined function. Modify the function definition and parameters according to your needs.

