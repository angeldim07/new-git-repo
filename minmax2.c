#include <stdio.h>
#include <stdlib.h>
#include "stats.h"

int main(int argc,char* argv[]) {
    int n[argc-1],min,max,i;
    for (i=0; i<=argc-1; i++) 
        n[i] = atoi(argv[i]); 
    printf ("min = %d\nmax = %d\n",find_min(argc,n),find_max(argc,n));
}
