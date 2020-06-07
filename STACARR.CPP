#include<iostream.h>
#include<conio.h>
#include<process.h>//for exit function
#include<dos.h> //for delay function
#define size 5 // replaces size by 5

class STACK
{
int data[size];
int top;

public:
STACK()
{
top=-1;
}
void push();
void pop();
void display();
~STACK(){}
};

void STACK::push() /*function to perform Push Operation*/
{
if(top==size-1)
cout<<"\n\t\t\t       STACK OVERFLOW!!!";
else
{
top++;
cout<<"\nEnter the Data to be inserted: ";
cin>>data[top];
}
getch();
}

void STACK::pop() /*function to perform Pop Operation*/
{
if(top==-1)
cout<<"\n\t\t\t      STACK UNDERFLOW!!!";
else
{
cout<<"\nDeleted Record is: "<<data[top]<<endl;
top--;
}
getch();
}

void STACK::display() /*function to Display elements in the stack*/
{
if(top==-1)
cout<<"\n\t\t\t      STACK UNDERFLOW!!!";
else
cout<<"\nElements in STACK are: ";
for(int i=top;i>=0;i--)
{
cout<<" "<<data[i];
}
getch();
}

void main()
{
STACK st; /*st is the object of class STACK*/
int ch,s=0;
do
{
clrscr();
cout<<"\n\n\t\t\t\t   ::WELCOME:: ";
cout<<"\n\n\t\t\t      ::STACK AS AN ARRAY::"<<endl;
cout<<"\n\nYour Options Are:-";
cout<<"\n\n1.Press 1 for PUSH Operation.";
cout<<"\n2.Press 2 for POP Operation.";
cout<<"\n3.Press 3 to DISPLAY Elements. ";
cout<<"\n4.Press 4 to EXIT from the Program.";
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

case 3: /*Case to Display elements in the stack*/
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