#include "functions.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	struct node *top = NULL;

	printf("Printing empty: ");
	print_list(top);
	printf("\n");

	printf("-----\n");

	// Populating list
	top = insert(top, makeSong("lauder", "jid"));
	print_list(top);
	printf("\n");

	top = insert(top, makeSong("magnolia", "playboi carti"));
	print_list(top);
	printf("\n");

	top = insert(top, makeSong("moonlight", "xxxtentacion"));
	print_list(top);
	printf("\n");

	top = insert(top, makeSong("nuketown", "ski mask"));
	print_list(top);
	printf("\n");

	top = insert(top, makeSong("rip", "playboi carti"));
	print_list(top);
	printf("\n");

	printf("-----TESTING GET SONG WITH ARTIST AND NAME-----\n");
	printf("%s\n", getSong(top, "jid", "lauder"));

	printf("-----TESTING GET SONG BY ARTIST-----\n");
	printf("%s\n", getSongByArtist(top, "jid"));



	// top = remove_node(top, 7);
	// printf("Printing list (removed 7): ");
	// print_list(top);
	// printf("\n");
	//
	// top = remove_node(top, 0);
	// printf("Printing list (removed 0): ");
	// print_list(top);
	// printf("\n");
	//
	// top = remove_node(top, 9);
	// printf("Printing list (removed 9): ");
	// print_list(top);
	// printf("\n");
	//
	// top = remove_node(top, 9);
	// printf("Printing list (tried removing 9 again): ");
	// print_list(top);
	// printf("\n");
	//
	// printf("-----\n");
	//
	// free_list(top);
	// printf("List after freeing all nodes: ");
	// print_list(top);
	// printf("\n");
}
