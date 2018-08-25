/*
 * LambdaExpressions.cpp
 *
 *  Created on: 18 ago 2018
 *      Author: michele
 */

#include <iostream>

using namespace std;

void test(void (*pFunc)())
{
	pFunc();
}

void test2(void (*pFunc)(int _array[], int _size), int array[], int size)
{
	pFunc(array, size);
}

int main() {

	auto func = []()
	{
		cout << "Hello" << endl;
	};

	func();

	test(func);

	test([]() {cout << "Hello again" << endl; });

	cout << endl;
	int array[] {1,2,3};

	//This is a comment

	//Comment n.X
	//Comment n.4
	auto func2 = [](int array[], int size)
	{
		/*
		 * this doesn't work: end is not defined in this scope
		 * */
//		for(auto val: array) {
//			cout << val << endl;
//		}
		for(int i = 0; i < size; i++) {
			cout << array[i] << endl;
		}

	};



	//Another row.
	//First Branch Added.
	//Merge.
	//Master from Kubuntu.
	//Number 1.

	func2(array, 3);
	cout << endl;
	test2(func2, array, 3);

	cout << endl;

	auto func3 = [](string name) -> string
	{
		//cout << "Welcome " << name << endl;
		return "Welcome " + name;
	};

	string rFunc3 = func3("Michele");
	cout << rFunc3 << endl;

	cout << endl;

	auto rFunc4 = [rFunc3]() -> string { return "Welcome " + rFunc3; }(); //Lambda Capure Expression by  value = [rFunc3];
	cout << rFunc4 << endl;

	int newInt = 3;
	int newInt2 = 5;

	[=](){ cout << "Welcome " << endl; }(); //Lambda Capture Expression all local variables by value
	[=, &newInt](){ cout << "Welcome " << endl; newInt++; }(); //Lambda Capture Expression all local variables by value, but newInt by reference.
															   //newInt2 can't be modified as it is read-only variable after passing by value
	cout << newInt << endl;


	[&](){ cout << "Welcome " << endl; newInt++, newInt2++; }(); //Lambda Capture Expression all local variables by reference
	cout << newInt << " " << newInt2 << endl;

	[&, newInt](){ cout << "Welcome " << endl; newInt2++; }(); //Lambda Capture Expression all local variables by value, but newInt by value.
	cout << newInt << " " << newInt2 << endl;

	return 0;
}


