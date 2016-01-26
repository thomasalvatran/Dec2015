//home/tovantran/Ctest/copyconstructor2.cpp --> 2015-04-06 by ./.tv  owner: tovantran
//https://www.youtube.com/watch?v=2KvslbLHTUY
//with dynamic memory allocation in youtube learningLad
#include <iostream>
#include <string.h>
using namespace std;

class Person {
	public:
		string *name;  //memory allocation pointer need new 
		int age;

		Person(string name, int age){
			this->name = new string(name);
			this->age = age;
		}

		Person(const Person &p){   //reference for copy ctor
			name = new string(*p.name);	
			age = p.age;
			cout << "Copy ctor" << endl;
		}
   Person& operator=(const Person &source) {
   if (this == &source)
       return *this;
     this->name = new string(*source.name);
     this->age = source.age;
	   //sizeof(source);
     //copy(source, this , sizeof(source));
     strcpy(*(this->name), *source.name);
     cout << "operator assign " << endl;
     return *this;
   }
		void changeNameandAge(string name, int age){
			*(this->name) = name;
			this->age = age;
		}

		void introduce(){
			cout << "Hi I am "<< *name << " and I am "<< age << endl;
		}
};
int main(){
	Person anil("Anil", 24);
	cout << sizeof(anil) << endl;
	anil.introduce();
  Person duplicateanil("Anilll", 24555);
	//Person duplicateanil = anil;  //copy ctor
	duplicateanil = anil;
	duplicateanil.introduce();

	anil.changeNameandAge("Anil Shetty", 100);
	anil.introduce();
	duplicateanil.introduce();
	return 0;
}



