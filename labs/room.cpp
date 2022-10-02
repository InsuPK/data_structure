#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector < pair<int, int> > r;

int main()
{  
    int n, a, b;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        r.push_back(make_pair(b, a));
    }

    sort(r.begin(), r.end());

    int x = 0;
    int i = 1, count = 1;

    while (true) {
        if (i >= n) {
            break;
        }

        if (r[x].first <= r[i].second) {
            count++;
            x = i;
        }
        i++;
    }

    cout << count << endl;
    
    return 0;
}