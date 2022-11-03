#include <iostream>

using namespace std;

int tournament1[100001];
int tournament2[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int Kim;
    int Im;
    int roundCount = 1;
    bool finish = true;

    cin >> n;
    cin >> Kim;
    cin >> Im;

    while (finish) {
        int tournament2Count = 0;
        for (int i = 1; i <= n; i++) {
            tournament1[i] = i;
            if (i % 2 == 0) {
                if (tournament1[i-1] == Kim && tournament1[i] == Im) {
                    finish = false;
                } else if (tournament1[i-1] == Im && tournament1[i] == Kim) {
                    finish = false;
                } else {
                    if (i-1 == Kim || i-1 == Im) {
                        tournament2[tournament2Count] = i-1;
                    } else if (i == Kim || i == Im) {
                        tournament2[tournament2Count] = i;
                    } else {
                        tournament2[tournament2Count] = rand() % 1 + i;
                    }
                    tournament2Count++;
                    roundCount++;
                }
            }
        }
        copy(begin(tournament2), end(tournament2), begin(tournament1));
        n = n/2;
        tournament2Count = 0;
    }

    cout << roundCount;


    return 0;
}
