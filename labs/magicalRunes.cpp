/*#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int n;
    int index = 1;

    cin >> s >> n;

    for (int i = 0; i < n; i++) {
        if (s[0] == 'A') {
            s[0] = 'B';
        } 
        else {
            s[0] = 'A';
            while (true) {
                if (s[index] == 'B') {
                    s[index] = 'A';
                }
                else {
                    s[index] = 'B';
                    break;
                }
                index++;
            }
        }
        index = 1;
    }
    cout << s;

    return 0;
}*/

#include <iostream>
using namespace std ;

int main()
{
    string str ;
    int N, answer ;
    cin >> str >> N ;
    
    for(int i = str.length() - 1 ; i + 1 ; i--)
    {
        answer <<= 1 ;
        if(str[i] == 'B') answer |= 1 ;
        //cout << answer << endl;
    }
    
    answer += N ;

    //cout << answer << endl;
    
    for(int i = 0 ; i < str.length() ; i++)
    {
        cout << answer << endl;
        answer & 1 ? cout << 'B' : cout << 'A' ;
        answer >>= 1;
    }
}