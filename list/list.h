typedef struct element Element;
typedef struct element *List;
typedef struct data Data;

struct data
{
    int id;
    char* name;
};

int check (void*);
List* create_ls ();
Data* create_dt (int, char*);
int access_ls (List*, Data, int, Data*);
int access_ls_by_id (List*, int, Data*);
int access_ls_by_name (List*, char*, Data*);
int insert_ls (List*, Data);
int remove_ls (List*);
int destroy_ls (List*);
