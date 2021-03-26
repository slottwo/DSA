typedef struct element Element;
typedef struct element *List;
typedef struct data Data;

struct data
{
    int id;
    char name[15];
};

List* create ();
Element access (List*);
void insert (List*);
void destroy (List);
