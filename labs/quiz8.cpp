#include <iostream>

using namespace std;

int main() {
    int* p = new int(25);
    cout << *p << endl;
    int* q = p;
    cout << *q << endl;
    *q = 34;
    q = new int(56);
    p = new int(78);
    cout << *p << endl;
    cout << *q;
    delete p;
    delete q;

}