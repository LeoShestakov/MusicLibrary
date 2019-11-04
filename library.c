#include<stdlib.h>
#include<string.h>
#include "library.h"
#include "functions.h"
// A-Z : 0-25
// 26 : other characters

int findIndex(char* string) {
	char* index = string[0] - 97;
	if (index > 25 || index < 0) {
		index = 26;
	}
	return index;
}

void add(char *name, char *artist) {
	struct node *toAdd = makeSong(name, artist);
	table[findIndex(artist)] = insert(table[findIndex(artist)], toAdd);
}

void printLib() {
	int counter;
	for (counter = 0; counter < 27; counter++) {
		if (table[counter] != NULL) {
			print_list(table[counter]);
		}
	}
	printf("\n");
}

struct node * search(char *name, char *artist) {
	int index = findIndex(artist);
	struct node *ans = getSong(table[index], artist, name);
	return ans;
}

struct node * searchByArtist(char *artist) {
	int index = findIndex(artist);
	struct node *ans = getSongByArtist(table[index], artist);
	return ans;
}

void printLetter(char *letter){
	int index = findIndex(letter);
	print_list(table[index]);
}

void printArtist(char *artist){
	int index = findIndex(artist);
	struct node *current = table[index];
	struct node *new = makeSong("placeholder", "placeholder");
	struct node *c = new;
	while(current != NULL){
		if (strcmp(current->artist, artist) == 0){
			c->next = current;
			c = c->next;
			current = current->next;
		} else {
			current = current->next;
		}
	}
	new = remove_node(new, "placeholder", "placeholder");
	print_list(new);
}

void del(char *name, char *artist) {
	int index = findIndex(artist);
	table[index] = remove_node(table[index], artist, name);
}

void clear() {
	int index = 0;
	for (; index < 27; index++) {
		table[index] = free_list(table[index]);
	}
}
