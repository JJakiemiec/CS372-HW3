//Jacob Jakiemiec
//CS372
//HW3
//2-21-21
//Lambda functions

#include <vector>
using std::vector;
#include <iostream>
using std::cout;
using std::endl;
#include <algorithm>
#include <functional>
#include <typeinfo>


void printVec(const vector<int>& v) {
	for (auto i : v)
		cout << i << ",";
	cout << endl;
}

int main() {
	//I know about lambda functions, but I haven't really used them that much
	//Mostly I know of their use in conjunction with algorithm
	//for example:
	vector<int> vec{1, 4, 2, 6, 321, 5, 132, 0};
	std::sort(vec.begin(), vec.end());													//for a default sort, the vector will be in ascending order
	printVec(vec);							
	std::sort(vec.begin(), vec.end(), [](int left, int right) {return left > right; });	//however, we can use a lambda function to say exactly how we want to sort it.
	printVec(vec);																		//this lambda function will make std::sort sort the vector in descending order
	

	//in general, you can assign a variable a lambda function, and call the variable as if it is a function
	//though in order to get it to work you need to use auto
	auto sum = [](int a, int b) {return a + b; };
	cout << "sum: " <<sum(7, 2) << endl;
	cout << "type of sum: " << typeid(sum).name() << endl;								//why is this the type?
	int test;
	cout << "test type: " << typeid(test).name() << endl;

	cout << endl;

	//you can also give the lambda functions outside parameters by putting them in the brackets
	int base = 12;
	auto baseSum = [base](int a) {return base + a; };
	cout << "basesum with 10: " << baseSum(10) << endl;
	cout << "changing base from 12 to 5" << endl;
	base = 5;
	cout << "basesum with 10: " << baseSum(10) << endl;		//basesum takes a copy of base, so if base changes, the lambda function does not

	cout << endl;

	auto BaseReferenceSum = [&base](int a) {return base + a; };
	cout << "baseReferenceSum with 10: " << BaseReferenceSum(10) << endl;
	cout << "changing reference base from 5 to 12" << endl;
	base = 12;
	cout << "basesum with 10: " << BaseReferenceSum(10) << endl;	//now that we took base a a reference, if base changes, so does the lambda function



	//however you can also do other things such as use them in structs
	//though you need to use std::function in order to use it
	//however I was not able to get it to work as I wanted



	return 0;

}