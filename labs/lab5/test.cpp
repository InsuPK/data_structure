#include <iostream>

using namespace std;
int main() {
    char msg[] = "hello";
    char *test = new char[3];
    test[0] = '1';
    test[1] = '2';
    cout << &test << endl;
    cout << test[1] << endl;
    cout << &msg << endl;

    int *list = new int[10];
    list[0] = 1;
    cout << list << endl;
    cout << (*list) << endl;

    return 0;
}