#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFF 100

struct Stack {
  int *first;
  int *last;
  int *stack_items[MAX_BUFF];
  int length;
};

void append(struct Stack *stack, int *value_to_add) {
  if (stack->first) {
    stack->last = value_to_add;
  }
  stack->first = value_to_add;
  stack->stack_items[stack->length] = value_to_add;
  stack->length++;
}

void pop(struct Stack *stack) {
  if (stack->length <= 0) {
    printf("No value to delete\n");
    exit(-1);
  }

  stack->first = stack->stack_items[stack->length - 1];
  stack->length--; 
  stack->stack_items[stack->length] = NULL;
}

void print_stack(struct Stack *stack) {
  if (stack->length == 0) {
    printf("No elements to print\n");
    exit(0);
  }

  for (int i = 0; i < stack->length; i++) {
    printf("%i\n", *stack->stack_items[i]);
  }
}

int main() {
  struct Stack *stack = malloc(sizeof(struct Stack));
  int mock_data[MAX_BUFF];
  
  for (int i = 0; i < MAX_BUFF; i++) {
    mock_data[i] = i;
    append(stack, &mock_data[i]);
  }

  pop(stack);
  print_stack(stack);

}