#include "functions.h"
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

void print_list(struct node *head) {
	printf("|");
	while (head->next != NULL) {
		printf("%s: %s|", head->artist, head->name);
		head = head->next;
	}
}

struct node * insert_front(struct node *head, int atFront) {
	struct node *toInsert = malloc(sizeof(struct node));
	toInsert->next = head;
	toInsert->i = atFront;
	return toInsert;
}

struct node * free_list(struct node *head) {
	if (head->next != NULL) {
		head->next = free_list(head->next);
	}
	free(head);
	return head->next;
}

struct node * remove_node(struct node *head, int data) {
	if (head->i == data)
		return head->next;
	else {
		struct node *prev = head;
		struct node *current = head->next;
		bool foundData = 0;
		while (foundData == 0 && current != NULL) {
			if (current->i == data) {
				prev->next = current->next;
				foundData = 1;
			}
			else {
				prev = current;
				current = current->next;
			}
		}
		return head;
	}
}
