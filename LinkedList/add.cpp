#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};

struct node* create(struct node* start)
{
	printf("\nEnter the number of elements");
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		if(start==NULL)
		{
			start=(struct node*)malloc(sizeof(struct node));
			scanf("%d",&start->data);
			start->next=NULL;
		}
		else
		{
			struct node* ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			struct node* temp=(struct node*)malloc(sizeof(struct node));
			scanf("%d",&temp->data);
			temp->next=NULL;
			ptr->next=temp;
		}
	}
	return start;
}
void display(struct node* start)
{
	struct node* ptr=start;
	while(ptr!=NULL)
	{
		printf("\n%d",ptr->data);
		ptr=ptr->next;
	}
}

struct node* add(struct node* start1, struct node* start2, struct node* sum)
{
	struct node* ptr1=start1;
	struct node* ptr2=start2;
	
	if(start1==NULL)
		return start2;
	
	if(start2==NULL)
		return start1;
		
	int carry=0;	
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(sum==NULL)
		{
			sum=(struct node*)malloc(sizeof(struct node));
			if(ptr1->data+ptr2->data<10)
			{
				sum->data=ptr1->data+ptr2->data;
			}
			else
			{
				carry=1;
				sum->data=(ptr1->data+ptr2->data)%10;
			}
			sum->next=NULL;
		}
		else
		{
			struct node* ptr=sum;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			struct node* temp=(struct node*)malloc(sizeof(struct node));
			if(ptr1->data+ptr2->data+carry<10)
			{
				temp->data=ptr1->data+ptr2->data+carry;
				carry=0;
			}
			else
			{
				temp->data=(ptr1->data+ptr2->data+carry)%10;
				carry=1;
			}
			temp->next=NULL;
			ptr->next=temp;
		}
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	if(ptr1==NULL && ptr2!=NULL)
	{
		struct node* ptr=sum;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		if(carry==1)
		{
			struct node* temp=(struct node*)malloc(sizeof(struct node));
			temp->data=ptr2->data+1;
			temp->next=ptr2->next;
			ptr->next=temp;
		}
		else
		{
			ptr->next=ptr2;
		}
	}
	if(ptr1!=NULL && ptr2==NULL)
	{
		struct node* ptr=sum;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		if(carry==1)
		{
			struct node* temp=(struct node*)malloc(sizeof(struct node));
			temp->data=ptr1->data+1;
			temp->next=ptr1->next;
			ptr->next=temp;
		}
		else
		{
			ptr->next=ptr1;
		}
	}
	
	return sum;
}

struct node* reverse(struct node* start)
{
	struct node* current=start,*prev=NULL,*forw;
	while(current!=NULL)
	{
		forw=current->next;
		current->next=prev;
		prev=current;
		current=forw;
	}
	return prev;
}
			
				
		
int main()
{
	struct node* start1=NULL;
	struct node* start2=NULL;
	
	start1=create(start1);
	start2=create(start2);
	
	struct node* start3=NULL;
	start3=add(start1,start2,start3);
	
	start3=reverse(start3);
	
	display(start3);
	
	return 0;
}
	