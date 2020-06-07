#include<iostream.h>
#include<conio.h>
#include<process.h> //for exit function
#include<dos.h> //for delay function
#define size 5 //replaces size by 5

class QUEUE
{
int data[size];
int front,rear;

public:
QUEUE()
{
front=-1;
rear=-1;
}
void insert();
void remove();
void display();
};

void QUEUE::insert() /* function to insert elements*/
{
if(rear==size-1)
cout<<"\n\t\t\t       QUEUE OVERFLOW!!!";
else
{
rear=rear+1;
cout<<"\nEnter the Data to be inserted: ";
cin>>data[rear];
if(front==-1)
front=0;
}
getch();
}

void QUEUE::remove()/*function to remove elements*/
{
if(front==-1)
cout<<"\n\t\t\t      QUEUE UNDERFLOW!!!";
else
{
cout<<"\nDeleted Record is: "<<data[front]<<endl;
if(front==rear)
front=rear=-1;
else
front=front+1;
}
getch();
}

void QUEUE::display()/*function to display elements*/
{
int i;
if(front==-1)
cout<<"\n\t\t\t      QUEUE UNDERFLOW!!!";
else
{
cout<<"\nElements in QUEUE are: ";
for(i=front;i<=rear;i++)
{
cout<<" "<<data[i];
}
}
getch();
}

void main()
{
QUEUE qt;
int ch,s=0;
do
{
clrscr();
cout<<"\n\n\t\t\t\t   ::WELCOME:: ";
cout<<"\n\n\t\t\t::ARRAY IMPLEMENTATION OF QUEUE::"<<endl;
cout<<"\n\nYour Options Are:-";
cout<<"\n\n1.Press 1 to INSERT Elements.";
cout<<"\n2.Press 2 to DELETE Elements.";
cout<<"\n3.Press 3 to DISPLAY Elements. ";
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

case 3: /*Case to Display Elements*/
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