#include <iostream>
#include <string>

using namespace std;

struct Stack {
    string *item;
    int N;
    int capacity;
};
using stack = Stack *;

stack newStack(int capacity = 1) {
    stack s = new Stack;
    s->item = new string[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

void free(stack s) {
    delete[] s->item;
    delete s;
}

int size(stack s) {
    return s->N;
}

bool empty(stack s) {
    return s->N == 0;
}

void pop(stack s) {
    s->N--;
}

string top(stack s) {
    return s->item[s->N-1];
}

void push(stack s, string item) {
    s->item[s->N++] = item;
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
    stack s = newStack();
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
