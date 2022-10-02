//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]

#include <iostream>
#include <map>
using namespace std;

int main() {
    cout << "declare map variable called table\n";
    map<string, int> table;

    cout << "initialize table using array[], insert(), pairt<>, make_pair()\n";
    table["Adam"] = 11;
    table["John"] = 21;
    table.insert(pair<string, int>("Paul", 15));
    table.insert(make_pair("Pete", 10));

    cout << "print table using range-based for loop\n";
    for (auto i : table) {
        cout << "name: " << i.first <<"       age: " << i.second << endl;
    }

    cout << "print table using iterator\n";

    for (map<string, int>::iterator i = table.begin(); i != table.end(); i++) {
        cout << "name: " << (*i).first <<"       age: " << i->second << endl;
    }

    cout << "define and initialize chart using pair<> and make_pair() only\n";

    map<string, int> table2 {
        pair<string, int>("A", 65),
        pair<string, int>("B", 66),
        make_pair("C", 67),
        make_pair("D", 68)
    };

    cout << "print chart using range-based for loop\n";

    for (auto i = table2.begin(); i != table2.end(); i++) {
        cout << "ascii: " << (*i).first <<"         code: " << i->second << endl;
    }

    return 0;
}