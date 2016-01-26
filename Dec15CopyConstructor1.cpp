//home/tovantran/Ctest/copyconstructor1.cpp --> 2015-04-06 by ./.tv  owner: tovantran
//https://www.youtube.com/watch?v=2KvslbLHTUY
//no dynamic memory allocation
//youtube learninglad
#include <iostream>
#include <string>
using namespace std;

class Person {
	public:
	string name;  // no dynamic memory allocation
	int age;
	
	Person(string name, int age): name(name), age(age){
//	this->name = name;
//	this->age = age;
	}
	
	void changeNameandAge(string name, int age){
	this->name = name;
	this->age = age;
	}
	
	void introduce(){
	cout << "Hi I am "<< name << " and I am "<< age << endl;
	}
};
int main(){
	Person anil("Anil", 24);
	anil.introduce();
	
	Person duplicateanil = anil;
	duplicateanil.introduce();
	
	anil.changeNameandAge("Anil Shetty", 100);
	anil.introduce();
	duplicateanil.introduce();
	return 0;
}
//no dynamic memory allocation
//Hi I am Anil and I am 24
//Hi I am Anil and I am 24
//Hi I am Anil Shetty and I am 100
//Hi I am Anil and I am 24
