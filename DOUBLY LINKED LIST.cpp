#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
};

void push(node **head,int n)  //pushes elements at the starting
{
    node *temp=*head;
    node *new_node=new node();
    new_node->data=n;
    if((*head)!=NULL)
    (*head)->prev=new_node;
    new_node->next=*head;
    new_node->prev=NULL;
    *head=new_node;
}


void print(node *head)  //prints the dll
{
    while(head!=NULL)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
    cout<<endl;
}


void dele(node **head,node *del)   //deletes a node
{
    if(*head==NULL || del==NULL)
        return;
    if(*head==del)
    {
        *head=del->next;
        del->prev=NULL;
        return;
    }
    node *curr=del;
    curr->prev->next=curr->next;
    if(curr->next!=NULL)
    curr->next->prev=curr->prev;
}

void rev(node **head)   //reverses the dll
{
    node *curr=*head,*temp=NULL;
    while(curr!=NULL)
    {
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }
    *head=temp->prev;
}

int countnodes(node *first)  // counts no. of nodes in dll
{
    int n;
    while(first!=NULL)
    {
        first=first->next;
        n++;
    }
    return n;
}

void swapk(node **head,int k)   // SWAP Kth node from beginning and kth from end
{
    int i;
    int n=countnodes(*head); //NO. OF NODES
    node *temp=*head;
    if(n<k) return ;
    if(k==1)
    {
        while(temp->next!=NULL)
            temp=temp->next;
       node *flag=(*head)->next;
       (*head)->next->prev=temp;
        temp->prev->next=(*head);
        (*head)->prev=temp->prev;
        (*head)->next=temp->prev=NULL;
        temp->next=flag;
        *head=temp;
        return;
    }
    node *x=*head,*x_prev=NULL,*x_next=NULL;
    for(i=1;i<k;i++)
        x=x->next;
    x_prev=x->prev;
    x_next=x->next;
    node *y=*head,*y_prev=NULL,*y_next=NULL;
    for(i=1;i<n-k+1;i++)
        y=y->next;
    y_next=y->next;
    y_prev=y->prev;

    x_next->prev=y;
    x_prev->next=y;
    x->next=y_next;
    x->prev=y_prev;


    y_next->prev=x;
    y_prev->next=x;
    y->next=x_next;
    y->prev=x_prev;

}

void pairss(node **head,int k)    // FINDING PAIRS WITH GIVEN SUM
{
    bool i;
    node *temp=(*head),*flag=*head;
    while(temp->next!=NULL)
    temp=temp->next;
    while(temp!=flag  && temp->next!=flag)
    {
        if(temp->data +flag->data ==k)
        {
            i=true;
            cout<< temp->data << " "<<flag->data<<endl;
            flag=flag->next;
            temp=temp->prev;
        }
        else
        {
            if(temp->data +flag->data < k)
              flag=flag->next;
              else
              temp=temp->prev;
        }
    }
    if(i==false)
    cout<<"NO PAIRS FOUND"<<endl;

}

void sortedinsert(node **head,int k)   //sorted insert in dll
{
    if(*head==NULL)
    return;
    else if((*head)->data > k)
    {
        node *new_node=new node();
        new_node->data=k;
        new_node->next=*head;
        (*head)->prev=new_node;
        (*head)=new_node;
    }
    else
    {
        node *curr=*head,*curr_next=NULL;
        while(curr->next!=NULL && curr->next->data < k)
             curr=curr->next;
        curr_next=curr->next;
        node *new_node=new node();
        new_node->data=k;
        new_node->prev=curr;
        new_node->next=curr->next;
        if(curr->next!=NULL)
        curr->next->prev=new_node;
        curr->next=new_node;
    }
}


void deleteatpos(node **head,int k)   //delete at a given pos
{
    int n=countnodes(*head);
    if(k>n)
    {
        cout<<"INVALID INPUT";
        return;
    }
    node *curr=*head;
    for(int i=1;i<k;i++)
    {
        curr=curr->next;
    }
    dele(head,curr);
}

void rotates(node **head,int k)   //rotates a dll
{
    int n=countnodes(*head);
    if(k>n || k<=0)
    {
        cout<<"INVALID INPUT \n";
        return ;
    }
    node *first=*head,*last=*head;
    while(last->next!=NULL)
    last=last->next;
    for(int i=1;i<k;i++)
    first=first->next;
    first->prev->next=NULL;

    first->prev=NULL;
    last->next=(*head);
    *head=first;
}

void duplicates(node **head)    //deletes duplicates from dll
{
    node *curr=*head;
    while(curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
          dele(head,curr->next);
        else curr=curr->next;
    }
}
int main()

{
    node *head=NULL;
    push(&head,9);
    push(&head,8);
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,3);
    print(head);
   // any function you want to check
    print(head);


}


