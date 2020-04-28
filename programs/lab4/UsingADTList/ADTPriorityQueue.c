///////////////////////////////////////////////////////////
//
// Υλοποίηση του ADT Priority Queue μέσω ταξινομημένης λίστας.
//
///////////////////////////////////////////////////////////

#include <stdlib.h>
#include <assert.h>

#include "ADTPriorityQueue.h"
#include "ADTList.h"			// Η υλοποίηση του PriorityQueue χρησιμοποιεί List


// Ενα PriorityQueue είναι pointer σε αυτό το struct
struct priority_queue {
	List list;		// η λίστα στην οποία αποθηκεύουμε τα στοιχεία
	CompareFunc compare;		// Η διάταξη
};

// Βοηθητικές συναρτήσεις ////////////////////////////////////////////////////////////////////////////


// Ανταλλάσει τις τιμές των κόμβων node1 και node2

void node_swap(Vector values,int node1,int node2) {
	Pointer value1 = vector_get_at(values,node1);
	Pointer value2 = vector_get_at(values,node2);
	vector_set_at(values,node1,value2);
	vector_set_at(values,node2,value1);
}

Vector vector_sorted_create(PriorityQueue pqueue,Vector values) {
	// Ταξινόμηση σε φθίνουσα σειρά
	int size = vector_size(values);
	int i;
	Vector vec = vector_create(size,NULL);
	for (i = 0; i < size-1; i++) 
		vector_set_at(vec,i,vector_get_at(values,i));

	// Χρησιμοποιούμε την Bubble Sort
	int j; 
    for (i = 0; i < size-1; i++)       
        for (j = 0; j < size-i-1; j++)  
            if ( pqueue->compare(vector_get_at(vec,j),vector_get_at(vec,j+1)) < 0 ) 
				node_swap(vec,j,j+1);
				
	return vec;
}

void list_initialize(PriorityQueue pqueue,Vector values) {
	int size = vector_size(values);
	ListNode node = LIST_BOF;
	for (int i = 0; i < size-1; i++) {
		list_insert_next(pqueue->list,node,vector_get_at(values,i));
		node = (node == LIST_BOF) ? list_first(pqueue->list) : list_next(pqueue->list,node);
	}
}


// Συναρτήσεις του ADTPriorityQueue //////////////////////////////////////////////////

PriorityQueue pqueue_create(CompareFunc compare, DestroyFunc destroy_value, Vector values) {
	assert(compare != NULL);	// LCOV_EXCL_LINE

	PriorityQueue pqueue = malloc(sizeof(*pqueue));
	pqueue->compare = compare;

	// Για την κλήση της συνάρτησης destroy_value, την περνάμε απλά στη list_create
	// οπότε θα καλείται αυτόματα όταν το στοιχείο αφαιρεθεί από τη λίστα.
	pqueue->list = list_create(destroy_value);

	// Αν values != NULL, ταξινομούμε και αρχικοποιούμε τη λίστα.
	if (values != NULL) {
		Vector sorted_values = vector_sorted_create(pqueue,values);

		list_initialize(pqueue,sorted_values);
	}

	return pqueue;
}

int pqueue_size(PriorityQueue pqueue) {
	return list_size(pqueue->list) ;
}

Pointer pqueue_max(PriorityQueue pqueue) {
	// Εφόσον η λίστα είναι ταξινομημένη σε φθίνουσα σειρά, max είναι το list_first
	return list_node_value(pqueue->list,list_first(pqueue->list));
}

void pqueue_insert(PriorityQueue pqueue, Pointer value) {
	ListNode node;
	for (node = LIST_BOF;
		 node != list_last(pqueue->list);
		 node = list_next(pqueue->list,node) ) {
		if (value >= list_node_value(pqueue->list,node)) 
			break;
	}
	list_insert_next(pqueue->list,node,value);
}

void pqueue_remove_max(PriorityQueue pqueue) {
	list_remove_next(pqueue->list,LIST_BOF);
}

DestroyFunc pqueue_set_destroy_value(PriorityQueue pqueue, DestroyFunc destroy_value) {
	// Απλά καλούμε την αντίστοιχη συνάρτηση της λίστας
	return list_set_destroy_value(pqueue->list, destroy_value);
}

void pqueue_destroy(PriorityQueue pqueue) {
	list_destroy(pqueue->list);

	free(pqueue);
}
