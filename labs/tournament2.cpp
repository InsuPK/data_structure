#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int Kim;
    int Im;
    int count = 0;

    cin >> n >> Kim >> Im;

    while (Kim != Im) {
        Kim = Kim/2 + Kim%2;
        Im = Im/2 + Im%2;
        count++;
    }

    cout << count;

    return 0;
}
