#include<iostream>
#include<chrono>
#include<thread>
using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

void findOdd(ull start, ull end)
{
	ull OddSum = 0;
	for (ull i = start; i < end; i++)
		if ((i & 1) == 1) OddSum += i;
	cout << OddSum << endl;
}

void findEven(ull start, ull end)
{
	ull EvenSum = 0;
	for (ull i = start; i < end; i++)
		if ((i & 1) == 0) EvenSum += i;
	cout << EvenSum << endl;
}

int main()
{
	ull start = 0, end = 1900000000;

	auto startTime = high_resolution_clock::now();

	thread t1(findOdd, start, end); //Syntax for function pointer
	thread t2(findEven, start, end);

	t1.join(); //Joining thread with main()
	t2.join(); 

	//findOdd(start, end);
	//findEven(start, end);

	auto stopTime = high_resolution_clock::now();

	auto duration = duration_cast<seconds>(stopTime - startTime);
	cout << duration.count() << endl;
	return 0;
}
