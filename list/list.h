struct data
{
  int id;
  char name[4];
};

typedef struct data Data;
typedef struct node *List;

List *createList();
void freeList(List *);
int isNull(void *);
int isEmpty(List *);
int length(List *);
int insertTop(List *, Data);
int insertBot(List *, Data);
int insertOrderly(List *, Data);
int removeTop(List *);
int removeBot(List *);
int removeById(List *, int);
int findOne(List *, int, Data *);
int accessByIndex(List *, int, Data *);
int printList(List *);
