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

// Δεσμεύει μνήμη για έναν ακέραιο, αντιγράφει το value εκεί και επιστρέφει pointer
int* create_int(int value) {
	int* pointer = malloc(sizeof(int));		// δέσμευση μνήμης
	*pointer = value;						// αντιγραφή του value στον νέο ακέραιο
	return pointer;
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

void test_remove() {
	int N = 1000;
	List list = create_test_list(N, NULL);
    int c = 0;

	// Διαγραφή του δεύτερου στοιχείου
	ListNode first = list_first(list);
	list_remove(list, list_next(list, first));	
    if (!(list_size(list) == N - 1)) {
        printf("1.mphka sthn list_size(list) == N - 1\n");
        c++;
    }
    if (!(*(int*)list_node_value(list, list_next(list, first)) == 2)) {
        printf("2.mphka sthn *(int*)list_node_value(list, list_next(list, first)) == 2\n");
        c++;
    }

	// Διαγραφή του πρώτου
	list_remove(list, list_first(list));	
    if (!(list_size(list) == N - 2)) {
        printf("3.mphka sthn list_size(list) == N - 2\n");
        c++;
    }
    if (!(*(int*)list_node_value(list, list_first(list)) == 2)) {
        printf("4.mphka sthn *(int*)list_node_value(list, list_first(list)) == 2\n");
        c++;
    }
	

	// Διαδοχική διαγραφή του τελευταίου στοιχείου μέχρι να αδειάσει η λίστα
	for (int i = 0; i <= N - 3; i++) {
        if (!(*(int*)list_node_value(list, list_last(list)) == N-1 - i)) {
            printf("5.mphka sthn *(int*)list_node_value(list, list_last(list)) == N-1 - i\n");
            c++;
        }
		list_remove(list, list_last(list));	
        if (!(list_size(list) == N - 3 - i)) {
            printf("6.mphka sthn list_size(list) == N - 3 - i\n");
            c++;
        }
		break;
	}
    if (c==0) printf("ola boba\n");

	list_destroy(list);
}

int main() {
    test_remove();
    return 0;
}