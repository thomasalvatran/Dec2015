//Modern C++ youtube.com A tout of Moern C++
//home/tovantran/Ctest/Dec9ModernC.cpp --> 2015-12-14 by ./.tv  owner: tovantran

#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <functional> //function
using namespace std;

struct Address
{

};

struct Person{  //own type not build in type
    string name;
    int age;
    Address address;
public:
    explicit Person(const Address& address) : address(address){}
    explicit Person(const string name, const int age):
    name(name), age(age){}
};

struct Exchange
{
    int count;
    float rates[2];
    Exchange(initializer_list<float> r)
    {
        if (r.size() < 2) return;
        auto i = r.begin();
        rates[0] = *i;
        i++;
        rates[1] = *i;
    }
};

template<typename T, typename U>
auto add(T t, U u) //->decltype(t+u)
{
    return t + u;
}

auto meaning_of_life() //->int
{
    return 42;
}

class Animal
{
protected:
    int legs = 4; //old C++ const int legs
public:
    explicit Animal(int legs) : legs(legs) {}
    virtual int walk(int steps)
    {
        return steps * 20;
    }
};

class Human : public Animal
{
 public:
    Human() : Animal(2) {}   //derived from Animal calls base ctor ****
//    Human(const Human&) = delete; //avoid generate automatic
//    int walk(int steps) override;
    int walk(int steps)
    {
        return steps * 10;
    }
};

int main()
{
    {
        vector<int> scores {8, 2, 4, 3};
        for_each(begin(scores), end(scores), []( int n) -> float
        {
            cout << n << endl;
            return n;
        });
        int zero = 0;
        auto is_positive = [zero](int n){ return n > zero; };
        cout << boolalpha << is_positive(2) << endl;
    }
//    auto fib = [&fib](int x) { return x < 2 ? 1 : fib(x -1) + fix(x - 2); };
    function<int(int)> fib = [&fib](int x) { return x < 2 ? 1 : fib(x -1) + fib(x - 2); };
    Human h;
    Human h2{ h };
    cout << "walk = " << h2.walk(1) << endl;

    Exchange e{10, 2, 3};  //legal value 1 assign to count and 2, 3 to rates
    Exchange e1{100.10, 200.20};    //count  == 1 and 1st element of array == 2
    cout << e1.count << " " << e1.rates[0] << " " << e1.rates[1] << endl;

    cout << add(2, 2.5) << endl;
    cout << add(string("Hello, "), "world") << endl; //string + char

    vector<double> value;
    typedef decltype(value.begin()) dvi;
    typedef decltype(42) myint;
//    myint = 1; //FAIL expected unqualified id before = token but it is ok myint(1)
    cout << "myint =" << myint(1) << endl;
    typedef decltype(add(2, 2.5)) qtype;
    cout << qtype(2222) << endl;

    int a = 1;
    int n{4}; //more powerful easy to initialize type
    string s{ "foo" };

    vector<int> values = {1, 2, 3};

    vector<int> values0;
    values0.push_back(1);

    vector<int> values1{1, 2, 3};  //new modern

    // map<string, string> capitals = {  OK without operator =
    map<string, string> capitals {
      {"UK", "London"}
    };
    Person p{"tom", 12};

    Person person(Address());  //like function
    Person person1{Address()}; // uniform initialization  this is constructor
    {
        auto a = 12.11;
        auto c =  "hello";
        auto d = { 1, 2, 3 };
        cout << a << endl;
        decltype(a) x = 2;


        map<string, vector<double>> ticks;
        auto itt = ticks.begin();

        map<string, vector<double>>::iterator it = ticks.begin();

        cout << meaning_of_life() << endl;
    }

}

