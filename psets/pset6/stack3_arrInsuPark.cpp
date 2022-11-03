//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]

#include <iostream>
#include <string>

using namespace std;

// #ifdef DEBUG
// #define DPRINT(func) func;
// #else
// #define DPRINT(func) ;
// #endif

#define DPRINT(capacity, size) cout << "capacity: " << capacity << " size: " << size << endl;

struct Stack {
    string *item;
    int N;
    int capacity;
};
using stack = Stack *;

void resize(stack s, int new_capacity) {
    string *copied = new string[new_capacity];
    for (int i = 0; i < s->N; i++)
        copied[i] = s->item[i];
    s->item = copied;
    s->capacity = new_capacity;
}

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
    if (s->capacity/4-1 == s->N) {
        resize(s, s->capacity/2);
    }
}

string top(stack s) {
    return s->item[s->N-1];
}

void push(stack s, string item) {
    if (s->capacity == s->N+1) {
        resize(s, s->capacity*2);
    }
    s->item[s->N++] = item;
    DPRINT(s->capacity, s->N);
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
