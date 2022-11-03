//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]

// postfix.cpp :
//
// The program evaluates a given postfix expression and produces a fully
// parenthesized infix expression. If the postfix expression may be 
// evaluated to a numeric value if it is expressed using numerically.
// For simplicity of coding, however, the postfix expression consists
// of single character operands and operators only and may have spaces.
//
// Author: idebtor@gmail.com
// 2020.04.05	Creation
// 2020.10.03	evaluation of numerical postfix expressions
//
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

// change the printStack to use template once you finish part 1 in step 1.
// prints the stack contents from the bottom.
template<typename T>
void printStack(stack<T> orig) {
    stack<T> temp;
    while (!orig.empty()) {
        cout << orig.top() << ' ';
        temp.push(orig.top());
        orig.pop();
    }
    while (!temp.empty()) {
        orig.push(temp.top());
        temp.pop();
    }
}

// returns a fully parenthesized infix expression in string after postfix evaluation.
string evaluate(string tokens) {
	stack<string> st;

	for (char token : tokens) {
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// current token is a operator,
        // pop two operands and evaluate them and push the results to st.
		if (token == '+' || token == '-' || token == '*' || token == '/') {
            assert(st.size() >= 2);
            string x;
            x = st.top();
            st.pop();
            x = "(" + st.top() + " " + token + " " + x + ")";
            st.pop();
            st.push(x);
		}
		else {  // push the operand
			DPRINT(cout << "  push: " << token << endl;);
			// convert token(char type) to a string type and push it to the stack
            st.push(string(1, token));
		}
	}

	DPRINT(cout << "token exhausted: \n";);
	DPRINT(printStack(st););
	DPRINT(cout << "stack size() should be 1.\n";);

    assert(st.size() == 1);
    //cout << "your code here" << endl;
    
	DPRINT(cout << "<evaluate() returns " << "your expr" << endl;);
    return st.top();
}

// returns true if the tokens consist of '+', '-', '*', '/', spaces, and 
// digits (0 ~ 9), false otherwise.
bool is_numeric(string tokens) {
    for (char token : tokens) {
        if (isspace(token)) continue;
        if (token != '+' && token != '-' && token != '*' && token != '/' && token != '0' && token != '1' && token != '2' && token != '3' && token != '4' && token != '5' && token != '6' && token != '7'&& token != '8' && token != '9') {
            return false;
        }
    }
	return true;
}

// returns a numeric value after evaluating the postfix evaluation.
double evaluate_numeric(string tokens) {
	stack<double> st;

	for (char token : tokens) {
		if (isspace(token)) continue;  // if token is a whitespace, skip it.
		DPRINT(cout << "token: " << token << endl;);

		// if token is a operator, evaluate; if a digit(or operand), push it to st.
        if (token == '+' || token == '-' || token == '*' || token == '/') {
            // checking the stack top() for right operand
            // checking the stack top() for left oprand
            // compute the expression and push the result
            double x = 0;
            double a = 0;
            double b = 0;
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            if (token == '+') {
                x = a + b;
            } else if (token == '-') {
                x = a - b;
            } else if (token == '*') {
                x = a * b;
            } else if (token == '/') {
                x = a / b;
            }
            st.push(x);
			//st.push(0);
		}
		else { // push the operand (digit) in a value to the stack
			// convert token to a numeric data type and push it the stack
            st.push(double(token - '0'));
			//st.push(0);
		}
	}

	DPRINT(cout << "token exhausted: check the stack, its size() should be 1.\n";);
    DPRINT(printStack(st););

	//cout << "your code here" << endl;
	//double expr = 0;
    double expr = st.top();
	DPRINT(cout << "<evaluate() returns " << expr << endl;);
	return expr;
}
