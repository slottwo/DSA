typedef struct set Set;

Set* create_set ();
int check_set (Set*);
int check_vet (int*);
void free_set(Set*);
void fill_set(Set*);
void attach_set(Set*);
int access_set(Set*, int);
int lenght_set(Set*);