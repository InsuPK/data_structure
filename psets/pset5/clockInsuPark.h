//아너코드: On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment. Signed: [박인수] Student Number: [22000292]

#ifndef CLOCK_H
#define CLOCK_H

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

// This is the end of the header guard
#endif