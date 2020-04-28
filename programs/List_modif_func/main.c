#include <stdio.h>
#include <stdlib.h>
#include "ADTList.h"
#include "allfunc.h"


int main() {

    List list = list_create(NULL);

     list_reverse_insert_next(list);

    list_print(list);
    
    list_destroy(list);
}

