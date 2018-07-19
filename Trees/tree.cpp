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

int height(struct tree* root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		int ld=height(root->left);
		int rd=height(root->right);
		
		if(ld>rd)
			return ld+1;
		else
			return rd+1;
	}
}

bool check(struct tree* root)
{
	//check(root->left);
	//check(root->right);
	if(abs(height(root->left)-height(root->right))<=1)
	{
		//printf("%d %d",height(root->left),height(root->right));
		return true;
	}

	return false;
}
		

int main()
{
	struct tree* root=NULL;
	root=create(root,2);
	root=create(root,1);
	root=create(root,3);
	root=create(root,4);
	//root=create(root,5);
	
	inorder(root);
	bool s=check(root);
	if(s)
	printf("yes");
	else
	printf("no");
	
	/*bool flag=check(root);
	if(flag)
	{
		printf("\nBalanced");
	}
	else
	{
		printf("Not balanced");
	}*/
	
	return 0;
}
		

		
