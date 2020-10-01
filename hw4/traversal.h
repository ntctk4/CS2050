/*
 *Nathaniel Callahan
 *ntctk4
 *hw4
 *lab E
 *
 * */

#ifndef LIB_H_
#define LIB_H_

typedef struct node_//data structure used to make a Balanced BST/
{
	int  data;
	struct node_* left;
	struct node_* right;
} BST;

void preorder(BST* root);
void inorder(BST* root);
void breadthFirst(BST* root);


#endif
