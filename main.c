#include <csquare.h>
int main(){
    repeat(5, __i) {
        say("Hello, world! %d repeat\n", __i + 1);
        wait(1);
    }
    say("Hello world has been said 5 times!\n");
    char* result = inpy("print(2 + 2)");
    say("2 + 2 = %s\n", result);
    return 0;

}
