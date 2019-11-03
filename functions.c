#include "functions.h"
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>

void print_list(struct node *head) {
	printf("|");
	if (head == NULL) {
		printf("|");
	}
	while (head != NULL) {
		printf(" %s: %s |", head->artist, head->name);
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
	if (strcmp(songA->artist, songB->artist) != 0) {
		return strcmp(songA->artist, songB->artist);
	}
	else {
		return strcmp(songA->name, songB->name);
	}
}

struct node * insert(struct node *head, struct node *toInsert) {
	struct node *current = head;
	struct node *prev = NULL;
	if (current == NULL || songcmp(toInsert, current) < 0) {
		return insert_front(head, toInsert);
	}
	prev = current;
	current = current->next;
	while (current != NULL && songcmp(toInsert, current) > 0) {
		prev = current;
		current = current->next;
	}
	prev->next = toInsert;
	toInsert->next = current;
	return head;
}


struct node * getSong(struct node *head, char *artist, char *name){
	struct node *current = head;
	while (current != NULL) {
		if (current->artist == artist && current->name == name){
			return current;
		} else {
			current = current->next;
		}
	}
}

struct node * getSongByArtist(struct node *head, char *artist){
	struct node *current = head;
	while (current != NULL) {
		if (current->artist == artist){
			return current;
		}
		else {
			current = current->next;
		}
	}
}

struct node * getRandSong(struct node *head) {
	int length = 0;
	for (struct node * count = head; count != NULL; count = count->next) {
		length++;
	}
	srand(time(NULL));
	int chosen = rand() % length;
	for (struct node * count = head; count >0; count--) {
		head = head->next;
	}
	return head;
}

// struct node * remove_node(struct node *head, char *artist, char *name) {
	// if (head->i == data)
		// return head->next;
	// else {
		// struct node *prev = head;
		// struct node *current = head->next;
		// bool foundData = 0;
		// while (foundData == 0 && current != NULL) {
			// if (current->artist == artist && current->name == name) {
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

// struct node * free_list(struct node *head) {
	// if (head->next != NULL) {
		// head->next = free_list(head->next);
	// }
	// free(head);
	// return head->next;
// }