/*
1. ParamType is reference or pointer 
2. ParamType is const reference or const pointer - T is int always
3. ParamType is Universal Reference or Const Universal pointer
4. ParamType is pass by value
5. During template type deduction, arguments that are reference are treated as non-reference
6. Const & Volatile are treated as Non-const & Non-volatile for pass by value parameter.
7. During template type deduction, arguments that are array or function names decay to pointer,
unless thery're used to intialize reference
*/
#include<iostream>
using namespace std;

template<typename T>
void funRef(T& ParamType) {
	cout << __FUNCSIG__ << endl;
}

template<typename T>
void funConstRef(const T& ParamType) {
	cout << __FUNCSIG__ << endl;
}

template<typename T>
void funPtr(T* ParamType) {
	cout << __FUNCSIG__ << endl;
}

template<typename T>
void funConstPtr(const T* ParamType) {
	cout << __FUNCSIG__ << endl;
}

template<typename T>
void funUniRef(T&& ParamType) {
	cout << __FUNCSIG__ << endl;
}

template<typename T>
void funUniConstRef(const T&& ParamType) {
	cout << __FUNCSIG__ << endl;
}

template<typename T>
void funPassByVal(T ParamType) {
	cout << __FUNCSIG__ << endl;
}

//void funArrayChar(const char iInput[]) {  //Array decay
void funArrayChar(const char (&iInput)[8]) {      //To prevent array decay take array as reference
	cout << sizeof(iInput) << endl;
}

//void funArrayInt(int param[]) {           //Array decay
void funArrayInt(int (&param)[5]) {         //To prevent array decay take array as reference
	cout << sizeof(param) << endl;
}

template<typename T>
void funArrayAsValue(T ParamType) {
	cout << __FUNCSIG__ << endl;
	cout << sizeof(ParamType) << endl;
}

template<typename T>
void funArrayAsRef(T& ParamType) {
	cout << __FUNCSIG__ << endl;
	cout << sizeof(ParamType) << endl;
	ParamType[0] = 7;
}

int main() {
	int i = 10;
	const int j = i;
	const int& k = i;
	
	cout << "ParamType is reference type:" << endl;
	funRef(i);
	funRef(j);
	funRef(k);
	//funRef(10); //Error

	cout << "\nParamType is reference to const type:" << endl;
	funConstRef(i);
	funConstRef(j);
	funConstRef(k);
	funConstRef(20);

	int x = 27;
	const int* px = &x;
	cout << "\nParamType is pointer type:" << endl;
	funPtr(&x);
	funPtr(px);

	cout << "\nParamType is reference to const type:" << endl;
	funConstPtr(&x);
	funConstPtr(px);

	cout << "\nParamType is universal reference type:" << endl;
	funUniRef(i);
	funUniRef(j);
	funUniRef(k);
	funUniRef(10);

	cout << "\nParamType is universal reference to const type:" << endl;
	funUniConstRef(move(i));
	funUniConstRef(move(j));
	funUniConstRef(move(k));
	funUniConstRef(10);

	cout << "\nParamType is Pass by value type:" << endl;
	funPassByVal(i);
	funPassByVal(j);
	funPassByVal(k);
	funPassByVal(10);

	cout << "\nArray decay" << endl;
	const char name[] = "Kashish";
	cout << sizeof(name) << endl;
	const char* ptrToName = name; //array decay to pointer
	funArrayChar(name);           //array decay to pointer

	int val[] = { 1,2,3,4,5 };
	cout << sizeof(val) << endl;
	funArrayInt(val);            //array decay to pointer

	cout << "\nParamType is Array as pass by value" << endl;
	funArrayAsValue(val);

	cout << "\nParamType is Array as reference to prevent Array decay" << endl;
	funArrayAsRef(val);
	cout << val[0] << endl;

	return 0;
}