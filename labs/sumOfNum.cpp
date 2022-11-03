    #include <iostream>

    using namespace std;

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long n;
        long long total = 0;
        long long i;
        int count = 0;

        cin >> n;

        for (i = 1; i <= n; i++) {
            total += i;
            count++;
            if (total > n){
                count--;
                break;
            }
        }

        cout << count;

        return 0;
    }