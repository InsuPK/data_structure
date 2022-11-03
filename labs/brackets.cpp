#include <iostream>
#include <string>

using namespace std;


struct Stack {
    string *item;
    int N;
    int capacity;
};

using stack = Stack *;

stack newStack(int capacity = 50) {
    stack s = new Stack;
    s->item = new string[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

void pop (stack s) {
    s->N--;
}

string top(stack s) {
    return s->item[s->N-1];
}

void push(stack s, int item) {
    s->item[s->N++] = item;
}

bool empty(stack s) {
    return s->N == 0;
}

int main() {
    int n = 0;
    cin >> n;
    string brackets;

    for (int i = 0; i < n; i++) {
        stack s = newStack();
        cin >> brackets;
        for (int j = 0; j < brackets.length(); j++) {
            if (brackets[j] == '(') {
                push(s, brackets[j]);
            } else {
                if (top(s) == "(") {
                    pop(s);
                } else {
                    push(s, brackets[j]);
                }
            }
        }
        if (empty(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
