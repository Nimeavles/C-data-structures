#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 100

struct Queue {
  int *queue_data[MAX_BUF];
  int *front;
  int *rear;
  int length;
};

void append(struct Queue *queue, int *value) {
  if (queue->front == NULL) {
    queue->front = value;
  }
  
  queue->rear = value;
  queue->queue_data[queue->length] = value;
  queue->length++;
}

void print_queue(struct Queue *queue) {
  if (queue->length == 0) {
    printf("No elements to print\n");
    exit(0);
  }

  for (int i = 0; i < queue->length; i++) {
    printf("%i\n", *queue->queue_data[i]);
  }
}

void shift(struct Queue *queue) {
  if (queue->length <= 0) {
    printf("There isn't any value on the queue.\n");
    exit(-1);
  }

  queue->length--; 
  for (int i = 0; i < queue->length; i++) {
    queue->queue_data[i] = queue->queue_data[i + 1];
  }
  queue->front = queue->queue_data[0];
}

int main() {
  struct Queue *queue = malloc(sizeof(struct Queue));
  int mock_data[MAX_BUF];

  for (int i = 0; i < MAX_BUF; i++) {
    mock_data[i] = i; 
    append(queue, &mock_data[i]);
  }

  shift(queue);
  shift(queue);
  print_queue(queue);
}