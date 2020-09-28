#include <stdio.h>
#include <stdlib.h>
# define MAX_SIZE 5

int stack[MAX_SIZE];
int top =  -1;

int main()
{
	int ch;
	void push();
	void pop();
	void peep();
	void traverse();
	printf ("Stack Application Menu \n");
	do
	{
		printf ("\n1. PUSH\n");
		printf ("2. POP\n");
		printf("3. PEEP \n");
		printf ("4. TRAVERSE\n");
		printf ("5. EXIT\n");
		printf ("Enter your choice (1 to 5) : ");
		scanf ("%d", &ch);
		switch(ch)
		{
			case 1: push(); break;
			case 2: pop();break;
			case 3: peep();break;
			case 4: traverse();break;
			case 5: printf ("End of stack application : ");break;
			default : printf ("you have entered wrong choice : ");
		}
	}while(ch!=5);
}
void push()
{
	int item;
	if(top>=MAX_SIZE-1)
		printf ("Stack overflow");
	else
	{
		printf ("Enter value to PUSH : ");
		scanf ("%d", &item);
		top++;
		stack[top]=item;
	}
}
void pop()
{
	int item;
	if (top<0)
	printf ("Stack is empty !!!");
	else
	{
		item = stack[top];
		printf ("%d is popped out : ", item);
		stack[top] = NULL;
		top--;
	}
}

void peep()
{
    int n;
    printf("Enter the position number to Peep :");
    scanf("%d",&n);
    if((top-n+1)<0)
    {
        printf("\n !! Not Possible\n");
        return;
    }
    printf("%d is Peep out\n",stack[top-n+1]);

}
void traverse()
{
	int i = 0, temp;
	if(top<0)
	{
		printf ("Stack is empty!!");
		return ;
	}
	temp = top;
	printf ("stack elements : ");
	while(temp>=0)
	{
		printf ("\n%d", stack[temp]);
		temp = temp-1;
	}
}
