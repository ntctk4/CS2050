/*ntctk4
 * Nathaniel Callahan
 * lab 9
 * labe code:LEGO
 * */

#ifndef LIB_H_
#define LIB_H_

typedef struct node_
{
	int data;
	struct node_* left;
	struct node_* right;
}BST;

BST* insert(BST* tree, int data);
BST* find(BST* tree, int data);
void inorder(BST* tree);
void print(BST* tree);

#endif

