#include <iostream>
#include <string>

using namespace std;


struct Stack {
    int *item;
    int N;
    int capacity;
};

using stack = Stack *;

stack newStack(int capacity = 100000) {
    stack s = new Stack;
    s->item = new int[capacity];
    s->N = 0;
    s->capacity = capacity;
    return s;
}

void pop (stack s) {
    s->N--;
}

int top(stack s) {
    return s->item[s->N - 1];
}

void push(stack s, int item) {
    s->item[s->N++] = item;
}

int main() {
    stack s = newStack();
    int n = 0, input = 0, sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        if (input == 0) {
            pop(s);
        } else {
            push(s, input);
        }
    }

    n = s->N;
    for (int i = 0; i < n; i++) {
        sum += top(s);
        pop(s);
    }

    cout << sum << endl;

    return 0;
}
