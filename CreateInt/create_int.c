//Κάνει refresh την διεύθυνση μίας ακέραιας μεταβλητής
//Χρήσιμη συνάρτηση η create_int (είπε ο Χατζηκο)

#include <stdio.h>
#include <stdlib.h>


int* create_int(int value) {
    int* p = malloc(sizeof(int));
    *p = value;
    return p;
}

//test της create_int στην main

int main(void) {
    int a = 1;
    printf ("Before, (long)&a = %ld\n",(long)&a);
    int* q = create_int(a);
    printf ("After, (long)&a = %ld\n",(long)q);
    return 0;
}