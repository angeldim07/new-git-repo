#include <stdio.h>
#include <stdbool.h>
#include "numb.h"

void swap(PNumber p, PNumber q) {
    struct Number temp =*p;
    *p =*q;
    *q = temp;
}