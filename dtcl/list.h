struct node
{
  int value;
  struct node *prior;
  struct node *next;
};

struct header
{
  struct node *init;
  struct node *end;
  int length;
};
