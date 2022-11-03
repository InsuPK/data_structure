#include <iostream>
#include <algorithm>

using namespace std;

int queue[100];
int priority[100];
int maximum[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int front = -1;
    int rear = -1;
    int testcase, size, num;
    int priorityNum;
    int maxIndex = 0;
    int priorityElement, queueElement;
    int count = 1;

    cin >> testcase;

    for (int i = 0; i < testcase; i++) {
        
        //인덱스 초기화
        front = -1;
        rear = -1;
        maxIndex = 0;
        count = 1;
        
        cin >> size >> num;
        
        //큐 입력
        for (int i = 0; i < size; i++) {
            cin >> priorityNum;

            //enque
            if (front == -1) front = 0;
            rear = (rear + 1) % size;

            priority[rear] = priorityNum;
            queue[rear] = i;
        }
        
        //우선순위 큐 대신 max배열을 만들어줌, 내림차순 정렬
        for (int i = 0; i < size; i++) {
            maximum[i] = priority[i];
        }
        
        sort(maximum, maximum+size, greater<int>());

        while (true) {
            //큐 재배치
            if (priority[front] < maximum[maxIndex]) {
                //deque
                priorityElement = priority[front];
                queueElement = queue[front];
                front = (front + 1) % size;
    
                //enque
                rear = (rear + 1) % size;
                priority[rear] = priorityElement;
                queue[rear] = queueElement;
            }
            //큐 출력
            else {
                //deque
                if (queue[front] == num) {
                    cout << count << "\n";
                    break;
                } else {
                    count++;
                    maxIndex++;
                    front = (front + 1) % size;
                }
            }
        }

    }

    return 0;
}
