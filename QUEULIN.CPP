#include<iostream.h>
#include<conio.h>
#include<process.h> //for exit function
#include<dos.h> //for delay function

struct node
{
int data;
node *next;
};

class QUEUE
{
node *rear,*front;
public:
QUEUE()
{
rear=NULL;
front=NULL;
}
void insert();
void remove();
void display();
~QUEUE();
};

void QUEUE::insert()/* function to insert elements*/
{
node *temp=new node;
cout<<"\nEnter the Data to be inserted: ";
cin>>temp->data;
temp->next=NULL;
if(rear==NULL)
{
rear=temp;
front=temp;
}
else
{
rear->next=temp;
rear=temp;
}
getch();
}

void QUEUE::remove()/* function to delete elements*/
{
if(front==NULL)
cout<<"\n\t\t\t      QUEUE UNDERFLOW!!!";
else
{
node *temp=front;
cout<<"\nDeleted Record is: "<<temp->data;
front=front->next;
if(front==NULL)
rear=NULL;
delete temp;
}
getch();
}

void QUEUE::display() /*function to Display elements in the queue*/
{
if(front==NULL)
cout<<"\n\t\t\t      QUEUE UNDERFLOW!!!";
else
{
node *temp=front;
cout<<"\nElements in QUEUE are: ";
while(temp!=NULL)
{
cout<<" "<<temp->data;
temp=temp->next;
}
}
getch();
}

QUEUE::~QUEUE()
{
node *temp;
while(front!=NULL)
{
temp=front;
front=front->next;
delete temp;
}
}

void main()
{
QUEUE qt;
int ch,s=0;
do
{
clrscr();
cout<<"\n\n\t\t\t\t   ::WELCOME:: ";
cout<<"\n\n\t\t\t::LINKED IMPLEMENTATION OF QUEUE::"<<endl;
cout<<"\n\nYour Options Are:-";
cout<<"\n\n1.Press 1 to INSERT elements.";
cout<<"\n2.Press 2 to DELETE elements.";
cout<<"\n3.Press 3 to DISPLAY all the Elements. ";
cout<<"\n4.Press 4 to Exit from the Program.";
cout<<"\n\nENTER YOUR CHOICE: ";
cin>>ch;

switch(ch)
{

case 1: /*Case to insert elements*/
qt.insert();
break;

case 2:/*Case to delete elements*/
qt.remove();
break;

case 3: /*Case to Display elements in the queue*/
qt.display();
break;

case 4:
cout<<"\nGetting Out Of The Program.";
delay(1000);//delay 1000 milliseconds
exit(0); //getting out of the program
break;

default:  //when no case matches
cout<<"\nWrong Choice!!!Please Enter Again.";
delay(2000);//delay 2000 milliseconds
}
}
while(s==0);
getch();
}


