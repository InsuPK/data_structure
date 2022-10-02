//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]

//Quiz 1에서는 run-time error가 발생했다고 생각합니다. 크기가 할당되지 않은 메모리에 접근하려고 시도했기 때문입니다.
#include <iostream>
using namespace std;

int main() {
    
    int *pi;
    pi = new int;
    *pi = 17;

    cout << "i = " << *pi << endl;

    delete pi;
    
    return 0;
}