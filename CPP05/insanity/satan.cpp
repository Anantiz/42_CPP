#include <iostream>
#include <string>

class Parent {

	private:

		const int x;

		// Make this class non-copyable by making the copy constructor private
		// Never called (as expected)
		virtual Parent &operator=(const Parent &p) {
			std::cout << "Parent assignment operator" << std::endl;
			return *this;
		}

	public:

		Parent(int x) : x(x) {
			std::cout << "Parent constructor" << std::endl;
		}
		~Parent() {
			std::cout << "Parent destructor" << std::endl;
		}

		// Make this class abstract
		virtual void foo() = 0;
};

class Child :Parent {

	private:

		// Somehow never gets called
		Child &operator=(const Child &c) {
			std::cout << "Child assignment operator" << std::endl;
			return *this;
		}

	public:

		Child(int x) : Parent(x) {
			std::cout << "Child constructor" << std::endl;
		}
		~Child() {
			std::cout << "Child destructor" << std::endl;
		}

		Child(const Child &c) : Parent(c) {
			std::cout << "Child copy constructor" << std::endl;
		}

		virtual void foo() {
			std::cout << "Child foo" << std::endl;
		}
};

int main()
{
	//Create a child, and try to create a copy of it (which should fail)
	Child c(5);
	std::cout << std::endl;

	Child c2 = c; // Why the hell is this working??
	//c = c2; // This fails tho

	//Child c2(c); meme chose
	// It bypasses the assignment operator overload and calls the copy constructor of the parent class

	/* WTF ??????????????????????????????????????*/
}
