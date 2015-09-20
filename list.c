#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	list_t* curr;
	list_t* last;
	last = head;
	curr = last->next;
	if(curr == NULL){
		if(last->index < new_element->index){
			last->next = new_element;
		}
		else{
			head = new_element;
			new_element->next = last;
		}
		return head;
	}
	if(new_element->index < curr->index){
		if(last->index < new_element->index){
			last->next = new_element;
			new_element->next = curr;
		}
		else{
			new_element->next = last;
			head = new_element;
		}
		return head;
	}
	while(curr != NULL && curr->index < new_element->index){
		last = curr;
		curr = curr->next;
	}
	if(curr == NULL){
		last->next = new_element;
		new_element->next = NULL;
	}
	else{
		last->next = new_element;
		new_element->next = curr;
	}
	curr = head;
	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	list_t* curr;
	list_t* last;
	list_t* next;
	last = head;
	curr = last->next;
	next = curr->next;
	last->next = NULL;
	if(curr == NULL){
		return head;
	}
	else if(next == NULL){
		curr->next = last;
		return curr;
	}
	while(next != NULL){
		curr->next = last;
		last = curr;
		curr = next;
		next = curr->next;
	}
	curr->next = last;
	head = curr;
	return head;
}

