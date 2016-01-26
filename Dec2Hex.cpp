#include <iostream>
using namespace std;

main()
{
int N1;

while (int i=1){
 if (N1 == 3)
   break;
cout << "Enter decimal: "<< endl;
cin >> N1;
cout << hex << "Hex: 0x"<< uppercase << N1 << endl;
cout << dec << "Dec: "<< uppercase << N1 << endl;
}

return 0;
}
