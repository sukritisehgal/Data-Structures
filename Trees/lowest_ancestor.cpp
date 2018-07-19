#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};

struct tree* create(struct tree* root, int n)
{
	if(root==NULL)
	{
		root=(struct tree*)malloc(sizeof(struct tree));
		root->data=n;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		if(root->data>n)
		{
			root->left=create(root->left,n);
		}
		else
		{
			root->right=create(root->right,n);
		}
	}
	return root;
}

void inorder(struct tree* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\n",root->data);
		inorder(root->right);
	}
}

struct tree* lowest_ancestor(struct  tree* root, int n1, int n2)
{
	if(root->data>n1 && root->data>n2)
	{
		//printf("\nRoot->left : %d",root->left->data);
		return lowest_ancestor(root->left,n1,n2);
	}
	if(root->data<n1 && root->data<n2)
	{
		return lowest_ancestor(root->right,n1,n2);
	}
	return root;
}

int main()
{
	struct tree* root=NULL;
	root=create(root,10);
	root=create(root,11);
	root=create(root,8);
	root=create(root,5);
	root=create(root,9);
	
	inorder(root);
	printf("\n");
	
	struct tree* lowest=lowest_ancestor(root,5,9);
	
	printf("%d",lowest->data);
	
	return 0;
}
	
