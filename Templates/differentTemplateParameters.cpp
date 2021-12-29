/*
- NTTP: Non-type parameters that are used to instantiate a template must be compile time constants or constexpr values
*/

#include<iostream>
using namespace std;

template<typename T  //Type parameter
	 size_t N>   //NTTP (non-type template parameter)

//template template parameters
template<template<typename 
int main()
{
	
}
