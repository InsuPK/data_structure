//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// #ifdef DEBUG
// #define DPRINT(func) func;
// #else
// #define DPRINT(func) ;
// #endif

#define DPRINT(capacity, size) cout << "capacity: " << capacity << " size: " << size << endl;

template<typename T>
struct Stack {
    vector<T> item;
};

template<typename T>
using stack = Stack<T> *;

template<typename T>
void free(stack<T> s) {
    delete s;
}

template<typename T>
int size(stack<T> s) {
    return s->item.size();
}

template<typename T>
bool empty(stack<T> s) {
    return s->item.empty();
}

template<typename T>
void pop(stack<T> s) {
    s->item.pop_back();
}

template<typename T>
T top(stack<T> s) {
    return s->item.back();
}

template<typename T>
void push(stack<T> s, T item) {
    s->item.push_back(item);
    DPRINT(s->item.capacity(), s->item.size());
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
    stack<string> s = new Stack<string>;
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    //int list [] = {1, 2, 3, 4, 5};
    
    for (auto item : list) {
        if (item != "-") {
            push(s, item);
        } else {
            cout << top(s) << ' ';
            pop(s);
        }
    }

    // for (auto item : list) {
    //     push(s, item);
    // }

    cout << "\nsize: " << size(s);
    cout << "\ntop: " << top(s);
    cout << "\nStack T: "; printStack(s);
    cout << "\nStack B: "; printStack_fromBottom(s);

    free(s);
}
