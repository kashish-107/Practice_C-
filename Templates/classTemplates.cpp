/*
- class templates are useful when a class defines something that is independent of the data type
*/

#include<iostream>

template<typename T>
class base
{
public:
	T _x;
	T _y;
};

template<typename T, size_t SIZE>
struct Array
{
	T* data();	
	const T* data() const;
	constexpr size_t size() const { return SIZE; }
	T* begin() { return data(); }
	T* end() { return data() + SIZE; }
	T& operator[](int idx) { return mData[idx]; }
	
	T mData[SIZE];
};

template<typename T, size_t SIZE>
T* Array<T, SIZE>::data()
{
	return std::addressof(mData[0]);
}

template<typename T, size_t SIZE>
const T* Array<T, SIZE>::data() const
{
	return std::addressof(mData[0]);
}

int main()
{
	base<int> obj{1,2};
	Array<int, 5> arr{1,2,3,4,5};
	for(const auto& i:arr) {
		std::cout<<i<<std::endl;
	}
	return 0;
}
