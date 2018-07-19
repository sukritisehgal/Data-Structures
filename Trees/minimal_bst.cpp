#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};

struct tree* newNode(int data)
{
	struct tree* node=(struct tree*)malloc(sizeof(struct tree));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	
	return node;
}

struct tree* add(int array[],int low,int high)
{
	if(high<low)
	{
		return NULL;
	}
	//struct tree* root=NULL;
	int mid=(low+high)/2;
	struct tree* root=newNode(array[mid]);
	root->left=add(array,low,mid-1);
	root->right=add(array,mid+1,high);
	
	return root;
}

void inorder(struct tree* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d",root->data);
		inorder(root->right);
	}
}

int main()
{
	int array[]={1,4,5,6,7,8};
	struct tree* root=NULL;
	root=add(array,0,5);
	
	inorder(root);
	return 0;
}
	
	
	
	