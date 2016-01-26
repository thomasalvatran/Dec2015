#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int i = 0;
    for ( double x = 0.0; x < 1 ; x+= (double)1/15, i++)
       cout << i << " " << x  << endl;
    
    double x = 15.0;
    while(x-->1)
      cout << x << " " << i << "|";
    cout << endl;
    return 0;
}

  
