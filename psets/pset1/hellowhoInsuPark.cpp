//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]

/*
* file: hellowho.cpp
* It prints "Hello World!" or "Hello" with a given name.
* The completed code should work as shown below. “>” is a prompt of the console.
*
*
*
*
*
*
*
*
To run the program without a command line argument:
  > ./hello
> Enter a name: John Lee
> Hello John Lee!
> Enter a name: Peter Kim
> Hello Peter Kim!
> Enter a name:<Enter>
* > Hello World! *>
*
* To run the program with a command line argument:
*   > ./hello John "Dr. Lee" "Handong Global University" peter
*   > Hello John!
*   > Hello Dr. Lee!
*   > Hello Handong Global University!
*   > Hello peter!
* > Hello World! *>
* To run the program through a pipe
* (names.txt contains a list of names as shown below:)
*   > cat names.txt | ./hello
*   > Enter a name: Hello john!
*   > Enter a name: Hello Dr. Lee!
*   > Enter a name: Hello Handong Global University!
*   > Enter a name: Hello Peter!
*   > Enter a name: Hello World!
*
*/
#include <iostream>
#include <string>
using namespace std;
int main() {
  string input;
  // if necessary, use setvbuf() to prevent the output from buffered on console.
  // setvbuf(stdout, NULL, _IONBF, 0);
  //cout << "Your code here" << endl;
  //cout << "Hello World!\n";

  while (true) {
    cout << "Enter a name: ";
    getline(cin, input);

    if (input == "") {
      cout << "Hello World!" << endl;
      break;
    }
    
    cout << "Hello " << input << "!" << endl;
  }
  // if necessary use system("pause") to prevent the terminal from disappearing
// as soon as the program terminates as in Visual Studio sometimes. // system("pause");
return EXIT_SUCCESS;
}