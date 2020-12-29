#include <iostream>
#include <exception>



class canGoWrong {
public: 
	canGoWrong() {
		char* pMemory = new char[999];
		delete[] pMemory;
	}
};




void mightGoWrong() {
	bool error1 = true;
	bool error2 = true;
	if (error1) {
		throw 8;
	}
	if (error2) {
		throw "Somthing went wrong";
	}
}

class myException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "somthing bad happened";
	}
};

class test {
public:
	void goesWrong() {
		throw myException();
	}
};


int main() {
	try {
		mightGoWrong();
	}
	catch (int e) {
		std::cout << "Error code: " << e << std::endl;
	}
	catch (char const* e) {
		std::cout << "Error code: " << e << std::endl;
	}

	std::cout << "Still running" << std::endl;
	

	try {
		canGoWrong wrong;
	}
	catch(std::bad_alloc &e){
		std::cout << "Cought exception: "<< e.what() << std::endl;
	}
	std::cout << "Still running" << std::endl;

	

	test test;

	try {
		test.goesWrong();
	}
	catch (myException& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}