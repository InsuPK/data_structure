#include <iostream>
#include <string>
#include <stack>

using namespace std;

//void printStack(stack<string> s);

// void printStack(stack<string> *s) {
//     while (!(*s).empty()) {
//         cout << (*s).top() << ' ';
//         (*s).pop();
//     }
// }

void printStack(stack<string> *s) {
    string x;
    if ((*s).empty())
        return;
    cout << (*s).top() << ' ';
    x = (*s).top();
    (*s).pop();
    return printStack(s), (*s).push(x);
}

void printStack_fromBottom(stack<string> *s) {
    string x;
    if ((*s).empty())
        return;
    x = (*s).top();
    (*s).pop();
    return printStack_fromBottom(s), cout << x << ' ', (*s).push(x);
}

int main () {
    //int list [] = {1, 2, 3, 4, 5, 0, 6, 0, 0, 7, 0, 0, 0, 8};
    string list[] = {"to", "be", "or", "not", "to", "-", "be", "-", "-", "that", "-", "-", "-", "is"};
    //string list[] = {"p", "o", "t", "s"};

    stack<string> s;
    for (auto item : list) {
        if (item != "-")
            s.push(item);
        else {
            cout << s.top() << ' ';
            s.pop();
        }
    }

    cout << "\nsize: " << s.size();
    cout << "\ntop: " << s.top();
    cout << "\nstack T: "; printStack(&s);
    cout << "\nstack T: "; printStack(&s);
    cout << "\nstack B: "; printStack_fromBottom(&s);
    cout << "\nHappy Coding";
}

// void printStack(stack<string> s) {
//     stack<string> t;
//     while (!s.empty()) {
//         cout << s.top() << ' ';
//         t.push(s.top());
//         s.pop();
//     }
//     while (!t.empty()) {
//         s.push(t.top());
//         t.pop();
//     }
// }
