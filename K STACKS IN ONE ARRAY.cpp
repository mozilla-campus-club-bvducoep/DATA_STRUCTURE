#include<bits/stdc++.h>
using namespace std;
class Kstack
{
    int *top;
    int *next;
    int *arr;
    int fre,k,n;
public: 
   Kstack(int n1, int k1)
   {
       n=n1;k=k1;
       top=new int [k+1];
       next=new int [n+1];
       arr=new int [n+1];
       for(int i=1;i<=k;i++)
        top[i]=-1;
       for(int i=1;i<=n;i++)
       {
           next[i]=i+1;
       }
       next[n]=-1;
       fre=1;
   }
   void push(int ,int );
   void pop(int);
   void display();
   int isempty(int);
   int isfull();
   void peek(int);
};

void Kstack :: push(int item,int st)
{
    if(isfull())
    {
        cout<<"STACK OVERFLOW \n";
        return;
    }
    int i=fre;
    fre=next[i];
    next[i]=top[st];
    top[st]=i;
    arr[i]=item;
}

void Kstack :: pop(int st)
{
    if(isempty(st))
    {
        cout<<"Stack Underflow \n";
        return ;
    }
    int i= top[st];
    top[st]=next[i];
    next[i]=fre;
    fre=i;
}

void Kstack :: display()
{
    for(int i=1;i<=k;i++)
    {
        if(top[i]==-1)
        {
            cout<<"STACK "<<i<<" is empty \n";
        }
        else
        {
        int j=top[i];
        while(j!=-1)
        {
            cout<<arr[j]<<" ";
            j=next[j];
        }
        cout<<"\n";
        }
    }
}

int Kstack :: isempty(int st)
{
    return (top[st]==-1);
}

int Kstack :: isfull()
{
    return (fre==-1);
}

void Kstack :: peek(int st)
{
    if(isempty(st))
    {
        cout<<"STACK IS EMPTY \n";
        return ;
    }
    cout<<arr[top[st]]<<"\n";
}
int main()
{
    Kstack s(20,5);
    s.push(12,1);
    s.push(13,1);
    s.push(14,1);
    s.push(15,3);
    s.push(18,4);
    s.display();
    s.peek(2);
}

















