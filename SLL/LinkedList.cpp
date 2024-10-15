#include <stdio.h>
#include <stdlib.h>

typedef struct Node* nodeptr;

struct Node {
	int data;
	nodeptr next;
};

typedef nodeptr LIST;
typedef nodeptr position;

int isLast(position P, LIST L) {
	return (P->next == NULL);
}

position find(int x, LIST L) {
	position P = L->next;
	while (P != NULL && P->data != x) {
		P = P->next;
	}
	return P;
}

position find_previous(int x, LIST L) {
	position P = L;
	while (P->next != NULL && P->next->data != x) {
		P = P->next;
	}
	return P;
}

void insert(int x, LIST L, position P) {
	position temp_cell = (position) malloc(sizeof(struct Node));
	if (temp_cell == NULL) {
		printf("fatal error");
	} else {
		temp_cell->data = x;
		temp_cell->next = P->next;
		P->next = temp_cell;
	}
}

void deleteNode(int x, LIST L) {  // Renamed to deleteNode
	position P = find_previous(x, L);
	if (P->next != NULL) {
		position temp_cell = P->next;
		P->next = temp_cell->next;
		free(temp_cell);
	}
}

int main() {
	// Example usage
	LIST L = (LIST) malloc(sizeof(struct Node));
	L->next = NULL;

	insert(10, L, L);
	insert(20, L, L);
	insert(30, L, find(10, L));

	printf("List after insertion: ");
	position P = L->next;
	while (P != NULL) {
		printf("%d -> ", P->data);
		P = P->next;
	}
	printf("NULL\n");

	deleteNode(20, L);  // Use the renamed function

	printf("List after deletion: ");
	P = L->next;
	while (P != NULL) {
		printf("%d -> ", P->data);
		P = P->next;
	}
	printf("NULL\n");

	return 0;
}

