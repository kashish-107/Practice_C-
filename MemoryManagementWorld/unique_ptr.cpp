/*
- Exclusive ownership
- Not possible to copy one unique_ptr to another
- std::move() function to transfer ownership of the contained pointer to another unique_ptr
- Can't transfer ownership of "const unique_ptr"
- providing exception safety to classes and functions that handle objects with dynamic lifetime, 
by guaranteeing deletion on both normal exit and exit through exception
- passing ownership to functions
- acquiring ownership from functions
- get()     - does not make unique_ptr release ownership of the pointer
- release() - unique_ptr object is released from the responsibility of deleting the object
- reset()   - Destroys the object currently managed by the unique_ptr (if any) and takes ownership of p. 
- swap()    - Exchanges the contents of the unique_ptr object. transferring ownership of any managed object between them without destroying either.
- operator[]- unique_ptr also has an overloaded operator [] to access the array elements by index. It is equivalent to: get()[i].
- Custom Del- deleter might not occupy any space at all in a unique_ptr object.
		For instance, a typical implementation of unique_ptr utilizes the empty base optimization. such that an empty function object or a capture-less lambda does not take any space. In those cases, the size of a unique_ptr is the same as the size of a raw pointer.However, a function pointer or a function object with data members or an std::function custom deleter increases the size of unique_ptr object.  
*/

#include<iostream>
#include<memory>

using namespace std;

class foo
{
public:
	 foo(int x)
		:_v{x} { cout<<"Foo ctor"<<endl; }
        ~foo() { cout<<"Foo dtor"<<endl; }

	void setVal(int x) { _v=x; }
	void showVal() { cout<<_v<<endl; }
private:
	int _v{0};
};

class Product
{
public:
	~Product() {
		cout<<__FUNCTION__<<endl;
	}
};

auto customDeleter = [](Product *p) {
		cout<<" I am a custom deleter"<<endl;
		delete p;
};

using uniqPtr_Product = unique_ptr<Product, decltype(customDeleter)>; 

class Factory
{
public:
	static uniqPtr_Product createProduct() {
		return uniqPtr_Product(new Product(), customDeleter);
	}

	~Factory() {
		cout<<__FUNCTION__<<endl;
	}
};

int main()
{
	unique_ptr<foo> ptr_1 = make_unique<foo>(10);
	auto ptr_2 = make_unique<foo>(20);
	
	ptr_1->showVal();
	(*ptr_2).showVal();

	//unique_ptr<foo> iPtr_3 = ptr_1;	//Error	
	cout<<"Move ownership. From pointer will set to nullptr"<<endl;
	unique_ptr<foo> ptr_4 = move(ptr_1);
	ptr_4->showVal();
	
	/* Get */
	cout<<"Get() - this function does not make unique_ptr release ownership of the pointer"<<endl;
	foo* ptr_5 = ptr_4.get();
	ptr_4->showVal();
	ptr_5->showVal();
	
	/* Release */
	cout<<"Release() - Releases ownership of its stored pointer, by returning its value and replacing it with a null pointer"<<endl;
	foo* ptr_6 = ptr_4.release();
	//ptr_4->showVal();
	ptr_6->showVal();

	/* Reset */
	cout<<"Reset() - Destroys the object currently managed by the unique_ptr (if any) and takes ownership of p."<<endl;
	unique_ptr<foo> ptr_7;
	ptr_7.reset(new foo(17));          // takes ownership of pointer
	ptr_7.reset();                     // deletes managed object
	ptr_2.reset(new foo(5));           // deletes managed object, acquires new pointer
	ptr_2->showVal();

	/* Swap */
	cout<<"Swap() "<<endl;
	unique_ptr<foo> ptr_a = make_unique<foo>(30);
	unique_ptr<foo> ptr_b = make_unique<foo>(40);
	ptr_a.swap(ptr_b);
	ptr_a->showVal();
	ptr_b->showVal();
	
	/* Operator[] array */
	auto arr = make_unique<int[]>(3);

	/* Custom deleter */
	cout<<"----------Custom deleter----------------"<<endl;
	auto f_ptr = make_unique<Factory>();
	f_ptr->createProduct();
	return 0;
}
