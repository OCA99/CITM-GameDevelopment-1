#include <iostream>
#include <string>
#include <cmath>

template<class T> class vec3 {
  private:
    T x;
    T y;
    T z;
  
  public:
    vec3() {
      x = 0.0f;
      y = 0.0f;
      z = 0.0f;
    }

    vec3(const T& _x, const T& _y, const T& _z) {
      x = _x;
      y = _y;
      z = _z;
    }

    vec3(const vec3<T>& v) {
      x = v.x;
      y = v.y;
      z = v.z;
    }

    void setX(const T& _x) {
      x = _x;
    }

    void setY(const T& _y) {
      y = _y;
    }

    void setZ(const T& _z) {
      z = _z;
    }

    T getX() {
      return x;
    }

    T getY() {
      return y;
    }

    T getZ() {
      return z;
    }
    
    vec3<T> operator+() {
        return vec3<T>(*this);  
    }
    
    vec3<T> operator+(const vec3<T>& other) {
        return vec3<T>(this->x + other.x, this->y + other.y, this->z + other.z);   
    }
    
    vec3<T> operator-() {
        return vec3<T>(-this->x, -this->y, -this->z);    
    }
    
    vec3<T> operator-(const vec3<T>& other) {
        return vec3<T>(this->x - other.x, this->y - other.y, this->z - other.z);   
    }
    
    vec3<T>& operator+=(const vec3<T>& other) {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        return *this;
    }
    
    vec3<T>& operator-=(const vec3<T>& other) {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        return *this;
    }
    
    vec3<T>& operator=(const vec3<T>& other) {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        return *this;
    }
    
    bool operator==(const vec3<T>& other) {
        return this->x == other.x && this->y == other.y && this->z == other.z;
    }
    
    double Length() {
        return std::sqrt(this->x * this->x + this->y * this->y + this->y * this->y);
    }
    
    vec3<double>& Normalize() {
        double length = Length();
        vec3<double>* res = new vec3<double>();
        res->setX(this->x / length);
        res->setY(this->y / length);
        res->setZ(this->z / length);
        return *res;
    }

    static vec3<T> Zero() {
      return vec3<T>();
    }
    
    bool isZero() {
        return this->x == 0 && this->y == 0 && this->z == 0;
    }
    
    double DistanceTo(vec3<T> other) {
        vec3<T> diff = *this - other;
        return diff.Length();
    }
    
    std::string toString() {
        return "(" + std::to_string(this->x) + "," + std::to_string(this->y) + "," + std::to_string(this->z) + ")";
    }
};

typedef vec3<int> vec3i;
typedef vec3<float> vec3f;
typedef vec3<double> vec3d;
