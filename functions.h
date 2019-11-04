struct node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

void print_list(struct node *head);
struct node * makeSong(char *name, char *artist);
struct node * insert_front(struct node *head, struct node *toInsert);
int songcmp(struct node *songA, struct node *songB);
struct node * insert(struct node *head, struct node *toInsert);
struct node * getSong(struct node *head, char *artist, char *name);
struct node * getSongByArtist(struct node *head, char *artist);
struct node * getRandSong(struct node *head);
struct node * free_list(struct node *head);
struct node * remove_node(struct node *head, char *artist, char *name);
