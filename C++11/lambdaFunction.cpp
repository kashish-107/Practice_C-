/*
1. auto lambda_Fun = []() { cout<<"Lambda fun"<<endl; };
	struct anonymous {
		public:
			auto operator()() const {
				cout<<"Lambda fun"<<endl;
			}
	}

2. auto lambda_byVal = [val]() { cout<<"I am lambda_byVal-"<<val<<endl; };
	struct anonymous {
		public:
			anonymous(int val):val{val} { }
			auto operator()() const {
				cout<<"I am lambda_byVal-"<<val<<endl;
			}
		private:
			int val{}; //Capture is considered as data member of class
	}


3. auto lambda_byRef = [&val]() { val++; cout<<"I am lambda_byRef-"<<val<<endl; };
	struct anonymous {
		public:
			anonymous(int val):val{val} { }
			auto operator()() const {
				val++;  // not modifying the class data
				cout<<"I am lambda_byRef-"<<val<<endl;
			}
		private:
			int &val; //Capture is considered as data member of class
	}


4. auto lambda_byVal_mutable = [val]() mutable { val++; cout<<"I am lambda_byVal_mutable-"<<val<<endl; };
	struct anonymous {
		public:
			anonymous(int val):val{val} { }
			auto operator()() {                //Non-const because its mutable
				cout<<"I am lambda_byVal-"<<val<<endl;
			}
		private:
			int val{}; //Capture is considered as data member of class
	}

5. auto is_above = (th)[int val] { return val > th; }
	struct anonymous {
		public:
			anonymous(int th):th{th} {}
			auto operator()(int val) const {
				return val>th;
			}
		private:
			int th{};
	}

6. Intializing variable inside capture
	[c=vector<int>{4,2}]() { 
			cout<<"Intializing variable in capture: ";
			for(auto& val:c)
				cout<<val; 
	}();

	struct anonymous {
		public:
			anonymous() : c{4,2} {}
			auto operator()() const -> void {
				cout<<"Intializing variable in capture: ";
				for(auto& val:c)
					cout<<val; 
			}
		private:
			vector<int> c{};
	}
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class foo
{
public:
	foo(int i):i{i} {}
	
	void member_fun() {
		int j = 0;
		[=](){ cout<<i<<j<<endl; }();
		[&](){ cout<<i<<j<<endl; }();
		//[*this](){ cout<<i<<endl; };
		[this](){ cout<<i<<endl; }();
	}
private:
	int i;
};

int count_Value_above(const vector<int>& v, int val)
{
	return count_if(begin(v), end(v), [val](int v) { return v > val; });
}

void download(const char* url, void(* callback)(int))
{
	cout<<"download"<<endl;
	callback(10);
}

int main()
{
	auto lambda_Fun = []() { cout<<"Lambda fun"<<__FUNCTION__<<" "<<endl; };
	lambda_Fun();
	
	vector<int> vec {1,3,1,2,3,2,4,5};
	cout<<count(vec.begin(), vec.end(), 1)<<endl;
	cout<<count_if(vec.begin(), vec.end(), [](int v) { return v > 1; })<<endl;
	cout<<count_Value_above(vec,2)<<endl;

	int val = 1;
	//Capture by value
	auto lambda_byVal = [val]() {
				cout<<__FUNCTION__<<" I am lambda_byVal-"<<val<<endl;
			};
	lambda_byVal();
	cout<<"Value after lambda_byVal: "<<val<<endl;
	
	//Capture by reference
	auto lambda_ref = [&val]() {
				val++;
				cout<<"I am lambda_ref- "<<val<<endl;
			};
	val++;
	lambda_ref();	
	cout<<"Value after lambda_ref: "<<val<<endl;
	
	//Capture by value but mutable
	auto lambda_byVal_mutable = [val]() mutable {
				val++;
				cout<<"I am lambda_byVal_mutable-"<<val<<endl;
			};
	lambda_byVal_mutable();
	lambda_byVal_mutable();
	cout<<"Value after lambda_byVal_mutable: "<<val<<endl;
	
	
	int th = 3;
	auto is_above = [th](int val) { return val > th; };
	cout<<is_above(5)<<endl;

	//Intializing variable in capture
	//Calling with IIFE - Immediately Invoked Function Expression
	[c=vector<int>{4,2}]() { 
			cout<<"Intializing variable in capture: ";
			for(auto& val:c)
				cout<<val; 
	}();

	//Capture all
	[=](){cout<<endl<<th<<endl;}(); //By value
	[&](){cout<<th<<endl;}(); //By reference
	foo f = foo(2);
	f.member_fun();

	//Capture by both - mixed capture
	[=, &th](){ }();      //th by reference and rest by value

	//Generic Lambda
	auto generic_Lambda = [](auto i, auto j) { cout<<i<<" Generic Lambda "<<j<<endl; };
	generic_Lambda(1,2);
	generic_Lambda("kashish", "mittal");

	//Can access static variable without capture
	static int stat_i = 10;
	[]() { cout<<"Static without capture: "<<stat_i<<endl;}();

	//C function pointer to lambda
	auto lambdaFuncPointer = +[](int result){ cout<<"I am function pointer lambda "<<result<<endl; };
	download("kashish", lambdaFuncPointer);
	return 0;

}
