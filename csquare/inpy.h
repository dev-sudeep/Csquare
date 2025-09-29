// inpy.h
// Inline Python execution from C through pipes
// License: MIT

#ifndef INPY_H
#define INPY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- INLINE PYTHON BRIDGE ---

// Run a Python expression and capture output (first line only)
static inline char* inpy(const char* code) {
    static char buffer[1024];
    char cmd[1200];
    snprintf(cmd, sizeof(cmd), "python3 -c \"%s\" 2>/dev/null", code);

    FILE* pipe = popen(cmd, "r");
    if (!pipe) return NULL;

    if (fgets(buffer, sizeof(buffer), pipe) == NULL) {
        pclose(pipe);
        return NULL;
    }

    pclose(pipe);
    buffer[strcspn(buffer, "\n")] = '\0'; // trim newline
    return buffer;
}

// Run a Python script file
static inline int inpy_file(const char* filename) {
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "python3 %s", filename);
    return system(cmd);
}

#endif // INPY_H
