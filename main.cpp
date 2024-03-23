#include "function.h"
#include "descent.h"
#include <iostream>
#include <cmath>

int main(){

    // Define a function and its gradient
    Function<2> f(
        [](Vec<2> x)
        { 
            return x[0] * x[1] + 4 * std::pow(x[0], 4) + std::pow(x[1], 2) + 3 * x[0];
        },
        [](Vec<2> x)
        { 
            Vec<2> grad = {
                x[1] + 16 * std::pow(x[0], 3) + 3,
                x[0] + 2 * x[1]
            };
            return grad;
        });

    // Define the parameters for the gradient descent algorithm
    GradientDescentHp<2> hp = {
        Vec<2>({0,0}),
        1e-6, 
        1e-6, 
        .5,
        0.0001,
        1000
    };

    // Create a minimizer object
    Minimizer<2> minimizer(f, hp);

    // Run the gradient descent algorithm
    Vec<2> x_min = minimizer.minimize();

    // Print the result
    std::cout << "Minimum found at: " << x_min << " in " << minimizer.k << " iterations with value " << f(x_min) << std::endl;

    return 0;
}