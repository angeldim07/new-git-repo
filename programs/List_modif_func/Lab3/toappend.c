#include <stdio.h>
#include <stdlib.h>
#include "ADTList.h"


// Ενα List είναι pointer σε αυτό το struct
struct list {
	ListNode dummy;				// χρησιμοποιούμε dummy κόμβο, ώστε ακόμα και η κενή λίστα να έχει έναν κόμβο.
	ListNode last;				// δείκτης στον τελευταίο κόμβο, ή στον dummy (αν η λίστα είναι κενή)
	int size;					// μέγεθος, ώστε η list_size να είναι Ο(1)
	DestroyFunc destroy_value;	// Συνάρτηση που καταστρέφει ένα στοιχείο της λίστας.
};

struct list_node {
	ListNode next;		// Δείκτης στον επόμενο
	Pointer value;		// Η τιμή που αποθηκεύουμε στον κόμβο
};

// Δεσμεύει μνήμη για έναν ακέραιο, αντιγράφει το value εκεί και επιστρέφει pointer
int* create_int(int value) {
	int* pointer = malloc(sizeof(int));		// δέσμευση μνήμης
	*pointer = value;						// αντιγραφή του value στον νέο ακέραιο
	return pointer;
}


int compare_ints(Pointer a,Pointer b) {
	return *(int*)b - *(int*)a;
}


// Δημιουργεί μια λίστα με N στοιχεία. Αν array != NULL τότε εισάγονται τα στοιχεία του array, χωρίς destroy handler.
// Αν array == NULL τότε εισάγονται οι αριθμοί 0..Ν-1 σε νέα μνήμη, με free σαν destroy handler.
List create_test_list(int N, int array[]) {
	List list = list_create(array == NULL ? free : NULL);
	ListNode node = LIST_BOF;

	for (int i = 0; i < N; i++) {
		int* value = array == NULL ? create_int(i) : &array[i];
		list_insert_next(list, node, value);
		node = node == LIST_BOF ? list_first(list) : list_next(list, node);
	}

	return list;
}

Pointer list_get_at(List list, int pos) {
	int i = 0;
	for (ListNode node = list_first(list); node != NULL; node = node->next) {
		if ((i++) == pos) 
			return node->value;
	}
	return NULL;
}

void list_remove(List list, ListNode node) {
    //Εντοπίζει τον προηγούμενο κόμβο από τον node και καλεί την list_remove_next
    //άρα, διαγράφει τον node
    ListNode node_previous;
    if (node == list_first(list))
        list_remove_next(list,LIST_BOF);
    else {
        for (ListNode node_i = list_first(list); node_i != node; node_i = node_i->next) {
		    node_previous = node_i;
        }
        list_remove_next(list,node_previous);
    }
}

/*
void list_append(List list, List to_append) {
	//Μία συνδεδεμένη λίστα είναι κενή, αν last = dummy
	ListNode node_previous = list->last == list->dummy ? LIST_BOF : list->last;		// περιπτώσεις, αν list κενή
	ListNode node = to_append->last == to_append->dummy ? LIST_EOF : to_append->dummy->next;		// περιπτώσεις, αν to_append κενή
//	ListNode node_created;

	//περνω τις τιμες σε array
	int size = to_append->size;
	int i=0;
	int array[size];
	for(ListNode node = list_first(list);            
        node != LIST_EOF;                          
        node = list_next(list, node)) {
		array[i] = *(int*)list_node_value(list,node);
	}

	i=0;
	for(ListNode node = list_first(list);            
        node != LIST_EOF;                          
        node = list_next(list, node)) {
		printf ("array[%d] = %d\n",i,array[i]);
		i++;
	}

	for (i = 0; i < size; i++) {
		list_insert_next(list,node_previous,(Pointer)(&array[i]));
		node_previous = 
	}
*/
/*	free(to_append->dummy);
	to_append->dummy = NULL;
	int i = 0;
	while (node != LIST_EOF) {
		list_insert_next(list,node_previous,node->value);

		//Εμφανιση κομβου που μολις προστεθηκε
		node_created = list_find_node(list,node->value,compare_ints);
		if (node_created == LIST_EOF) printf ("mphka sthn node_created == LIST_EOF\n");
		printf("node %d = %d\n",i,*(int*)list_node_value(list,node_created));

		node_previous = node;
		node = node->next;
		i++;
//		if (node==LIST_EOF) printf ("skaei h func gia i=%d\n",i);
		
	}
	list->last = to_append->last;
//	list->size = list->size + to_append->size;

	printf("AFTER APPEND in func\nlist:\n");
	printf("list size = %d\n",list_size(list));
	i = 0;
    for(node = list_first(list);            
        node != LIST_EOF;                          
        node = list_next(list, node)) {
		printf("node %d = %d\n",i,*(int*)list_node_value(list,node));
		i++;
	}

	list_destroy(to_append);
}
*/

void list_append(List list, List to_append) {

	if (list->size == 0) {	
		printf("mphka list->size == 0\n");
		ListNode node_l = LIST_BOF;
		for(ListNode node_t = list_first(to_append);            
        	node_t != LIST_EOF;                          
        	node_t = list_next(to_append, node_t)) {
			list_insert_next(list,node_l,node_t->value);
			node_l = node_l == LIST_BOF ? list_first(list) : list_next(list, node_l);
		}

		printf("%d\n",list->size);
		int i = 0;
		for(ListNode node = list_first(list);            
			node != LIST_EOF;                          
			node = list_next(list, node)) {
			printf("node %d = %d\n",i,*(int*)list_node_value(list,node));
			i++;
		}

	}
	else if (to_append->size != 0) {
		ListNode node_previous = list->last;
		ListNode node = list_first(to_append);
		int i = 0;
		while (node != LIST_EOF) {
			list_insert_next(list,node_previous,node->value);
			node_previous = node_previous->next;
			node = node->next;
			i++;
		}
	}
//		list->last = to_append->last;
	list_destroy(to_append);
}


void test_append() {
	int N = 10;
	int array[2*N];	// 2*N στοιχεία!
    int c = 0;
	int i;

	for (i = 0; i < 2*N; i++) {
		array[i] = i;
//		printf ("array[%d] = %d\n",i,array[i]);
	}

	// append σε κενή λίστα
	List list = create_test_list(0, array);
//	printf("%d\n",list->size);
	List to_append = create_test_list(N, array);

//	printf("%d\n",list_size(list));


/*	i = 0;
	printf("BEFORE APPEND\nto_append:\n");
    for(ListNode node = list_first(to_append);            
        node != LIST_EOF;                          
        node = list_next(to_append, node)) {
		printf("node %d = %d\n",i,*(int*)list_node_value(to_append,node));
		i++;
	}
 */   

	list_append(list, to_append);

	//  printf("AFTER APPEND\nlist:\n");
	// // printf("list size = %d\n",list_size(list));
	// i = 0;
    // for(ListNode node = list_first(list);            
    //     node != LIST_EOF;                          
    //     node = list_next(list, node)) {
	// 	printf("node %d = %d\n",i,*(int*)list_node_value(list,node));
	// 	i++;
	// }

    if (!(list_size(list) == N)) {
        printf("1.mphka sthn list_size(list) == N\n");
        c++;
    }
//	else printf ("1 boba\n");
	for (int i = 0; i < N; i++) {
        if (!(list_get_at(list, i) == &array[i])) {
            printf("2.mphka sthn list_get_at(list, %d) == &array[%d]\n",i,i);
            c++;
        }
//		else printf ("2 boba\n");
    }
	// append κενής λίστας
	to_append = create_test_list(0, array);

	list_append(list, to_append);
    if (!(list_size(list) == N)) {
        printf("3.mphka sthn list_size(list) == N\n");
        c++;
    }
//	else printf ("3 boba\n");
	for (int i = 0; i < N; i++) {
        if (!(list_get_at(list, i) == &array[i])) {
            printf("4.mphka sthn list_get_at(list, %d) == &array[%d]\n",i,i);
            c++;
        }
//		else printf ("4 boba\n");
    }
		

	// append γεμάτης λίστας
	printf("\nappend γεμάτης λίστας\n");
	to_append = create_test_list(N, &array[N]);	// το δεύτερο μισό του πίνακα!

	printf("BEFORE APPEND\n");
	//εμφανιση των list , to_append
	i = 0;
    for(ListNode node = list_first(list);            
        node != LIST_EOF;                          
        node = list_next(list, node)) {
		printf("list node %d = %d\n",i,*(int*)list_node_value(list,node));
		i++;
	}
	i = 0;
    for(ListNode node = list_first(to_append);            
        node != LIST_EOF;                          
        node = list_next(to_append, node)) {
		printf("to_append node %d = %d\n",i,*(int*)list_node_value(to_append,node));
		i++;
	}
	//τελος εμφανισης


	list_append(list, to_append);


	printf("AFTER APPEND\n");
	//εμφανιση των list , to_append
	i = 0;
    for(ListNode node = list_first(list);            
        node != LIST_EOF;                          
        node = list_next(list, node)) {
		printf("list node %d = %d\n",i,*(int*)list_node_value(list,node));
		i++;
	}
	//τελος εμφανισης

    if (!(list_size(list) == 2*N)) {
        printf("5.mphka sthn list_size(list) == 2*N\n");
        c++;
    }
	for (int i = 0; i < 2*N; i++) {
        if (!(list_get_at(list, i) == &array[i])) {
            printf("6.mphka sthn list_get_at(list, %d) == &array[%d]\n",i,i);
            c++;
        }

    }
	if (c==0) printf("ola boba\n");	
	// destroy _μόνο_ τη list, η to_append καταστρέφεται από την append
	list_destroy(list);
}

int main() {
    test_append();
    return 0;
}
