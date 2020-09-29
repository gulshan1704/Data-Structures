 /* OPERATION ON CIRCULAR QUEUE */


 #include<stdio.h>
 #define MAX 5

 int cq[MAX];
 int front =-1 , rear = -1;
 int choice;
 void insert();
 void del();
 void traverse();

 char ch;
 int main()
 {
     printf("Circular Queue Application :");

     do
     {
         printf("\n1. INSERT\n");
         printf("2. DELETE\n");
         printf("3. TRAVERSE\n");
         printf("4. EXIT\n");
         printf("ENTER YOUR CHOICE :");
         scanf("%d",&choice);

         switch(choice)
         {
             case 1:insert();
                break;
             case 2:del();
               break;
             case 3:traverse();
               break;
              case 4:printf("End of Circular Queue Application :\n");
                break;
             default:printf("You Have Entered Wrong Choice:\n");
          }
     }    while(choice !=4);
     return 0;
 }


 void insert()
 {
     int num;
     printf("Enter The Element To Be Inserted:");
     scanf("%d",&num);

     if(front==(rear+1)%MAX)
     {
         printf("Queue Is Full\n");
         return 0;
     }
     if(front==-1)
     {
         front=0;
         rear=0;
     }
     else
     {
         rear =(rear+1)%MAX;
     }
      cq[rear]=num;
 }

 void del()
 {
     int N;
     if(front==-1)
     {
         printf("Queue Is Empty\n");
         return ;
     }
      N =cq[front];
      if(front==rear)
      {
        front=rear=-1;
      }
      else
      {
        front=(front+1)%MAX;
        printf("Deleted Element Is=%d\n",N);
      }
 }

 void traverse()
 {
     int temp;
     if(front==-1)
     {
         printf("Queue Is Empty:\n");
         return;
     }
     temp =front;
     printf("Elements Of Circular Queue:");
     while(temp<=rear)
     {
         printf(" %d ",cq[temp]);
         temp =temp +1;
     }
 }


