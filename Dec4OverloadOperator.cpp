// http://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
//home/tovantran/Ctest/Dec4OverloadOperator.cpp --> 2015-12-04 by ./.tv  owner: tovantran

#include <iostream>
#include <vector>
//#include <limits>
#include <iomanip>

using namespace std;

template <typename T>
class Box
{
  T m_width;
  T m_height;
  public:
  Box operator+(Box b) 
  {
      Box box;
      box.m_width = this->m_width + b.m_width;
      box.m_height = this->m_height + b.m_height;
      return box;
  }
  Box(){};
  Box(T width, T height) : m_width(width), m_height(height) {}
  
  T getwidth() { return m_width; }
  T getheight() { return m_height; }
};

int main()
{
  Box<float> box1(2.3, 3.5);
  Box<float>  box2(5.5, 6.8);
  Box<float> box = box1 + box2;
  cout << fixed  << box.getwidth() << endl;
  cout << setprecision(2) << box.getheight() << endl;  
}
