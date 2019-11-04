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

	printf("-----TESTING GET SONG BY ARTIST AND NAME [JID: LAUDER]-----\n");
	printf("| %s : %s |\n", getSong(top, "jid", "lauder")->artist, getSong(top, "jid", "lauder")->name);

	printf("-----TESTING GET SONG BY ARTIST (SKI MASK)-----\n");
	printf("| %s : %s |\n", getSongByArtist(top, "ski mask")->artist, getSongByArtist(top, "ski mask")->name);

	printf("-----TESTING GET RANDOM SONG-----\n");
	struct node *rand = getRandSong(top);
	printf("| %s : %s |\n", rand->artist, rand->name);

	printf("-----TESTING REMOVE SONG [JID: LAUDER]-----\n");
	printf("List before removal: ");
	print_list(top);
	printf("\n");
	remove_node(top, "jid", "lauder");
	printf("List after removal: ");
	print_list(top);


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
