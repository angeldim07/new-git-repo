//#include "acutest.h"
#include <stdio.h>
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

// Επιστρέφει την τιμή στη θέση pos της λίστας list (μη ορισμένο αποτέλεσμα αν pos < 0 ή pos >= size)
Pointer list_get_at(List list, int pos) {
/*	bool condition = (pos>=0 && pos<list->size);
//	assert(condition);		// LCOV_EXCL_LINE

	// Διασχίζουμε τη λίστα μέχρι τη θέση  pos
	ListNode node = list->dummy;
	for (int i=1; i<=pos; i++) 
		node = node->next;

	if (condition) 
		return node->value;
	return NULL;
*/

	int i = 0;
	for (ListNode node = list_first(list); node != NULL; node = node->next) {
		if ((i++) == pos) 
			return node->value;
	}
	return NULL;


}

void test_get_at() {
	List list = list_create(NULL);
	int N = 100;
	int array[N];

	// Εισάγουμε δοκιμαστικές τιμές στον πίνακα , για να ελέγξουμε την test_find
	for (int i = 0; i < N; i++) {
		array[i] = i;
		list_insert_next(list, LIST_BOF, &array[i]);
	}

    printf("list size = %d\n",list_size(list));
    for(ListNode node = list_first(list);            
        node != LIST_EOF;                          
        node = list_next(list, node)) {
		printf("%d\n",*(int*)list_node_value(list,node));
	}

    int c = 1;
	// Εύρεση όλων των στοιχείων
	for (int i = 0; i < N; i++) {
		int* value = list_get_at(list, i);
		if (value != &array[N-1 - i]) c = 0;
    }
    if (c==0) printf("mphka estw mia\n");
	list_destroy(list);
}

int main(int argc, char** argv) {
    test_get_at();
    return 0;
}