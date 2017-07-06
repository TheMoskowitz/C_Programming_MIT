#include <stdio.h>
#include <stdlib.h>


struct tnode {
	int data;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *talloc(int data) {
	struct tnode *p = (struct tnode*)malloc(sizeof(struct tnode));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}

struct tnode *addnode(struct tnode *root, int data) {

	struct tnode *p = NULL;

	if (root == NULL) {
		p = talloc(data);
		return p;
	}

	if (data < root->data) { root->left = addnode(root->left, data); }
	else { root->right = addnode(root->right, data); }

	return root;
}

void preorder(struct tnode *head) {

	printf("%d ", head->data);
	if (head->left != NULL) preorder(head->left);
	if (head->right != NULL) preorder(head->right);

}

void inorder(struct tnode *head) {

	if (head->left != NULL) inorder(head->left);
	printf("%d ", head->data);
	if (head->right != NULL) inorder(head->right);
}

int deltree(struct tnode *root) {
	int counter = 0;
	if (root->right != NULL) counter += deltree(root->right);
	if (root->left != NULL) counter += deltree(root->left);
	counter++;
	free(root);
	return counter;
}

int main() {
	
	printf("Let's make a binary tree\n");
	struct tnode *head = talloc(3);
	head = addnode(head, 1);
	head = addnode(head, 0);
	head = addnode(head, 2);
	head = addnode(head, 8);
	head = addnode(head, 6);
	head = addnode(head, 5);
	head = addnode(head, 9);

	printf("preorder traversal:\n");
	preorder(head);
	printf("\n");

	printf("inorder traversal:\n");
	inorder(head);
	printf("\n");

	printf("Now let's delete the tree\n");
	int nodes_deleted = deltree(head);
	printf("%d nodes deleted\n", nodes_deleted);
	return 0;
}