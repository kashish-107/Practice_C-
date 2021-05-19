#include<iostream>
#include<future>
#include<chrono>

using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

ull findOddSum(ull start, ull end)
{
	int oddSum = 0;
	for (int i = 0; i < end; i++)
		oddSum += (i & 1);
	return oddSum;
}

int main()
{
	ull start = 0, end = 1900000000;
	future<ull> oddSum = async(launch::async, findOddSum, start, end);
	this_thread::sleep_for(chrono::seconds(5));
	
	cout << "Waiting for result" << endl;
	auto startTime = high_resolution_clock::now();
	cout << "Odd Sum:" << oddSum.get() << endl;
	auto endTime = high_resolution_clock::now();
	cout << "Time taken " << (duration_cast<seconds>(endTime - startTime)).count();
	return 0;
}
