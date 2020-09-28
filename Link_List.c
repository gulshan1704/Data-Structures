
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
struct linklist
{
	int num;
	struct linklist *next;
};
struct linklist *start;

void insert();
void display();
void del();
void edit();
void count();
void sort();
void reverse();
void exit();
void atbeg();
void atend();
void before();
void after();
void atpos();
void atbeg1();
void atend1();
void before1();
void after1();
void atpos1();


int main ( )
{
	int ch1;
	char choice1='y';
	start=NULL;
	do
	{
		printf ("\n 1. INSERT  ");
		printf ("\n 2. DISPLAY  ");
		printf ("\n 3. DELETE    ");
		printf ("\n 4. EDIT    ");
		printf ("\n 5. COUNT NODES ");
		printf ("\n 6. SORTING ");
		printf ("\n 7. REVERSE  ");
		printf ("\n 8. EXIT  ");

		printf ("\n\n Enter Your Choice = ");
		scanf("%d",&ch1);

		switch (ch1)
		{
			case 1:
				insert ( );
				break;

			case 2:
				display ( );
				break;
            case 3:
				del();
				break;
            case 4:
				edit();
				break;
            case 5:
				count();
				break;
            case 6:
				sort();
				break;
            case 7:
				reverse();
                break;
			case 8:
				choice1='n';
				break;
			default:
				printf ("invalid choice");
		}
	} while (choice1== 'y');
	return 0;
}
// end of main //
void insert ( )
{
	int ch2;
	char choice2;
	do
	{
		printf ("\n 1. ATBEG ") ;
		printf("\n 2. ATEND ");
		printf("\n 3. BEFORE ");
		printf("\n 4. AFTER ");
		printf("\n 5. ATPOS ");
		printf ("\n 6. EXIT ")  ;
		printf ("\n\n Enter Your Choice = ") ;
		scanf ("%d",&ch2);
		switch(ch2)
		{
			case 1:
				atbeg ( );
				break;
            case 2:
                atend();
                break;
            case 3:
                before();
                break;
            case 4:
                after();
                break;
            case 5:
               atpos();
                break;

			case 6:
				choice2='n';
				break;
			befault:
				printf("INVALID CHOICE");
		}
	}while(choice2=='y');
}

void atbeg()
{
	struct linklist *temp,*node;
	node =(struct linklist*)malloc(sizeof(struct linklist));
	printf("\n\n Enter a no.");
	scanf("%d",&node->num);
	node->next=NULL;

	if(start==NULL)
	{
		start=node;
		return;
	}
	else
	{
		temp=start;
		start=node;
		node->next=temp;
	}
}

void atend()
  {
     struct linklist *temp,*node;
	node =(struct linklist*)malloc(sizeof(struct linklist));
	printf("\n\n Enter Data.");
	scanf("%d",&node->num);
	node->next=NULL;

	if(start==NULL)
	{
		start=node;
		return;
	}

	  temp=start;
	  while(temp->next!=NULL)

	{
		temp=temp->next;  //last node
	}
	    temp->next=node;  // Add the node at end
  }

void before()
{

    int val;
    struct linklist *temp,*temp1,*node;

    printf("\n Before which node u want to insert =");
    scanf("%d",&val);
    node=(struct linklist*)malloc(sizeof(struct linklist));
	printf("\n\n Enter Data.");
	scanf("%d",&node->num);
	node->next=NULL;

	  temp=start;
	  while(temp->num != val)

	{
	    temp1 =temp;
		temp=temp->next;
	}
	    temp1->next=node;
	    node->next=temp;
}

void after()
{
    int val;
    struct linklist *temp,*temp1,*node;

    printf("\n After which node u want to insert =");
    scanf("%d",&val);
    node =(struct linklist*)malloc(sizeof(struct linklist));
	printf("\n\n Enter Data.");
	scanf("%d",&node->num);
	node->next=NULL;

	  temp=start;
	  while(temp->num !=val)

	{
		temp=temp->next;
	}
	    node->next=temp->next;
	    temp->next=node;
}

void atpos()
{
	int i=1,c=0,n;
	struct linklist *temp,*temp1,*node;
	printf("Enter the position no=");
	scanf("%d",&n);


	node=(struct linklist*)malloc(sizeof(struct linklist));
	printf("\n\n Enter the data of node : ");
	scanf("%d",&node->num);
	node->next = NULL;

	temp=start;

	while(temp!=NULL)
	{
		c=c+1;
		temp=temp->next;
	}
	if (n>c)
	{
		printf("\n Not valid ");
		return;
	}
	temp=start;

	while(i<n)
	{
		i = i+1;
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=node;
	node->next=temp;
}




void del()
{
	int ch3;
	char choice3;
	do
	{
		printf ("\n 1. ATBEG ") ;
		printf("\n 2. ATEND ");
		printf("\n 3. BEFORE ");
		printf("\n 4. AFTER ");
		printf("\n 5. ATPOS ");
		printf ("\n 6. EXIT ")  ;
		printf ("\n\n Enter Your Choice = ") ;
		scanf ("%d",&ch3);
		switch(ch3)
		{
			case 1:
				atbeg1 ();
				break;
            case 2:
                atend1();
                 break;
            case 3:
                before1();
                break;
            case 4:
                after1();
                break;
            case 5:
                atpos1();
                break;

			case 6:
				choice3='n';
				break;
			befault:
				printf("INVALID CHOICE");
		}
	}while(choice3=='y');
}

void atbeg1()
{

    struct linklist *temp;
    temp=start;
    start=start->next;
    free(temp);
}


void atend1()
{

    struct linklist *temp,*temp1;
    temp=start;
    while(temp->next!=NULL)
    {
        temp1=temp;
        temp = temp->next;
    }
    temp1->next=NULL;
    free(temp);
}


void before1()
{
    int i;
    struct  linklist *temp,*temp1,*temp2;
    printf("\n Before which node u want to delete =");
    scanf("%d",&i);

    temp =start;
    temp1=temp->next;
    temp2=temp1->next;

    while(temp2->num !=i)
    {

        temp=temp->next;
        temp1=temp->next;
        temp2=temp1->next;
    }
    temp->next=temp2;
    temp1->next=NULL;
    free(temp1);

}



void after1()
{
    int i;
    struct linklist *temp,*temp1,*temp2;
    printf("\n After which node u want to delete =");
    scanf("%d",&i);

    temp =start;
    temp1=temp->next;
    temp2=temp1->next;

    while(temp->num !=i)
    {
        temp=temp->next;
        temp1=temp->next;
        temp2=temp1->next;
    }
    temp->next=temp2;
    temp1->next=NULL;
    free(temp1);

}

void atpos1( )
{
	int i=1,c=0,n;
	struct linklist *temp,*temp1;
	printf("Enter the position no =");
	scanf("%d",&n);
	temp=start;

	while(temp!=NULL)
	{
		c=c+1;
		temp=temp->next;
	}
	if (n>c)
	{
		printf("Not valid ");
		return;
	}
	temp=start;

	while(i<n)
	{
		i = i +1;
		temp1=temp;
		temp=temp->next;

	}
	temp1->next=temp->next;
	temp->next=NULL;
	free(temp);
}


    //display the link list

void display()
	{
		struct linklist *temp;
		temp = start;
		while(temp!=NULL)
		{
		printf("%d-->",temp->num);
		temp=temp->next;
		}
	}


	//COUNT THE NODES


void count()
{
	    int count=0;
	    struct linklist *temp;
	    temp=start;

	    while(temp!=NULL)
        {
            count=count+1;
            temp=temp->next;
        }
        printf("\n The total nodes =%d",count);
}

//EDIT NODES OF LINKLIST

void edit()
{

    int i=1,count=0,pos,num1;
    struct linklist *temp;
    printf("\nEnter the position of node for edit =");
    scanf("%d",&pos);

    printf("\n \n Enter the data of new node :");
    scanf("%d",&num1);

    temp =start;
    while(temp!=NULL)
    {

        count=count+1;
        temp=temp->next;
    }
    if(pos>count)
    {
        printf("\nNot valid");
        return;
    }
    temp=start;
    while(i<pos)
    {

        i=i+1;
        temp=temp->next;
    }
    temp->num= num1;
}


//SORTING  LINKLIST


void sort()
{
	int n;
	struct linklist *temp,*temp1;
	temp=start;
	while(temp==start)
	while(temp!=NULL)
	{
		temp1=temp->next;
		while(temp1!=NULL)
		{
			if(temp->num>temp1->num)
			{
				n=temp->num;
				temp->num=temp1->num;
				temp1->num=n;
			}
			temp1=temp1->next;
		}
		temp=temp->next;
	}
}

void reverse()
{
    struct linklist *ptr,*temp,*old;
    temp=start;
    ptr=NULL;

    while(temp!=NULL)
          {
              old =ptr;
              ptr =temp;
              temp=temp->next;
              ptr->next=old;
          }
          start=ptr;

}




