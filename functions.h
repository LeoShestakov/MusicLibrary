struct node{ 
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct node *head);
struct node * insert_front(struct node *head, int atFront);
struct node * free_list(struct node *head);
struct node * remove_node(struct node *head, int data);
