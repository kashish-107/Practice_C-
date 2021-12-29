/*
- When the vector needs to rearrange the Person objects (for example, as a result of an
insert), the values are copy constructed or moved. Objects are moved if they have a
nothrow move constructor. Otherwise, the objects will be copy constructed in order to
guarantee strong exception safety
*/

#include<iostream>
#include<vector>

using namespace std;

class Person
{
public:
	Person() { cout<<"Default ctor"<<endl; }
	Person(const Person& other) { cout<<"Copy ctor"<<endl; }
	auto& operator=(const Person& other) { 
		cout<<"Assignment operator"<<endl; 
		return *this;
	}
	auto& operator=(Person&& other) noexcept { 
		cout<<"Move Assignment operator"<<endl; 
		return *this;
	}
	Person(Person&& other) noexcept  { cout<<"Move ctor"<<endl; }
};

int main()
{
	vector<int> vec{1,2,3,4,5};
	for(auto& i:vec)
		cout<<i<<endl;

	vector<Person> vec_P;
//	vec_P.reserve(5);
	vec_P.emplace_back();
	vec_P.emplace_back();
	vector<Person> vec_P2;
	vec_P.reserve(5);
	vec_P2[0] = move(vec_P[0]);	
	return 0;
}
