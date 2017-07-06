#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node *nalloc(int data) {
	struct Node *p = (struct Node*)malloc(sizeof(struct Node));
	if (p != NULL) {
		p->data = data;
		p->next = NULL;
	}
	return p;
}

void display(struct Node *head) {

	printf("%d", head->data);
	while(head->next != NULL) {
		head = head->next;
		printf("-%d", head->data);
	}
	printf("\n");

}

struct Node *addback(struct Node *head, int data) {
	struct Node *new_node = nalloc(data);
	struct Node *ptr = head;
	while (ptr->next != NULL) ptr=ptr->next;
	ptr->next = new_node;
	return head;
}

struct Node *find(struct Node *head, int data) {
	while (head != NULL) {
		if (head->data == data) return head;
		head = head->next;
	}
	return NULL;
}

struct Node *delnode(struct Node *head, struct Node *pelement) {
	
	if (head->next == NULL) return NULL;
	if (head == pelement) return head->next;

	if (pelement->next == NULL) {
		struct Node *ptr = head;
		while (ptr->next != pelement) ptr=ptr->next;
		free(pelement);
		ptr->next = NULL;
	} else {
		pelement->data = pelement->next->data;
		struct Node *nextptr = pelement->next;
		pelement->next = pelement->next->next;
		free(nextptr);
	}
	return head;
}

void freelist(struct Node *head) {
	struct Node *ptr = head;
	while(ptr != NULL) {
		head = ptr;
		ptr = ptr->next;
		free(head);
	}
}

int main() {

	struct Node *head = nalloc(5);

	struct Node *node2 = nalloc(10);
	head->next = node2;

	head = addback(head, 25);

	display(head);

	printf("Is 10 in the list?\n");
	struct Node *target = find(head, 10);
	if (target == NULL) {
		printf("Node not found\n");
	} else {
		printf("Node found - yes it is!\n");
	}
	printf("Now let's get rid of it\n");
	head = delnode(head, target);

	display(head);

	printf("Now let's delete the whole list\n");

	freelist(head);

	printf("Linked list deleted!\n");

	return 0;
}