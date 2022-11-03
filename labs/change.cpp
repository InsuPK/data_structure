#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;

    cin >> n;
    if (n == 1 || n == 3) {
        cout << -1;
    }
    else if ((n % 5) % 2 == 0) {
        cout << n / 5 + (n % 5) / 2;
    }
    else {
        cout << ((n / 5) - 1) + ((n % 5) + 5) / 2;
    }

    return 0;

}