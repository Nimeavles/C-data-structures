#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node *next;
	unsigned value;
};

struct Node *last(struct Node *head) {

	if (head->next == NULL) {
		return head;
	}

	struct Node *last = head;

	while (last->next != NULL) {
		last = head;
		last = last->next;
	}

	return last;
}

struct Node *add(struct Node *head, int value) {
	struct Node *new_node = malloc(sizeof(struct Node));

	new_node->next = head;
	new_node->value = value;

	return new_node;
}

static void print_list(struct Node *head) {
	if (head == NULL) {
		puts("empty list");
		exit(1);
	}

	printf("%d", head->value);

	for (head = head->next; head != NULL; head = head->next) {
		printf(" -> %d", head->value);
	}
	puts("");
}

int main() {
	struct Node *head = malloc(sizeof(struct Node));

	for (int i = 10; i > 0; i--) {
		head = add(head, i);
	}

	print_list(head);
}