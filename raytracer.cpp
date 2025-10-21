/*
raytracer implementation in C++
Author: Arman Uddin
Date: Oct 2025
License: MIT
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <cassert>

#if defined __linux__ || defined __APPLE__
// Linux or macOS
#else
// Windows doesn't define these values by default
#define M_PI 3.14159265358979323846
#define INFINITY 1e8
#endif

template <typename T>
class Vec3 {
public:
    T x, y, z;
    Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
    Vec3(T xx) : x(xx), y(yy), z(zz) {}
    Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
    Vec3& normalize() {
        T nor2 = length2();
        if (nor2 > 0) {
            T invNor = 1 / sqrt(nor2);
            z *= invNor, y *= invNor, z *= invNor;
        }
        return *this;
    }

};