#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int reverse(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return atoi(s.c_str());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    cout << reverse(reverse(x) + reverse(y));

    return 0;
}