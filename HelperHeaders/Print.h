#pragma once

#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

template<typename T>
void PrintVector(vector<T> iInput)
{
	for (auto& elm : iInput)
		cout << elm << " ";
	cout<<endl;
}

template<typename T, typename U, typename V>
void PrintMap(map<T, U, V> iInput)
{
	for (auto& elm : iInput)
		cout << "{" << elm.first << "," << elm.second << "} ";
	cout << endl;
}

template<typename T, typename U, typename V>
void PrintMultiMap(multimap<T, U, V> iInput)
{
	for(auto& elm : iInput)
		cout << "{" << elm.first << "," << elm.second << "} ";
	cout << endl;
}
