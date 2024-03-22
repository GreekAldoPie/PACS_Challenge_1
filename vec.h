#pragma once

#include <iostream>
#include <cmath>
#include <initializer_list>

template <int N>
struct Vec
{
    // The data of the vector
    double data[N];

    /**
     * @brief Construct a new Vec object
     */
    Vec()
    {
        for (int i = 0; i < N; i++)
        {
            data[i] = 0;
        }
    }

    /**
     * @brief Construct a new Vec object
     * 
     * @param other The vector to copy
     */
    Vec(const Vec<N> &other)
    {
        for (int i = 0; i < N; i++)
        {
            data[i] = other.data[i];
        }
    }

    /**
     * @brief Construct a new Vec object
     * 
     * @param list The list of doubles to copy to the vector
     */
    Vec(std::initializer_list<double> list)
    {
        // If the list dimension mismatches the vector dimension, throw an error
        if (list.size() != N)
        {
            throw std::invalid_argument("List dimension mismatches vector dimension");
        }
        // Copy the list to the vector
        std::copy(list.begin(), list.end(), data);
    }

    Vec<N> &operator=(const Vec<N> &other)
    {
        for (int i = 0; i < N; i++)
        {
            data[i] = other.data[i];
        }
        return *this;
    }

    Vec<N> operator+(const Vec<N> &other) const
    {
        Vec<N> result;
        for (int i = 0; i < N; i++)
        {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    Vec<N> operator-(const Vec<N> &other) const
    {
        Vec<N> result;
        for (int i = 0; i < N; i++)
        {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    Vec<N> operator*(double scalar) const
    {
        Vec<N> result;
        for (int i = 0; i < N; i++)
        {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    Vec<N> dot(const Vec<N> &other) const
    {
        Vec<N> result;
        for (int i = 0; i < N; i++)
        {
            result.data[i] = data[i] * other.data[i];
        }
        return result;
    }

    double &operator[](const int index)
    {
        return data[index];
    }

    /**
     * @brief The norm of the vector.
     * @return double 
     */
    double norm() const
    {
        double sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += data[i] * data[i];
        }
        return std::sqrt(sum);
    }
};

// Different template because the friend function is not a member function
template <int M>
std::ostream &operator<<(std::ostream &os, const Vec<M> &vec)
{
    os << "(";
    for (int i = 0; i < M; i++)
    {
        os << vec.data[i];
        if (i < M - 1)
        {
            os << ", ";
        }
    }
    os << ")";
    return os;
}