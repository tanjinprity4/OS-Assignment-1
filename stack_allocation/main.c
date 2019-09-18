// stack_allocation/main.c
// 
// (Bad) stack allocation example.
// 

#include <stdio.h>

struct tree {
  int value;
  struct tree *left_child;
  struct tree *right_child;
};

typedef struct tree tree_t;

tree_t *make_tree(int value) {
  tree_t t;
  t.value = value;
  tree_t *t_pointer = &t;
  return t_pointer;
}

void make_other_things() {
  int fun_array[7] = {1,2,3,4,5,6,7};
  fun_array[5] = 20;
  char fun_string[25] = "I love programming in C!";
  char some_character = fun_string[6];
  int magic_number = some_character + 50;
}

int main() {
  tree_t *t1 = make_tree(3);
  printf("The value of t1 is %d\n", t1->value);

  tree_t *t2 = make_tree(4); // t2 Reuses the same memory as t1.
  printf("The value of t2 is %d, not surprising\n", t2->value);
  printf("But the value of t1 is now %d!\n", t1->value); // Value of t1 gone after the end of make_tree() function.

  printf("Making other things...\n");
  make_other_things();

  printf("Even worse, the value of t1 is now %d\n", t1->value);
  printf("And the value of t2 is %d\n", t2->value);
  return 0;
}

/***
 * Output: 
 * The value of t1 is 3
 * The value of t2 is 4, not surprising
 * But the value of t1 is now 4!
 * Making other things...
 * Even worse, the value of t1 is now 1763731310
 * And the value of t2 is 1763731310
*/

