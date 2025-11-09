#include "csquare.h"

// Forward declaration
class Person;

// Define a class
class Person {
    char* name;
    int age;
    method(void, speak, const char* msg);
};

// Method implementation
def(void) Person_speak(void* self_ptr, const char* msg) {
    class Person* self = (class Person*)self_ptr;
    printf("%s says: %s\n", self->name, msg);
}

// Constructor
def(class Person*) Person_new(const char* name, int age) {
    class Person* self = malloc(sizeof(class Person));
    if (!self) return NULL;
    
    self->name = strdup(name);
    if (!self->name) {
        free(self);
        return NULL;
    }
    self->age = age;
    self->speak = Person_speak;
    return self;
}

// Destructor
def(void) Person_del(class Person* self) {
    if (self && self->name) free(self->name);
}

int main(){
    repeat(5, __i) {
        say("Hello, world! %d repeat\n", __i + 1);
        wait(1);
    }
    say("Hello world has been said 5 times!\n");
    say("InPy says ");
    integer result = atoi(inpy("print(2 + 2)"));
    say("2 + 2 = %d\n", result);

    say("Starting Pygame window...\n");
    sm_init(1280, 800, "Line, Square and Circle", SM_FULLSCREEN "|" SM_SCALE);
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
    say("Pygame window closed.\n");

    printf("Using Coop OOP features:\n");
    // Demonstrate Coop OOP
    object(Person) person = Person_new("Alice", 30);
    printf("Created Person: %s, Age: %d\n", person->name, person->age);
    
    if (person) {
        person->speak(person, "Hello, world!");
        Person_del(person);
    }

    return 0;
}
