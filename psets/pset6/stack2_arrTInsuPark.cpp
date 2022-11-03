//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]

#include <iostream>
#include <string>

using namespace std;

template<typename T>
struct Stack {
    T *item;
    int N;
    int capacity;
};

template<typename T>
using stack = Stack<T> *;

template<typename T>
stack<T> newStack(int capacity) {
    stack<T> s = new Stack<T>;
    s->item = new T[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

template<typename T>
void free(stack<T> s) {
    delete[] s->item;
    delete s;
}

template<typename T>
int size(stack<T> s) {
    return s->N;
}

template<typename T>
bool empty(stack<T> s) {
    return s->N == 0;
}

template<typename T>
void pop(stack<T> s) {
    s->N--;
}

template<typename T>
T top(stack<T> s) {
    return s->item[s->N-1];
}

template<typename T>
void push(stack<T> s, T item) {
    s->item[s->N++] = item;
}

template<typename T>
void printStack(stack<T> s) {
    T x;
    if (empty(s))
        return;
    cout << top(s) << ' ';
    x = top(s);
    pop(s);
    return printStack(s), push(s, x);
}

template<typename T>
void printStack_fromBottom(stack<T> s) {
    T x;
    if (empty(s))
        return;
    x = top(s);
    pop(s);
    return printStack_fromBottom(s), cout << x << ' ', push(s, x);
}

int main() {
    stack<string> s = newStack<string>(8);
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    
    for (auto item : list) {
        if (item != "-")
            push(s, item);
        else {
            cout << top(s) << ' ';
            pop(s);
        }
    }

    cout << "\nsize: " << size(s);
    cout << "\ntop: " << top(s);
    cout << "\nStack T: "; printStack(s);
    cout << "\nStack B: "; printStack_fromBottom(s);
}
