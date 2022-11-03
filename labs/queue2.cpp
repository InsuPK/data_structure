#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    vector<int> queue;
    string command;
    int size = 0;
    int index = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "push") {
            int item;
            cin >> item;
            queue.push_back(item);
            size++;
        } else if (command == "pop") {
            if (size == 0) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", queue[index]);
                index++;
                size--;
            }
        } else if (command == "size") {
            printf("%d\n", size);
        } else if (command == "empty") {
            if (size == 0) {
                printf("%d\n", 1);
            } else {
                printf("%d\n", 0);
            }
        } else if (command == "front") {
            if (size == 0) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", queue[index]);
            }
        } else {
            if (size == 0) {
                printf("%d\n", -1);
            } else {
                printf("%d\n", queue[size+index-1]);
            }
        }
    }
    
    return 0;
}