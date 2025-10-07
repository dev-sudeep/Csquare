#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Basic class system
#define class struct
#define object(classname) class classname*
#define def(returntype) returntype
#define method(returntype, name, ...) returntype (*name)(void* self, ##__VA_ARGS__)

// Constructor/destructor helpers
#define __init__(classname) classname##_new
#define __del__(classname) classname##_del

// Object lifecycle management
#define new(classname, ...) __init__(classname)(__VA_ARGS__)
#define delete(obj, classname) do { \
    if (obj) { \
        __del__(classname)(obj); \
        free(obj); \
        obj = NULL; \
    } \
} while(0)



/*
Usage Example:
--------------

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

// Usage
int main() {
    class Person* p = new(Person, "John", 30);
    if (p) {
        p->speak(p, "Hello!");
        delete(p, Person);
    }
    return 0;
}
*/
