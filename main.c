#include "functions.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
	struct node *top = NULL;

	printf("Printing empty: ");
	print_list(top);
	printf("\n");

	printf("-----\n");

	// Populating list
	char* name;
	char* artist;
	name = "LAUDER"
	artist = "JID"
	top = insert(top, name, artist);
	printf("Printing list (added %s by %s): ", name, artist);
	print_list(top);
	printf("\n");
	}

	printf("-----\n");

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
