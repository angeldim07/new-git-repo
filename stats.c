#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

int find_min(int size,int n[]) {
    int min = n[0],i;
    for (i=1; i<=size-1; i++) {
        if  (n[i]<min) 
            min = n[i];
    }
    return min;
}

int find_max(int size,int n[]) {
    int max = n[0],i;
    for (i=1; i<=size-1; i++) {
        if  (n[i]>max) 
            max = n[i];
    }
    return max;
}