#include <stdio.h>
#include <stdlib.h>
#define MAX_BUF 10

/*
  MOCK_DATA = {12, 22, 45, 25, 78}

  HASH RESULT -> { 2, 2, 0, 0, 0, 3 }
   -------
 0 |__22__| -> 45 -> 25
 1 |______| -> 
 2 |__12__| -> 22 
 3 |__78__| ->
 4 |______| ->
 5 |______| ->
 6 |______| ->
 7 |______| ->
 8 |______| ->
   -------
*/

struct Node {
  int value;
  struct Node *next;
};

struct List {
  struct Node *head;
};

struct Map {
  struct List *list[MAX_BUF];
};

int hash(int value) {
  return value % 5;
}

void append(struct Map *map, struct Node *new_node) {
  //Hash the value and save it on a variable
  int hashed_value = hash(new_node->value);

  //Each array position will be a LL as we are solving colisions with it.  
  //Make sure that the address were we are going to store
  //data is free. If not, we will prepend the value on the head of the LL. 
  if (map->list[hashed_value] == NULL) {
    struct List *ll = malloc(sizeof(struct List));
    ll->head = new_node;
    map->list[hashed_value] = ll;
  }else{
  //We assign the address of the head to the next value of the Node
  //And then we assign the new node to the LL head  
    new_node->next = map->list[hashed_value]->head;
    map->list[hashed_value]->head = new_node;
  }
}

void *get(int index, struct Map *map) {
  int hashed_pos = hash(index);
  if (map->list[hashed_pos] == NULL) {
    printf("empty field");
    return NULL;
  }

  return map->list[hashed_pos];
}

int main() {
  struct Map *hash_map = malloc(sizeof(*hash_map));
  int mock_data[] = {12, 22, 45, 25, 78};

  for (int i = 0; i < 5; i++) {
    struct Node *new_node = malloc(sizeof(struct Node));
    new_node->value = mock_data[i];
    append(hash_map, new_node);
  }

  struct List *value1 = get(2, hash_map);
}