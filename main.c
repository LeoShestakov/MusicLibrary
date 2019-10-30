#include "functions.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
	struct node *top = malloc(sizeof(struct node));
	
	printf("Printing empty: ");
	print_list(top);
	printf("\n");
	
	printf("-----\n");
	
	int i;
	// Populating list
	for (i = 9; i >= 0; i--) {
		top = insert_front(top, i);
		printf("Printing list (added %d to front): ", i);
		print_list(top);
		printf("\n");
	}
	
	printf("-----\n");
	
	top = remove_node(top, 7);
	printf("Printing list (removed 7): ");
	print_list(top);
	printf("\n");
	
	top = remove_node(top, 0);
	printf("Printing list (removed 0): ");
	print_list(top);
	printf("\n");
	
	top = remove_node(top, 9);
	printf("Printing list (removed 9): ");
	print_list(top);
	printf("\n");
	
	top = remove_node(top, 9);
	printf("Printing list (tried removing 9 again): ");
	print_list(top);
	printf("\n");
	
	printf("-----\n");
	
	free_list(top);
	printf("List after freeing all nodes: ");
	print_list(top);
	printf("\n");
}
