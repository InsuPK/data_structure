//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]
// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
#include <iostream>
#include <vector>
#include <string>
#include "../include/printfunc.h"

//using namespace std;

void printfunc(int n, char *names[]) {
	for (int i = 0; i < n; i++)
		std::cout << "Hello " << names[i] << "!" << std::endl;
}

void printfunc(std::vector<std::string> names) {
	for (auto name : names) {
		std::cout <<"Hello " << name << "!" << std::endl;
	}
}
