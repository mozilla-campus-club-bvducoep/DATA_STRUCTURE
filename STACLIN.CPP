#include<iostream.h>
#include<conio.h>
#include<process.h>//for exit function
#include<dos.h> //for delay function

struct node
{
int data;
node *next;
};

class STACK
{
node *top;

public:
STACK()
{
top=NULL;
}
void push();
void pop();
void display();
~STACK();
};

void STACK::push()/*function to perform Push Operation*/
{
node *temp=new node;
cout<<"\nEnter the Data to be inserted: ";
cin>>temp->data;
temp->next=top;
top=temp;
getch();
}

void STACK::pop()/*function to perform Pop Operation*/
{
if(top==NULL)
cout<<"\n\t\t\t      STACK UNDERFLOW!!!";
else
{
node *temp=top;
cout<<"\nDeleted Record is: "<<temp->data;
top=top->next;
delete temp;
}
getch();
}

void STACK::display()/*function to Display all the Elements*/
{
if(top==NULL)
cout<<"\n\t\t\t      STACK UNDERFLOW!!!";
else
{
node *temp=top;
cout<<"\nElements in STACK are: ";
while(temp!=NULL)
{
cout<<" "<<temp->data;
temp=temp->next;
}
}
getch();
}

STACK::~STACK()
{
node *temp;
while(top!=NULL)
{
temp=top;
top=top->next;
delete temp;
}
}

void main()
{
STACK st; /*st is the object of class STACK*/
int ch,s=0;
do
{
clrscr();
cout<<"\n\n\t\t\t\t   ::WELCOME:: ";
cout<<"\n\n\t\t\t    ::STACK WITH LINKED LIST::"<<endl;
cout<<"\n\nYour Options Are:-";
cout<<"\n\n1.Press 1 for PUSH Operation.";
cout<<"\n2.Press 2 for POP Operation.";
cout<<"\n3.Press 3 to DISPLAY all the Elements. ";
cout<<"\n4.Press 4 to Exit from the Program.";
cout<<"\n\nENTER YOUR CHOICE: ";
cin>>ch;
switch(ch)
{

case 1: /*Case for Push Operation*/
st.push();
break;

case 2:/*Case for Pop Operation*/
st.pop();
break;

case 3: /*Case to Display all the elements*/
st.display();
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