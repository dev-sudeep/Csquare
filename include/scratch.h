// scratch.h
// A Scratch-like header for C 
// License: MIT

#ifndef SCRATCH_H
#define SCRATCH_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// --- CONTROL BLOCKS ---

#define repeat(n, c) for (int c = 0; c < (n); c++)
#define forever while (1)
#define wait(s) do { sleep((unsigned int)(s)); } while (0)


// --- LOOKS BLOCKS ---

#define say printf


// --- SENSING BLOCKS ---

#define pick_random(a, b) ((rand() % ((b) - (a) + 1)) + (a))

// Internal: enable non-blocking input
static inline void __scratch_enable_raw_mode(void) {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO); // disable canonical mode & echo
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // non-blocking input
}

// key_pressed(char)
// Usage: if (key_pressed('a')) { ... }
static inline int key_pressed(char key) {
    __scratch_enable_raw_mode();
    int ch = getchar();
    if (ch == key) return 1;
    if (ch != EOF) ungetc(ch, stdin); // put back if not matched
    return 0;
}




#endif // SCRATCH_H
