#include <errno.h>
#include <stddef.h>
#include <stdio.h>

struct node {
  struct node *next;
  int value;
};

struct node *last(struct node *head) {
  struct node *last = head;
  while (head != NULL) {
    last = head;
    head = head->next;
  }
  return last;
}

#define MAX_ALLOC 100

// simple bump allocator so we don't try and allocate thousands of nodes, if
// anything goes wrong with our algorithms.
static struct node static_alloc[MAX_ALLOC];
static size_t current_node_alloc;

struct node *alloc_node(int const value) {
  if (current_node_alloc == MAX_ALLOC) {
    errno = ENOMEM;
    return NULL;
  }
  struct node *ptr = &static_alloc[current_node_alloc++];
  ptr->next = NULL;
  ptr->value = value;
  return ptr;
}

struct node *cons(struct node *head, int const value) {
  struct node *new_node = alloc_node(value);
  if (new_node == NULL)
    return head;

  new_node->value = value;
  new_node->next = head;
  return new_node;
}

static void print_list(struct node *head) {
  if (head == NULL) {
    puts("empty list");
    return;
  }

  printf("%d", head->value);

  for (head = head->next; head != NULL; head = head->next) {
    printf(" -> %d", head->value);
  }
  puts("");
}

int main() {
  struct node *head = NULL;

  print_list(head);

  for (int i = 0; i < 10; i++) {
    head = cons(head, i);
  }

  print_list(head);
  print_list(last(head));
}
