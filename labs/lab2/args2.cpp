//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]
// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
//
// Lab 2:
//	1. vector class in c++
//	2. ranged-for loop
//	3. function overloading
//	4. include file
//  5. not using `using namespace std;`

#include <iostream>
#include <vector>
#include "printfunc.h"

using namespace std;

int main(int argc, char **argv) {

	cout << "Print using printfunc(**argv)\n";
	
	for (int i = 1; i < argc; i++) {
		cout<< "Hello " << argv[i] << "!\n";
	}

	// copy **argv to a `vector<string> names;` except 1st one. 
	// use push_back() method in the vector class
	cout << "Copy using vector<string>\n";
	vector<string> names;
	for (int i = 1; i < argc; i++) {
		names.push_back(argv[i]);
	}
	//cout << "your code here\n";

	// print names only using for-loop and names
	// do not use argc/argv and ranged-for loop
	cout << "Print using indexing, but not ranged-for\n";
	//cout << "your code here\n";

	for (int i = 0; i < names.size(); i++) {
		cout << "Hello " << names[i] << "!\n";
	}

	cout << "Print names using printfunc(vector<string>)\n";
	// use ranged-for loop in printfunc(vector<string>)
	// do not use `using namespace std;` in printfunc.cpp 
	// cout << "Print names using printfunc(vector<string>)\n";
	// printfunc(names);

	printfunc(names);

	return 0;
}
