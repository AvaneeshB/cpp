#include<stdio.h>
#include<stdlib.h>
#define Max 100
int top=-1;
typedef struct
{
	int key;
//	int a;
}element;
element stack[Max];
void push()
{
	if(top>=Max)
		printf("Stack is full\n");
	else
	{
		int n;
		printf("Enter the element to be pushed\n");
		scanf("%d",&n);
		stack[++top].key=n;
	}	
}
void pop()
{
	if(top==-1)
		printf("Stack is empty\n");
	else
	{
		printf("Popped element is %d \n",stack[top--]);
	}	
}
void display()
{
	int i;
	for(i=0;i<=top;i++)
		printf("%d\t",stack[i]);
	printf("\n");	
}
int main()
{
	int n;
	printf("1.Push\n2.Pop\n3.Dispay\n4.Exit\n");
	while(1)
	{
		printf("Enter the operation to be performed on the stack....\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:push();break;
			case 2:pop();break;
			case 3:display();break;
			case 4:exit(0);
			default :printf("Enter a valid input fucker...\n\n");break;
		}
	}
	return 0;
}
