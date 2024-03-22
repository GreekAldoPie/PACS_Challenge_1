#pragma once

#include <iostream>
#include "vec.h"
#include "cmath"
#include "functional"

/**
 * @brief The Function struct contains a function and its gradient.
 * @tparam N The dimension of the function.
 * @param fn The function.
 * @param grad_fn The gradient function.
 */
template <int N>
struct Function {
    // The function to minimize takes a Vec<N> and returns a double.
    std::function<double(Vec<N>)> fn;
    // The gradient of the function takes a Vec<N> and returns a Vec<N>.
    std::function<Vec<N>(Vec<N>)> grad_fn;
    // Constructor
    Function(std::function<double(Vec<N>)> fn, std::function<Vec<N>(Vec<N>)> grad_fn)
        : fn(fn), grad_fn(grad_fn) {}
    // A function to get the value of the function at a point
    inline double operator()(Vec<N> x) const {
        return fn(x);
    }
    // A function to get the gradient of the function at a point
    inline Vec<N> grad(Vec<N> x) const {
        return grad_fn(x);
    }
};