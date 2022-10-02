#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    int values[10] = {0};
    int coins = 0;

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    for (int i = n; i > 0; i--) {
        coins += k / values[i-1];
        k = k % values[i-1];
    }

    cout << coins << endl;

    return 0;
}