#include <iostream>

using namespace std;

int fun(int x, int y) {
    return x + y;
}

int foo(int x, int y) {
    return x * y;
}

int print(int op(int, int), int x, int y) {
    return op(x,y);
}


// void swap(int* a, int* b) {
//     int temp = *a;
//     *a = *b;
//     *b = *a;
// }

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void change(int op(int, int), int func(int, int)) {
    op = func;
}


int main() {
    int (*fps[])(int, int) = {fun, foo};
    int (*op)(int, int) = fun;
    int a = 1;
    int b = 2;
    //cout << fps(a,b);
   // cout << print(fps[0], a, b);
   // cout << print(fps[1], a, b);

    change(&op, foo);
    cout << fps(a, b);

    int x = 3;
    int y = 4;
    swap(x, y);
    cout << "\n" << x << y << endl;

}