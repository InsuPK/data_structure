//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]

#include <iostream>
#include <iomanip>

using namespace std;

struct Clock {
    int hr, min, sec;
};

void tick(Clock *ptr);
void show(Clock *ptr);

int main (void) {
    Clock *ptr = new Clock {14, 38, 56};

    for (int i = 0; i < 6; i++) {
        tick(ptr);
        show(ptr);
    }
    return 0;
}

void tick (Clock *ptr) {
    ptr->sec++;
    if ((*ptr).sec >= 60) {
        ptr->min++;
        ptr->sec = 0;
    }

    if ((*ptr).min >= 60) {
        ptr->hr++;
        ptr->min = 0;
    }
}

// show the current time in military form.
void show (Clock *ptr) {
    std::cout.fill('0');
    std::cout << std::setw(2) << ptr->hr << ":" << std::setw(2) << ptr->min << ":" << std::setw(2) << ptr->sec << std::endl;
}