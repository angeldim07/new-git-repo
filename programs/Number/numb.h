#include <stdio.h>
#include <stdbool.h>

#define INT1 5
#define INT2 77
#define FL1 6.3
#define FL2 83.4

struct Number {
    int i;
    long int li;
    float f;
    double d;
    bool b;
};

typedef struct Number* PNumber;

void swap(PNumber p, PNumber q);