#include "functions.h"
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>

void print_list(struct node *head) {
	printf("|");
	while (head != NULL) {
		printf("%s: %s|", head->artist, head->name);
		head = head->next;
	}
}

struct node * insert_front(struct node *head, struct node *toInsert) {
	toInsert->next = head;
	return toInsert;
}

struct node * makeSong(char *name, char *artist) {
	struct node *toInsert = malloc(sizeof(struct node));
	strcpy(toInsert->name, name);
	strcpy(toInsert->artist, artist);
	return toInsert;
}

int songcmp(struct node *songA, struct node *songB) {
	if (songA->artist < songB->artist) {
		return -1;
	}
	else if (songA->artist > songB->artist) {
		return 1;
	}
	else {
		if (songA->name < songB->name) {
			return -1;
		}
		else if (songA->name > songB->name) {
			return 1;
		}
	}
	return 0;
}

struct node * insert(struct node *head, struct node *toInsert) {
	struct node *current = head->next;
	struct node *prev = head;
	struct node * new = insert_front(NULL, toInsert);
	if (current == NULL || songcmp(toInsert, current) < 0) {
		return insert_front(head, toInsert);
	}
	while (current != NULL && songcmp(toInsert, current) > 0) {
		prev = current;
		current = current->next;
	}
	new->next = current;
	prev->next = new;
	return head;
}



// struct node * free_list(struct node *head) {
	// if (head->next != NULL) {
		// head->next = free_list(head->next);
	// }
	// free(head);
	// return head->next;
// }

// struct node * remove_node(struct node *head, int data) {
	// if (head->i == data)
		// return head->next;
	// else {
		// struct node *prev = head;
		// struct node *current = head->next;
		// bool foundData = 0;
		// while (foundData == 0 && current != NULL) {
			// if (current->i == data) {
				// prev->next = current->next;
				// foundData = 1;
			// }
			// else {
				// prev = current;
				// current = current->next;
			// }
		// }
		// return head;
	// }
// }
