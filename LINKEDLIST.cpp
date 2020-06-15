#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};


void append(node **head)
{
    system("CLS");
    int data;
    cout<<"ENTER THE DATA \n";
    cin>>data;
    node *new_node=new node();
    node *last = *head;
    new_node->data=data;
    new_node->next=NULL;
    cout<<"DATA HAS BEEN APPENDED SUCCESSFULLY \n";
    if(*head==NULL)
    {
        *head=new_node;
        return ;
    }
    while(last->next!=NULL)
        last=last->next;

    last->next=new_node;
    return ;

}

void split(node *head , node **start , node **last)
{
    node *fast= head->next;
    node *slow=head;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    *start=head;
    *last=slow->next;
    slow->next=NULL;
}

node *sortedmerge(node *a,node *b)
{
   node *result=NULL;
    if(a==NULL)
        return b;
    if(b==NULL)
        return a;
    if(a->data <= b->data)
    {
        result=a;
        result->next=sortedmerge(a->next,b);
    }
    if(a->data > b->data)
    {
        result=b;
        result->next=sortedmerge(a,b->next);
    }
    return result;
}

void mergesort(node **headref)
{
    system("CLS");
    node *a,*b;
    node *head=*headref;
    if(head==NULL || head->next==NULL)
        {
            cout<<"THE LIST IS EMPTY OR ONLY HAS ONE ELEMENT ";
            return ;
        }

        split(head, &a,&b);

        mergesort(&a);
        mergesort(&b);

        *headref=sortedmerge(a,b);
        cout<<" LIST HAS BEEN SORTED ";
}


void deletenode(node **head)
{
    system("CLS");
    node *temp=*head,*prev=NULL;
    int data;
    cout<<"ENTER THE DATA \n";
    cin>>data;
    if(temp==NULL)
    {
        cout<<"THE LIST IS EMPTY \n";
        return ;
    }
    if(temp!=NULL && temp->data==data)
    {
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=data)
    {
        prev=temp;22
        temp=temp->next;
    }
    if(temp==NULL)
        {
            cout<<" COULD NOT FIND THE DATA ";
            return ;
        }
    cout<<"DATA DELETED ";
    prev->next=temp->next;
    free(temp);
}

void searchl(node *head)
{
    system("CLS");
    int data;
    cout<<"ENTER THE DATA \n";
    cin>>data;
    if(head==NULL)
    {
        cout<<"THE LIST IS EMPTY ";
        return;
    }
    while(head!=NULL && head->data!=data)
    {
        head=head->next;
    }
    if(head==NULL)
    {
        cout<<"DATA NOT FOUND ";
        return ;
    }
    cout<<"DATA FOUND ";

}


void printlist(node *n)
{
    system("CLS");
    if(n==NULL)
    {
        cout<<"THE LIST IS EMPTY";
        return ;
    }
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
    cout<<endl;
}

void middle(node *head)
{
    node *slow=head,*fast=head->next;
    if(head==NULL)
    {
        cout<<"THE LIST IS EMPTY ";
        return ;
    }
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    cout<<"THE MIDDLE ELEMENT : "<<slow->data;
}

void reversel(node **head)
{
    system("CLS");
    node *prev=NULL,*curr=*head,*next=curr->next;
    if(curr==NULL)
    {
        cout<<"THE LIST IS EMPTY :";
        return;
    }
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    cout<<"THE LIST IS REVERSED ";
}

void push(node** head)
{
    system("CLS");
    int data;
    cout<<"ENTER THE DATA \n";
    cin>>data;
    node* new_node=new node();
    new_node->data=data;
    new_node->next=*head;
    *head=new_node;
    cout<<"DATA INSERTED SUCCESSFULLY ";
}



int main()
{
    node *head=NULL;
    int p=0,c=0;
    char ch='y';
    while(ch=='y')
    {
        system("CLS");
        cout<<"   MAIN MENU ";
        cout<<"\n\n\n\n";
        cout<<"1. APPEND \n";
        cout<<"2. INSERT AT TOP \n";
        cout<<"3. SORT THE LIST \n";
        cout<<"4. SEARCH A ELEMENT \n";
        cout<<"5. FIND THE MIDDLE \n";
        cout<<"6. DELETE A NODE \n";
        cout<<"7. REVERSE THE LIST \n";
        cout<<"8. PRINT THE LIST \n";
        cout<<"9. EXIT \n\n";
        cout<<"CHOOSE AN OPTION : ";
        cin>>p;

        switch(p)
        {
            case 1:
                append(&head);
                break;
            case 2:
                push(&head);
                break;
            case 3:
                mergesort(&head);
                break;
            case 4:
                searchl(head);
                break;
            case 5:
                middle(head);
                break;
            case 6:
                deletenode(&head);
                break;
            case 7:
                reversel(&head);
                break;
            case 8:
                printlist(head);
                break;
            case 9:
                return 0;
            default :
                    cout<<"WRONG CHOICE ";



        }
        cout<<"\n DO YOU WANT TO RETURN TO THE MAIN MENU (y/n)";
        cin>>ch;

    }


}
