//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]

#include <iostream>
#include <iomanip>
#include <unistd.h>

struct Clock {
    int hr, min, sec;
};

using pClock = Clock*;
void tick(pClock ptr);
void show(pClock ptr, char end = '\n');
void runs(pClock ptr, char end = '\n');

int main (void) {
    pClock ptr = new Clock {14, 38, 56};

    runs(ptr, '\r');

    delete ptr;
}

void runs (pClock clk, char end) {
    while (true) {
        sleep(1);
        tick(clk);
        show(clk,'\r');
    }
}

void tick (pClock ptr) {
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
void show (pClock ptr, char end) {
    std::cout.fill('0');
    std::cout << std::setw(2) << ptr->hr << ":" << std::setw(2) << ptr->min << ":" << std::setw(2) << ptr->sec << end << std::flush;
}
