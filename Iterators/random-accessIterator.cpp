/*
- Few algo that use Random-access iterator
	- nth_element
	- sort
	- random_shuffle
- Can be used to access elements at an arbitrary offset position relative to the element they point to, offering the same functionality as pointers.
- Random-access iterators are the most complete iterators in terms of functionality
- All pointer types are also valid random-access iterators.
- Container that support Random-access iterator
	1. Vector
	2. Deque
- Salient Features
	- Used in multi-pass algorithms, i.e., algorithm which involves processing the container several times in various passes.
	- Equality / Inequality Comparison: A == B, A != B (Allowed)
	- Dereferenced both as a rvalue as well as a lvalue.
	- Incrementable
	- Decrementable
	- Relational Operators: Although, Bidirectional iterators cannot be used with relational operators like , =,
				but random-access iterators being higher in hierarchy support all these relational operators.
				(A <= B allowed)
	- Arithmetic Operators: Can be used with arithmetic operators like +, – and so on. 
				This means that Random-access iterators can move in both the direction, and that too randomly.
	- Random-access iterators support offset dereference operator ([ ]), which is used for random-access.
	- Swappable
*/
