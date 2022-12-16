#ifndef Vector3_H_
#define Vector3_H_

#include <cmath>
#include <iostream>
#include <vector>



/// @brief A class built solely to handle 3D vector mathematics.
class Vector3 {
 public:
  float x = 0;  //!< x-coordinate
  float y = 0;  //!< y-coordinate
  float z = 0;  //!< z-coordinate

  /**
   * @brief Default constructor.
   */
  Vector3();

  /**
   * @brief Parameter constructor.
   *
   * @param[in] x_ x-coordinate
   * @param[in] y_ y-coordinate
   * @param[in] z_ z-coordinate
   */
  Vector3(float x_, float y_, float z_);

  Vector3(std::vector<float> v) {
    x = v[0];
    y = v[1];
    z = v[2];
  }

  /**
   * @brief Overrides + operator.
   * @param[in] v The Vector3 object you would like to add to this Vector3
   * object
   * @return The Vector3 Object comprised of the sum of the two objects
   */
  Vector3 operator+(const Vector3& v);

  /**
   * @brief Overrides - operator.
   * @param[in] v The Vector3 object you would like to subtract to this Vector3
   * object
   * @return The Vector3 Object comprised of the subtraction of the two objects
   */

  Vector3 operator-(const Vector3& v);
  /**
   * @brief Overrides * operator.
   * @param[in] v The Vector3 object you would like to multiply to this Vector3
   * object
   * @return The Vector3 Object comprised of the multiplication of the two
   * objects
   */
  Vector3 operator*(float m);

  /**
   * @brief Overrides / operator.
   * @param[in] v The Vector3 object you would like to divide to this Vector3
   * object
   * @return The Vector3 Object comprised of the division of the two objects
   */
  Vector3 operator/(float m);

  /**
   * @brief Overrides [] operator, allowing caller to read and write to index into x, y, z elements
   * @param[in] index The index of the vector at which the value is desired
   * @return The value at index; if index is out of bounds, no useful data is returned.
   */
  float& operator[](int index) {
    if (index == 0) {
      return x;
    }
    if (index == 1) {
      return y;
    }
    if (index == 2) {
      return z;
    }

    static float dummyData;
    return dummyData;
  }

  /**
   * @brief Overrides [] operator, allowing caller to read to index into x, y, z elements
   * @param[in] index The index of the vector at which the value is desired
   * @return The value at index; if index is out of bounds, no useful data is returned.
   */
  float operator[](int index) const {
    if (index == 0) {
      return x;
    }
    if (index == 1) {
      return y;
    }
    if (index == 2) {
      return z;
    }
    return 0.0;
  }

  /**
   * @brief Computes and returns the vector's magnitude.
   * @return The vector's magnitude.
   */
  float Magnitude() { return std::sqrt(x * x + y * y + z * z); }

  /**
   * @brief Computes and returns the unit vector.
   * @return The unit vector.
   */
  Vector3 Unit() { return (*this) / Magnitude(); }

  /**
   * @brief Distance to another vector
   * @param v The vector to which the distance is desired
   * @return The distance to vector v
   */
  float Distance(const Vector3& v) {
    return sqrt(pow(v.x - this->x, 2) + pow(v.y - this->y, 2) +
                pow(v.z - this->z, 2));
  }

  /**
   * @brief Prints vector to nicely formatted string
   */
  void Print();

  /**
   * @brief Converts Vector3 object to C++ vector object
   * @return vector in C++ vector object form
   */
  std::vector<float> toCppVector() {
    std::vector<float> result;
    result.push_back(x);
    result.push_back(y);
    result.push_back(z);
 
    return result;
  }
};

#endif  // Vector3_H_
