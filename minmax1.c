#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc,char* argv[]) {
    int n[argc-1],min,max,i;
    for (i=0; i<=argc-1; i++) 
        n[i] = atoi(argv[i]); 
    //min = max = n[0];
    min = INT_MAX;
    max = INT_MIN;

    for (i=0; i<=argc-1; i++) {
        if  (n[i]<min) 
            min = n[i];
        if  (n[i]>max) 
            max = n[i];   
    }
    printf ("min = %d\nmax = %d\n",min,max);
    return 0;
}