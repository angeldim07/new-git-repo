#include <stdio.h>
#define NDEBUG
#include <assert.h>
#include "stats.h"


int main() {
    FILE *fp;
    int line = 0;
    char str[LENGTH];
    char* lines[WORDS];
//    int same[WORDS] = {0};
    fp = fopen("words-10","r");
    while (line<=9 /*|| !feof(fp)*/) {
        fgets(str,LENGTH,fp);
        lines[line] = str;
        assert(line==0);
        printf("%d\n",line);
        for (int i=0;i<=line;i++) 
            puts(lines[i]);
        line++;
    }
    fclose(fp);
//    assert(line==0);
    return 0;
}