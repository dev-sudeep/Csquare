#include "inpy.h"
#include "scratch.h"
#include <stdio.h>

FILE* messages_py;
FILE* srvdrawer;

void sm_init() {
    const char *py_code =
"import pygame\n"
"import time\n"
"import os\n"
"\n"
"pygame.init()\n"
"screen = pygame.display.set_mode((800, 600))\n"
"pygame.display.set_caption(\"Python Command Window\")\n"
"\n"
"# Store shapes to be drawn\n"
"draw_commands = []\n"
"\n"
"running = True\n"
"while running:\n"
"    for event in pygame.event.get():\n"
"        if event.type == pygame.QUIT:\n"
"            running = False\n"
"\n"
"    if os.path.exists(\"quit.flag\"):\n"
"        running = False\n"
"\n"
"    screen.fill((255, 255, 255))\n"
"\n"
"    # Execute any new commands\n"
"    if os.path.exists(\"msgqueue.py\"):\n"
"        with open(\"msgqueue.py\", \"r\") as f:\n"
"            code = f.read()\n"
"        if code.strip():\n"
"            try:\n"
"                draw_commands.append(code)\n"
"            except Exception as e:\n"
"                print(\"Error in command file:\", e)\n"
"        open(\"msgqueue.py\", \"w\").close()\n"
"\n"
"    # Draw all stored shapes\n"
"    for cmd in draw_commands:\n"
"        try:\n"
"            exec(cmd, {\"pygame\": pygame, \"screen\": screen})\n"
"        except Exception as e:\n"
"            print(\"Error executing command:\", e)\n"
"\n"
"    pygame.display.flip()\n"
"    time.sleep(0.05)\n"
"\n"
"pygame.quit()\n";

    /// Open files safely
    messages_py = fopen("msgqueue.py", "w+");
    if (!messages_py) {
        perror("Failed to open msgqueue.py");
    }

    srvdrawer = fopen("smotion_pygame_server_draw.py", "w");
    if (!srvdrawer) {
        perror("Failed to open smotion_pygame_server_draw.py");
        return;
    }

    fprintf(srvdrawer, "%s", py_code);
    fclose(srvdrawer);

    // Run the server in background using system command
    #ifdef __APPLE__
    system("python3 smotion_pygame_server_draw.py &");
    #else
    system("python smotion_pygame_server_draw.py &");
    #endif
    
    // Small delay to ensure window is created
    wait(0.5);
}

#define sm_draw(shape, ...) do { \
    if (messages_py) { \
        fprintf(messages_py, "pygame.draw.%s(screen, %s)\n", shape, __VA_ARGS__); \
        fflush(messages_py); \
    } \
} while (0)

void sm_quit() {
    // Close message queue file
    if (messages_py) {
        fclose(messages_py);
        messages_py = NULL;
    }

    // Create quit flag
    FILE *f = fopen("quit.flag", "w");
    if (f) fclose(f);

    // Wait for Python to detect the flag
    wait(0.5);

    // Cross-platform process termination
    #ifdef _WIN32
        system("taskkill /F /IM python.exe /FI \"WINDOWTITLE eq Python Command Window\"");
    #elif defined(__APPLE__)
        system("pkill -f smotion_pygame_server_draw.py");
    #else
        system("killall -f python3 2>/dev/null || killall python 2>/dev/null");
    #endif

    // Clean up files
    remove("quit.flag");
    remove("msgqueue.py");
    remove("smotion_pygame_server_draw.py");
}
