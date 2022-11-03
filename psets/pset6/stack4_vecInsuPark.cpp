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

struct Stack {
    vector<string> item;
};
using stack = Stack *;

void free(stack s) {
    delete s;
}

int size(stack s) {
    return s->item.size();
}

bool empty(stack s) {
    return s->item.empty();
}

void pop(stack s) {
    s->item.pop_back();
}

string top(stack s) {
    return s->item.back();
}

void push(stack s, string item) {
    s->item.push_back(item);
    DPRINT(s->item.capacity(), s->item.size());
}

void printStack(stack s) {
    string x;
    if (empty(s))
        return;
    cout << top(s) << ' ';
    x = top(s);
    pop(s);
    return printStack(s), push(s, x);
}

void printStack_fromBottom(stack s) {
    string x;
    if (empty(s))
        return;
    x = top(s);
    pop(s);
    return printStack_fromBottom(s), cout << x << ' ', push(s, x);
}

int main() {
    stack s = new Stack;
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    
    for (auto item : list) {
        if (item != "-") {
            push(s, item);
        } else {
            cout << top(s) << ' ';
            pop(s);
        }
    }
    cout << "\nsize: " << size(s);
    cout << "\ntop: " << top(s);
    cout << "\nStack T: "; printStack(s);
    cout << "\nStack B: "; printStack_fromBottom(s);

    free(s);
}
