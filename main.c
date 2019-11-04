#include "library.h"
#include "functions.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	printf("-----LINKED LIST TESTS-----\n\n");
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

	printf("-----TESTING GET SONG BY ARTIST [SKI MASK]-----\n");
	printf("| %s : %s |\n", getSongByArtist(top, "ski mask")->artist, getSongByArtist(top, "ski mask")->name);

	printf("-----TESTING GET RANDOM SONG-----\n");
	struct node *rand = getRandSong(top);
	printf("| %s : %s |\n", rand->artist, rand->name);

	printf("-----TESTING REMOVE SONG [JID: LAUDER]-----\n");
	printf("List BEFORE removal: ");
	print_list(top);
	printf("\n");
	top = remove_node(top, "jid", "lauder");
	printf("List AFTER removal: ");
	print_list(top);
	printf("\n");

	printf("-----\n");

	top = free_list(top);
	printf("List after freeing all nodes: ");
	print_list(top);
	printf("\n\n");

	printf("-----MUSIC LIBRARY TESTS-----\n\n");

	// Populating list
	add("lauder", "jid");
	add("magnolia", "playboi carti");
	add("moonlight", "xxxtentacion");
	add("nuketown", "ski mask");
	add("rip", "playboi carti");

	printf("-----PRINTING INTIALIZED LIBRARY-----\n");
	printLib();
	printf("-----TESTING SEARCH SONG [PLAYBOI CARTI : MAGNOLIA]-----\n");
	printf("%s : %s\n", search("magnolia", "playboi carti")->artist, search("magnolia", "playboi carti")->name);
	printf("-----TESTING SEARCH SONG BY ARTIST [XXXTENTACION]-----\n");
	printf("%s : %s\n", searchByArtist("xxxtentacion")->artist, searchByArtist("xxxtentacion")->name);
	printf("-----TESTING PRINT LETTER [P]-----\n");
	printLetter("p");
}
