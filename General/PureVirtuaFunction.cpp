/*
1. A class is abstract if it has at least one pure virtual function. 
2. Abstract class can have normal functions and variables along with a pure virtual function.
3. We can have pointers and references of abstract class type. 
4. If we do not override the pure virtual function in derived class, then derived class also becomes abstract class.
5. We can’t create object of abstract class as we reserve a slot for a pure virtual function in Vtable, 
but we don’t put any address, so Vtable will remain incomplete
6. An abstract class can have constructors.
7. An interface class is a class that has no member variables, and where all of the functions are pure virtual! 
In other words, the class is purely a definition, and has no actual implementation. 
Interfaces are useful when you want to define the functionality that derived classes must implement, 
but leave the details of how the derived class implements that functionality entirely up to the derived class.
*/

#include <iostream>
#include <memory>

using namespace std;

class base {
public:
    virtual void fun() = 0;
};

//Derived1 will also be a abstract class as it hasn't implemented pure virual function
class Derived1 : public base { 

};

class Derived2 : public base {
    virtual void fun() {

    }
};

class Animal {
protected:
    string mName;
public:
    Animal(const string& iName) :mName(iName) {

    }
    virtual const char* speak() = 0;
    virtual ~Animal() = default;
};

const char* Animal::speak() {
    return ("I am " + mName +" and I Speak ").c_str();
}

//Derived1 will also be a abstract class as it hasn't implemented pure virual function
class Cat : public Animal {
public:
    Cat(string iName) :Animal(iName) {

    }
    const char* speak() override {
        cout << Animal::speak();
        return "Meow";
    }
};

class Dog : public Animal {
public:
    Dog(string iName) :Animal(iName) {

    }
    const char* speak() override {
        cout << Animal::speak();
        return "Woof";
    }
};

int main()
{
    //Derived1 obj1; //Error - Cannot instantiate abstract class
    Derived2 obj1;
    unique_ptr<Animal> pCat = make_unique<Cat>("Kitty");
    cout << pCat->speak() << endl;

    unique_ptr<Animal> pDog = make_unique<Dog>("Tommy");
    cout << pDog->speak() << endl;
    return 0;
}
