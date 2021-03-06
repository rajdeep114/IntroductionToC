/* Integer linked list example.  CSE374 15au and previously. */

#include <stdlib.h>
#include <stdio.h>

// a single list node
struct List {
  int val;
  struct List * tail;
};

// return a new node containing integer x and a null tail field
struct List * from_int(int x) {
  struct List * ans =
    (struct List*)malloc(sizeof(struct List));
  ans->val = x;
  ans->tail = NULL;
  return ans;
}

// Return a new linked list containing the integers in p[0..len-1]
struct List * from_array(int len, int* p) {
  struct List * ans = NULL;
  int i;
  for (i = len-1; i >= 0; --i) {
    struct List * next = from_int(p[i]);
    next->tail = ans;
    ans = next;
  }
  return ans;
}

// free the whole list; better not use any other pointers
// to any list elements (and better not have a cicular list)
void free_list(struct List * lst) {
  while (lst != NULL) {
    struct List * next = lst->tail;  // must precede next statement
    free(lst);
    lst = next;
  }
}

// Print lst to stdout
void print(struct List * lst) {
  printf("\n[");
  while (lst != NULL) {        // could just say while (lst) ...
    printf(" %d ", lst->val);
    lst = lst->tail;
  }
  printf("]\n");
}

// == "x appears in lst"
int member(struct List *lst, int x) {
  for (; lst != NULL; lst = lst->tail)
    if (lst->val == x)
      return 1;
  return 0;
}

// length of lst (recursively)
int length1(struct List *lst) {
  if (lst == NULL)
    return 0;
  return 1 + length1(lst->tail);
}

// length of lst (iteratively)
int length2(struct List *lst) {
  int ans = 0;
  while (lst != NULL) {
    ++ans;
    lst = lst->tail;
  }
  return ans;
}

// sharing with lst2, copying of lst1
struct List* append1(struct List* lst1, struct List *lst2) {
  if (lst1 == NULL)
    return lst2;
  struct List * ans = append1(lst1->tail, lst2);
  struct List * first = from_int(lst1->val);
  first->tail = ans;
  return first;
}

// sharing with lst2, copying of lst1
struct List* append2(struct List*lst1, struct List *lst2) {
  if (lst1 == NULL)
    return lst2;
  struct List *result = from_int(lst1->val);
  struct List *prev   = result;
  lst1 = lst1->tail;
  while (lst1 != NULL) {
    struct List * first = from_int(lst1->val);
    prev->tail = first;
    prev = first;
    lst1 = lst1->tail;
  }
  prev->tail = lst2;
  return result;
}

// change lst1; return val only necessary if lst1 is NULL
// creates lots of _aliasing_
struct List* destructive_append(struct List*lst1, struct List*lst2) {
  struct List* ans;
  if (lst1 == NULL)
    return lst2;
  ans = lst1;
  while (lst1->tail != NULL)
    lst1 = lst1->tail;
  lst1->tail = lst2;
  return ans;
}

void test() {
  int arr1[5] = { 2, 4, 6, 8, 10};
  int arr2[3] = { 1, 2, 3};
  int arr3[4] = {20, 0, 0, 0};
  struct List * lst1 = from_array(5, arr1);
  struct List * lst2 = from_array(3, arr2);
  struct List * lst3 = from_array(4, arr3);
  print(lst1);
  print(lst2);
  print(lst3);
  print(append1(lst1, lst2));   // space leak!
  print(append2(lst1, lst2));   // space leak!
  print(lst1);
  print(lst2);
  destructive_append(lst1, lst2);   // ignore result b/c lst1 not NULL
  print(lst1);
  print(lst2);
  append1(lst1, lst1);
  destructive_append(lst1, lst1);   // An awfully bad idea! Why?
  // print(lst1);
  //space-leak: lst1 (cannot call free_list)
  //             not lst2 (now part of lst1)
  //             lst3 (can call free_list)
}

int main(int argc, char**argv) {
  test();
  return 0;
}
