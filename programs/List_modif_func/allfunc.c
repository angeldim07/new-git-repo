#include <stdio.h>
#include <stdlib.h>
#include "ADTList.h"
#include "allfunc.h"


// Δεσμεύει μνήμη για έναν ακέραιο, αντιγράφει το value εκεί και επιστρέφει pointer
int* create_int(int value) {
	int* pointer = malloc(sizeof(int));		// δέσμευση μνήμης
	*pointer = value;						// αντιγραφή του value στον νέο ακέραιο
	return pointer;
}

int compare_ints(Pointer a,Pointer b) {
	return *(int*)b - *(int*)a;
}

/*void list_reverse_insert_next(List list) {
        //insertion ενός memory block (πχ λίστα) απο το τελος προς την αρχη
    for (int i = 0; i < 100; i++) {
		list_insert_next(list, LIST_BOF, create_int(i));
	}
}*/

void list_reverse_insert_next(List list) {
        //insertion ενός memory block (πχ λίστα) απο το τελος προς την αρχη
		int* p;
		ListNode node_created;
    for (int i = 0; i < 100; i++) {
		p = create_int(i);
		list_insert_next(list, LIST_BOF,p);
		node_created = list_find_node(list,p,compare_ints);
		if (node_created == LIST_EOF) printf ("mphka sthn node_created == LIST_EOF\n");
	}
}

void list_print(List list) {
    //εκτύπωση λίστας απτην αρχή προς το τέλος
	int i = 0;
    for(ListNode node = list_first(list);            
        node != LIST_EOF;                          
        node = list_next(list, node)) {
		printf("node %d = %d\n",i,*(int*)list_node_value(list,node));
		i++;
	}
}