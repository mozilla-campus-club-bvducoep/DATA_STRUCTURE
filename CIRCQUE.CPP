#include<iostream.h>
#include<conio.h>
#include<process.h> //for exit function
#include<dos.h> //for delay function
#define size 5 //replaces size by 5

class CQUEUE
{
int data[size];
int front,rear;

public:
CQUEUE()
{
front=-1;
rear=-1;
}
void insert();
void remove();
void display();
};

void CQUEUE::insert() /* function to insert elements*/
{
if((rear==size-1&&front==0)||(front==rear+1))
cout<<"\n\t\t\t   CIRCULAR QUEUE OVERFLOW!!!";
else
{
if(rear==-1)
{
rear++;
front++;
}
else
{
if(rear==size-1)
rear=0;
else
rear++;
}
cout<<"\nEnter the Data to be inserted: ";
cin>>data[rear];
}
getch();
}

void CQUEUE::remove() /* function to delete elements*/
{
if(front==-1)
cout<<"\n\t\t\t  CIRCULAR QUEUE UNDERFLOW!!!";
else
cout<<"\nDeleted Record is: "<<data[front];
if(front==rear)
{
front=-1;
rear=-1;
}
else if(front==size-1)
front=0;
else
front++;
getch();
}

void CQUEUE::display() /*function to Display elements in the circular queue*/
{
if(front==-1)
cout<<"\n\t\t\t  CIRCULAR QUEUE UNDERFLOW!!!";
else
{
cout<<"\nElements in CIRCULAR QUEUE are: " ;
for(int i=front;i<=rear;++i)
cout<<data[i]<<" ";
}
getch();
}

void main()
{
CQUEUE qt;
int ch,s=0;
do
{
clrscr();
cout<<"\n\n\t\t\t\t   ::WELCOME:: ";
cout<<"\n\n\t\t\t       ::CIRCULAR QUEUE::"<<endl;
cout<<"\n\nYour Options Are:-";
cout<<"\n\n1.Press 1 to INSERT elements.";
cout<<"\n2.Press 2 to DELETE elements.";
cout<<"\n3.Press 3 to DISPLAY elements. ";
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

case 3: /*Case to Display elements in the circular queue*/
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
