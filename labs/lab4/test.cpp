#include <iostream>

using namespace std;

void print_hello()
{
    cout << "Hello, world!\n";
}
int main() {

    cout << reinterpret_cast<void *>(&print_hello);
    
    return 0;
}