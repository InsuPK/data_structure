//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]

#include <iostream>
#include <string.h>

using namespace std;

struct Car{
    int age;
    string tag;
};

int main() {
    Car ur = {25, "cat"};
    Car *my = new Car {20, "sky"};
    Car *we = &ur;
    ur.tag = "hat";
    cout << (*we).tag << endl;

    delete my;
    //delete we;
}




