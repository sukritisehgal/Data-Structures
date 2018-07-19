#include<stdio.h>
class Stack
{
	public:
	int top;
	int array[100];
	void push(int[],int&,int);
	int pop(int[],int&);
};
class Queue
{
	public:
	Stack s1,s2;
	void enqueue(int);
	int dequeue();
};

void Stack::push(int array[], int &top, int element)
{
	if(top==99)
	{
		printf("\nOverflow");
	}
	else
	{
		top++;
		array[top]=element;
	}
}
int Stack::pop(int array[],int &top)
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
void Queue::enqueue(int element)
{
	s2.push(s2.array,s2.top,element);
	//printf("%d",s2.top);
}
int Queue::dequeue()
{
	for(int i=s2.top;i>=0;i--)
	{
		int x=s2.pop(s2.array,s2.top);
		s1.push(s1.array,s1.top,x);
	}
	int y=s1.pop(s1.array,s1.top);
	return y;
}
int main()
{
	Queue q;
	//Stack s1,s2;
	q.s1.top=-1;
	q.s2.top=-1;
	q.enqueue(1);
	
	printf("%d\n",q.dequeue());
	q.enqueue(2);
	q.enqueue(3);
	
	printf("%d\n",q.dequeue());
	printf("%d\n",q.dequeue());
	
	return 0;
}
		