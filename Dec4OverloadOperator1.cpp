// http://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
//home/tovantran/Ctest/Dec4OverloadOperator1.cpp --> 2015-12-04 by ./.tv  owner: tovantran

#include <iostream>
#include <vector>
//#include <limits>
#include <iomanip>

using namespace std;
const int SIZE = 3; /* height, width, lenght */

template <typename T>
class Box
{
  
  std::vector<T> m_vec;  //no size vec(2) initiate in ctor
  public:
  
  Box operator+(Box b) //Box& b) by value or reference all working
  {
      Box box;
      box.m_vec[0] = this->m_vec[0] + b.m_vec[0];
      box.m_vec[1] = this->m_vec[1] + b.m_vec[1];
      box.m_vec[2] = this->m_vec[2] + b.m_vec[2];
      return box;
  }
  Box(T height, T width, T lenght) : m_vec(SIZE) //vector size in ctor
  { 
    m_vec[0] = height;
    m_vec[1] = width;
    m_vec[2] = lenght;
  } 
  Box() : m_vec(SIZE) { cout <<"Ctor" << endl;};
  void showBox(Box box)
  {
    cout << setprecision(2) << "height = "<< box.m_vec[0] << endl;
    cout << fixed << "width = "<< box.m_vec[1] << endl;
    cout << fixed << "lenght = "<< box.m_vec[2] << endl;
  }
};

int main()
{
  // vector<int> v(2);
  Box<float> box1(1.1, 2, 3.0);  //Box<int> for integer, <float> for float
  Box<float> box2(3.5, 4, 5.0);
  Box<float> box = box1 + box2;
  box.showBox(box);
  
  // cout << box.m_vec[0] << endl;  //m_vec is private
  // cout << box.m_vec[1] << endl; 
  // cout << box.m_vec[2] << endl;
}
