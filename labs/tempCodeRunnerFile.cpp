#include <iostream>
#include <climits>
//#include <bits/stdc++.h>

using namespace std;

int maximum[100001] = {0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n , num;
    int front = -1;
    int rear = -1;
    int max = -100;
    int size = 0;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> num;

        if (num == 0) {
            
            //if empty, print 0
            if (front == -1) {
                cout << 0 << "\n";
            } 
            else {
                //deque
                cout << maximum[front] << "\n";

                if (front == rear) {
                    front = -1;
                    rear = -1;
                }
                else {
                    front = (front + 1) % size;
                }
            }
            
        }
        else {
            //enque
            size++;
            if (front == -1) front = 0;
            
            if (num > max) {
                max = num;
                //cout << max << endl;
                //배열값이 비어있지 않거나 하나 이상이면 rear+1 % 100001값에 max값을 넣어주고 front를 rear위치로 바꿔준다. 이제 max index가 front가 된다.
                if (rear >= 0) {
                    //cout << "rear%: " << (rear+1) % 100001 << endl;
                    maximum[(rear+1) % size] = num;
                    //cout << "max rear: " << front << endl;
                    front = (rear+1) % size;
                    //cout << "front: " << front << endl;
                }
                //배열값이 비어있거나 하나 밖에 없으면 그냥 enque
                else {
                    rear = (rear+1) % size;
                    maximum[rear] = num;
                }
            }
            else {
                rear = (rear+1) % size;
                maximum[rear] = num;
            }

        }


        //cout << "front: " << front << endl;
        //cout << "rear: " << rear << endl;

    }

    return 0;
}