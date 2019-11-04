struct node * table[27];
// A-Z : 0-25
// 26 : other characters

int findIndex(char* string);
void add(char *name, char *artist);
void printLib();
struct node * search(char *name, char *artist);
struct node * searchByArtist(char *artist);
void printLetter(char* letter);
void printArtist(char* artist);

struct node * shuffle();
void del(char *name, char *artist);
void clear();
