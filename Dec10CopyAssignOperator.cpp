// http://www.geeksforgeeks.org/copy-constructor-vs-assignment-operator-in-c/
#include <iostream>
#include <stdio.h>
using namespace std;

class Test
{
public:
  int m_t;
  Test(int i) : m_t(i) {}
//  Test(const Test &t)
//  {
//      cout << "Copy Ctor" << endl;
//      
//      
//  }
//  Test& operator = (const Test &t)
//  {
//      cout << "Assign opertor" << endl;
//  }
//Compiler create a default assign overload opeartor and copy ctor
// Test(const Test& t) : m_t(t.m_t){ cout << "Shallow copy ctor " << endl; } //shallow copy
// Test& operator=(const Test& t)  { m_t = t.m_t ; cout << "Shallow overload operator = " << endl; } //shallow overload assign operator 
};

int main()
{
    Test t1(1), t2(2);
    t2 = t1;        //assign
    Test t3 = t1;   //copy
    cout << t3.m_t << endl;
    return 0;
}
// Copy constructor is called when a new object is created from an existing object, as a copy of the existing object (see this G-Fact). And assignment operator is called when an already initialized object is assigned a new value from another existing object.
// t2 = t1;  // calls assignment operator, same as "t2.operator=(t1);"
// Test t3 = t1;  // calls copy constructor, same as "Test t3(t1);"
