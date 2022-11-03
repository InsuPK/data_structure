//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]

// infix.cpp :
//
// The program evaluates a given infix expression which is fully parenthesized.
// It uses Dijkstra's two-stack algorithm. For simplicity of coding, however,
// the expression is to be fully parenthesized.
// For example:
//   ((3 - 1 ) * 5) + 4
//   2 * ((34 - 4) * 2)
//   1 + (((12 * 2) / 4) - 1)
//
// Author: idebtor@gmail.com
// 2020.04.05    created and assert() added
//
#include <iostream>
#include <cassert>
#include <cmath>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#if 0    //////////////////////////////////////////////////////////////////////
// set #if 1, if you want to use this stack using vector instead of STL stack.
// a basic stack functinality only provided for pedagogical purpose only.
#include <vector>
template <typename T>
struct stack {
    vector<T> item;

    bool empty() const {
        return item.empty();
    }
    auto size() const {
        return item.size();
    }
    void push(T const& data) {
        item.push_back(data);
    }
    void pop() {
        if (item.empty())
            throw out_of_range("stack<>::pop(): pop stack");
        item.pop_back();
    }
    T top() const {
        if (item.empty())
            throw out_of_range("stack<>::top(): top stack");
        return item.back();
    }
};
#else  /////////////////////////// using STL stack //////////////////////////
#include <stack>
#endif ///////////////////////////////////////////////////////////////////////

template <typename T>
void printStack(stack<T> orig) {
    
    T x;
    if (orig.empty())
        return;
    cout << orig.top() << ' ';
    x = orig.top();
    orig.pop();
    return printStack(orig), orig.push(x);
    
    //cout << "Step 2: your code here: copy printStack() template version from postfix.cpp\n";
    //cout << "Step 3: rewrite printStack() using recursion. refer to PDF file\n";

    cout << endl;
}

// performs arithmetic operations.
double apply_op(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a,b);
    }
    cout << "Unsupported operator encountered: " << op << endl;
    return 0;
}

int precedence (char op) {
    int precedence;
    
    if (op == '^') {
        precedence = 3;
    }
    else if (op == '*' || op == '/') {
        precedence = 2;
    }
    else {
        precedence = 1;
    }
    
    return precedence;
}

// there is a bug...
double compute(stack<double>& va_stack, stack<char>& op_stack) {
//    double left  = va_stack.top(); va_stack.pop();
//    double right = va_stack.top(); va_stack.pop();
    double right  = va_stack.top(); va_stack.pop();
    double left = va_stack.top(); va_stack.pop();
    char op = op_stack.top(); op_stack.pop();
    double value = apply_op(left, right, op);

    DPRINT(cout << " va/op_stack.pop: " << value << endl;);
    return value;
}

// returns value of expression after evaluation.
double evaluate(string tokens) {
    DPRINT(cout << ">evaluate: tokens=" << tokens << endl;);
    stack<double> va_stack;              // stack to store operands or values
    stack<char> op_stack;                 // stack to store operators.
    double value = 0;

    for (size_t i = 0; i < tokens.length(); i++) {
        // token is a whitespace or an opening brace, skip it.
        if (isspace(tokens[i])) continue;
        DPRINT(cout << " tokens[" << i << "]=" << tokens[i] << endl;);

        // current token is a value(or operand), push it to va_stack.
        if (isdigit(tokens[i])) {
            int ivalue = 0;
            ivalue = tokens[i] - '0';
            while (true) {
                if (isdigit(tokens[i+1])) {
                    ivalue *= 10;
                    ivalue += tokens[i+1] - '0';
                    i++;
                } else {
                    break;
                }
            }
            //cout << "your code here: to handle multi-digits(operand)\n";
            //ivalue = tokens[i] - '0';
            va_stack.push(ivalue);
        }
        else if (tokens[i] == ')') { // compute it, push the result to va_stack
            
            while (true) {
                if (op_stack.top() != '(') {
                    assert(va_stack.size() >= 2);
                    va_stack.push(compute(va_stack, op_stack));
                } else {
                    op_stack.pop();
                    break;
                }
            }
            //cout << "your code here\n";

        }
        else if (tokens[i] == '(') {
            op_stack.push(tokens[i]);
        }
        else { // token is an operator; push it to op_stack.
            while (true) {
                if (op_stack.size() >= 1 && op_stack.top() != '(' && op_stack.top() != ')') {
                    int lastOp = precedence(op_stack.top());
                    int thisOp = precedence(tokens[i]);
                    
                    if (thisOp <= lastOp) {
                        assert(va_stack.size() >= 2);
                        va_stack.push(compute(va_stack, op_stack));
                    } else {
                        op_stack.push(tokens[i]);
                        break;
                    }
                } else {
                    op_stack.push(tokens[i]);
                    break;
                }
                
            }
        }
    }
    
    
    
    DPRINT(cout << "tokens exhausted: now, check two stacks:" << endl;);
    DPRINT(printStack(va_stack);  cout << endl;);
    DPRINT(printStack(op_stack);  cout << endl;);
    
    while (!op_stack.empty()) {
        assert(va_stack.size() >= 2);
        va_stack.push(compute(va_stack, op_stack));
    }
    
    assert(va_stack.size() == 1);
    
    value = va_stack.top();
    //cout << "your code here: process if !op_stack.empty() \n";
    //cout << "your code here: post-conditions\n";
    //cout << "your code here: return & clean-up\n";
    
    return value;
}
