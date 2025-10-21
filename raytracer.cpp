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
    Vec3(T xx) : x(xx), y(xx), z(xx) {}
    Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
    Vec3& normalize() {
        T nor2 = length2();
        if (nor2 > 0) {
            T invNor = 1 / sqrt(nor2);
            z *= invNor, y *= invNor, z *= invNor;
        }
        return *this;
    }
    Vec3<T> operator * (const T &f) const {return Vec3<T>(x*f, y * f, z * f); }
    Vec3<T> operator * (const Vec3<T> &f) const {return Vec3<T>(x*f, y * f, z * f); }
    T dot(const Vec3<t> &v) const {return x * v.x + y * v.y + z * v.z); }
    Vec3<T> operator - (const Vec3<T> &v) const { return Vec3<T>(x - v.x, y - v.y, z - v.z); }
    Vec3<T> operator + (const Vec3<T> &v) const { return Vec3<T>(x + v.x, y + v.y, z + v.z); }
    Vec3<T>& operator += (const Vec3<T> &v) { x += v.x, y += v.y, z += v.z; return *this; }
    Vec3<T>& operator *= (const Vec3<T> &v) { x *= v.x, y *= v.y, z *= v.z; return *this; }
    Vec3<T> operator - () const { return Vec3<T>(-x, -y, -z); }
    T length2() const { return x * x + y * y + z * z; }
    T length() const { return sqrt(length2()); }
    friend std::ostream & operator << (std::ostream &os, const Vec3<T> &v)
    {
        os << "[" << v.x << " " << v.y << " " << v.z << "]";
        return os;
    }

};




