
/* Queue Operations Using Linked List */

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

struct queue
{
     int info;
     struct queue *next;
};
typedef struct queue qu;
qu *front=NULL,*rear=NULL;


int main()
{
     void insert();
     void delt();
     void traverse();
     int ch;
	printf("Queue Application: linked list:");
	do
	{
		printf ("\n 1. INSERT     ");
		printf ("\n 2. DELETE       ");
		printf ("\n 3. TRAVERSE       ");
		printf ("\n 4. EXIT        ");
		printf ("\n\n Enter Your Choice = ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				insert( );
				break;

               case 2:
				delt();
				break;

			case 3:
				traverse ( );
				break;

			case 4:
				printf("End of queue operation");
				break;

			default:
				printf ("invalid choice");
		}
	} while (ch!=4);
	return 0;
}

void insert()
{
      qu *node;
      int x;
      printf("Enter the data to insert in queue:");
      scanf("%d",&x);
      node=(qu*)malloc(sizeof(qu));
      node->info=x;
      node->next=NULL;
      if(rear==NULL)
      {
           front=node;
           rear=node;
           return;
      }
      rear->next=node;
      rear=node;
}
void delt()
{
     int N;
     qu *temp;
     if(front==NULL)
     {
          printf("Queue is empty!!");
          return;
     }
     temp=front;
     N=front->info;
     front=temp->next;
     temp->next=NULL;
     free(temp);
     printf("%d is deleted:",N);

}
void traverse()
{
  qu *temp;
  if(front==NULL)
  printf("Queue is empty");
  else
  {
       temp=front;
       printf("ELEMENTS IN QUEUE:");
       while(temp->next!=NULL)
       {
            printf("%d ",temp->info);
            temp=temp->next;
       }
       printf("%d",temp->info);
  }
}
