#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
	struct tree* nextright;
};

struct tree* create(struct tree* root, int n)
{
	if(root==NULL)
	{
		root=(struct tree*)malloc(sizeof(struct tree));
		root->data=n;
		root->left=NULL;
		root->right=NULL;
		root->nextright=NULL;
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
void connectRecur(struct tree* p)
{
	if(p==NULL)
	{
		return;
	}
	if(p->left)
	{
		p->left->nextright=p->right;
	}
	if(p->right)
	{
		if(p->nextright)
		{
			p->right->nextright=p->nextright->left;
		}
		else
		{
			p->right->nextright=NULL;
		}
	}
}
void connect(struct tree* node)
{
	if(node->nextright==NULL)
	{
		connectRecur(node);
	}
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
	
	connect(root);
	
	printf("\nnextRight of %d is %d\n",root->data,(root->nextright?root->nextright->data:-1));
	printf("\nnextRight of %d is %d\n",root->left->data,(root->left->nextright?root->left->nextright->data:-1));
	
	return 0;
}
	
	
