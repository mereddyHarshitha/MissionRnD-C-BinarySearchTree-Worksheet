/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void array(struct node *root, int position, int *arr,int *index){

	if (root == NULL)
		return;

	if (position == 0){
		arr[*index] = root->data;
		*index = *index + 1;
	}
	else{
		array(root->right, position - 1, arr, index);
		array(root->left, position - 1, arr, index);
	}

}
int getHeight(struct node *root){

	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	int lHeight = getHeight(root->left);
	int rHeight = getHeight(root->right);

	if (lHeight > rHeight)
		return lHeight + 1;
	else
		return rHeight + 1;
}

int power(int num1, int num2){

	int i = 0;
	int res=1;
	for (i = 0; i < num2; i++){
		res = res*num1;
	}
	return res;
}

int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
		return NULL;

	int height = getHeight(root);
	int arrSize = power(2, height) - 1;

	int *arr = (int*)malloc(arrSize*sizeof(int));
    
	int position;
	int index = 0;
	
	for (position = 0; position < height; position++)
		array(root, position, arr, &index);
	
	return arr;

}
