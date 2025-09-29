#include "csquare.h"
int main(){
    repeat(5) {
        say("Hello, world! %d repeat\n", __i + 1);
        wait(1);
    }
    say("Hello world has been said 5 times!\n");
    char* result = inpy("print(2 + 2)");
    say("InPy says 2 + 2 = %s\n", result);
    
    say("Starting Pygame window...\n");
    sm_init();
    wait(0.5); // Increased delay for initialization
    
    say("Drawing shapes...\n");
    
    // Draw multiple shapes
    sm_draw("circle", "(255, 0, 0), (400, 300), 50");  // Red circle
    sm_draw("rect", "(0, 255, 0), pygame.Rect(200, 200, 100, 100)");  // Green square
    sm_draw("line", "(0, 0, 255), (100, 100), (700, 500), 5");  // Blue line with thickness 5
    
    // Keep window open
    say("Shapes drawn. Window will close in 10 seconds...\n");
    wait(10);
    
    sm_quit();
    return 0;
}