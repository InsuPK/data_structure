#include <iostream>
#include <string>

using namespace std;


struct Stack {
    int *item;
    int N;
    int capacity;
};

using stack = Stack *;

stack newStack(int capacity = 10000) {
    stack s = new Stack;
    s->item = new int[capacity];
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

void pop (stack s) {
    if (s->N >= 1) {
        cout << s->item[s->N - 1] << endl;
        s->N--;
    } else {
        cout << "-1" <<endl;
    }
}

int top(stack s) {
    if (s->N >= 1) {
        return s->item[s->N - 1];
    } else {
        return -1;
    }
}

void push(stack s, int item) {
    s->item[s->N++] = item;
}

int main() {
    stack s = newStack();
    int n = 0;
    cin >> n;
    string command;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "push") {
            int item;
            cin >> item;
            push(s, item);
        }

        if (command == "top") {
            cout << top(s) << endl;
        }

        if (command == "size") {
            cout << size(s) << endl;
        }

        if (command == "pop") {
            pop(s);
        }

        if (command == "empty") {
            cout << empty(s) << endl;
        }
    }

    return 0;
}
