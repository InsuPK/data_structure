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
    string x;
    char op = '+';
    s.push("a");
    s.push("b");
    x = s.top();
    s.pop();
    x = "(" + s.top() + " " + string(1, op) + " " + x + ")";
    s.pop();
    s.push(x);
    cout << s.top() << endl;

    // for (auto item : list) {
    //     if (item != "-")
    //         s.push(item);
    //     else {
    //         cout << s.top() << ' ';
    //         s.pop();
    //     }
    // }

    // cout << "\nsize: " << s.size();
    // cout << "\ntop: " << s.top();
    // cout << "\nstack T: "; printStack(&s);
    // cout << "\nstack T: "; printStack(&s);
    // cout << "\nstack B: "; printStack_fromBottom(&s);
    // cout << "\nHappy Coding";
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

// while (true) {
//                 if (st.top() != " ") {
//                     x = st.top();
//                     st.pop();
//                     break;
//                 } else {
//                     st.pop();
//                 }
//             }
            
//             while (true) {
//                 if (st.top() != " ") {
//                     x = "(" + st.top() + " " + token + " " + x + ")";
//                     st.pop();
//                     st.push(x);
//                     break;
//                 } else {
//                     st.pop();
//                 }
//             }