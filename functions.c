#include "functions.h"
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
#include<time.h>

void print_list(struct node *head) {
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
	struct node *toFind = makeSong(name, artist);
	while (head != NULL && songcmp(toFind, head) != 0) {
		head = head->next;
	}
	free(toFind);
	return head;
}

struct node * getSongByArtist(struct node *head, char *artist){
	while (head != NULL && strcmp(artist, head->artist) != 0) {
		head = head->next;
	}
	return head;
}

struct node * getRandSong(struct node *head) {
	int length = 0;
	for (struct node * count = head; count != NULL; count = count->next) {
		length++;
	}
	srand(time(NULL));
	int chosen = rand() % length;
	for (chosen; chosen >0; chosen--) {
		head = head->next;
	}
	return head;
}

struct node * remove_node(struct node *head, char *artist, char *name) {
	struct node * toRemove = makeSong(name, artist);
    struct node * after = head->next;
    struct node * prev = head;

    if (songcmp(toRemove, head) == 0) {
        free(head);
        return after;
    }

    while (songcmp(toRemove, after) != 0) {
        prev = after;
        after = after->next;
        if (after == NULL) {
            return head;
        }
    }

    prev->next = after->next;
    free(after);
    return head;
}

struct node * free_list(struct node *head) {
	struct node * current = head;
    struct node * next = current;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    return NULL;
}