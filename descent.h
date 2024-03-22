#pragma once

#include <iostream>
#include "cmath"
#include "function.h"

/**
 * @brief The GradientDescentHp struct, which aggregates the parameters for the gradient descent algorithm.
 */
template <int N>
struct GradientDescentHp
{
    Vec<N> x;  // initial point
    double e_s; // control on the step length
    double e_r; // control on the residual
    double armijo_alpha0; // initial step length for the Armijo rule
    double armijo_sigma; // parameter for the Armijo rule
    int k_max;  // maximum number of iterations
};

// The class that will implement the gradient descent algorithm
template <int N>
class Minimizer
{
public:
    // The function to minimize
    Function<N> f; // () is the function, .grad is the gradient
    // The initial point
    Vec<N> x;
    // The parameters for the gradient descent algorithm
    GradientDescentHp<N> hp;
    // The iteration count
    int k;

    // Constructor
    Minimizer(Function<N> f, GradientDescentHp<N> hp) : f(f), hp(hp) {}

    // The armijo rule
    inline double armijo(double alpha0, Vec<N> x_k, Vec<N> grad_k)
    {
        constexpr double rho = 0.5;
        while (f(x_k - grad_k * alpha0) > f(x_k) - hp.armijo_sigma * alpha0 * grad_k.norm())
        {
            alpha0 *= rho;
        }
        return alpha0;
    }

    // The function that will minimize the function f
    Vec<N> minimize()
    {
        // Initialize the point
        Vec<N> x_k = hp.x;
        // Initialize the iteration counter
        k = 0;
        // Initialize the gradient
        Vec<N> grad_k;
        // Initialize the residual
        double r = grad_k.norm();
        // Initialize the step length
        double alpha = hp.armijo_alpha0;
        // Initialize the residual control
        double e_r = hp.e_r;
        // Initialize the step length control
        double e_s = hp.e_s;
        // Initialize the maximum number of iterations
        int k_max = hp.k_max;

        // While the residual is greater than the control and the step length is greater than the control
        while (k++ < k_max)
        {
            // Get gradient
            grad_k = f.grad(x_k);

            // Get step length
            alpha = armijo(alpha, x_k, grad_k);
            
            // Check the two stopping criteria
            Vec<N> step = grad_k * alpha;

            // Update the point
            x_k = x_k - step;

            // Residual
            r = grad_k.norm();

            // Check the two stopping criteria
            if (r < e_r || step.norm() < e_s)
            {
                break;
            }
        }

        // Return the point
        return x_k;
    }
    
};