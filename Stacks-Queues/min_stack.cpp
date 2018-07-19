#include<stdio.h>
class Stack
{
	public:
	int top;
	int array[100];
	void push(int[],int&,int);
	int pop(int[],int&);
	int min(int[],int&);
};

int main()
{
	Stack s;
	s.top=-1;
	s.push(s.array,s.top,1);
	s.push(s.array,s.top,3);
	s.push(s.array,s.top,2);
	

	printf("%d\n",s.pop(s.array,s.top));
	printf("%d\n",s.min(s.array,s.top));
	printf("%d\n",s.pop(s.array,s.top));
	
	return 0;
}

void Stack::push(int array[],int &top, int element)
{
	int temp[100];
	int j=-1; // Counter for temp array
	if(top==-1)
	{
		top++;
		array[top]=element;
	}
	else if(top==99)
	{
		printf("\nOverflow");
	}
	else if(array[top]>=element)
	{
		top++;
		array[top]=element;
	}
	else
	{
		int i;
		for(i=top;i>=0;i--)
		{
			if(array[top]>=element)
			{
				break;
			}
			else
			{
				j++;
				temp[j]=pop(array,top);
			}
		}
		push(array,top,element);
		for( ;j>=0;j--)
		{
			push(array,top,temp[j]);
		}
	}
	//printf("%d\n",top);
}

int Stack::pop(int array[], int &top)
{
	if(top==-1)
	{
		printf("\nUnderflow");
		return -1;
	}
	else
	{
		int x=array[top];
		top--;
		return x;
	}
}

int Stack::min(int array[], int &top)
{
	if(top==-1)
	{
		printf("\nUnderflow");
		return -1;
	}
	else
	{
		int x=array[top];
		return x;
	}
}
		
				
			
		
