#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node
{
    int info;
    node *next;
};

node *start=NULL;

void insert_end();
void insert_begin();
void insert_after();
void insert_before();
void insert_bet();
void display();
void rev_display(node *);
void search1();
void update();
void delete_par();
void delete_end();
void delete_begin();
void delete_after();
void delete_before();
void delete_bet();

void insert_end()
{
    node *t,*cur;
    t=(node *)malloc(sizeof(node));
    cout<<"\nEnter a value\n";
    cin>>t->info;
    t->next=NULL;
    if(start==NULL)
    {
        start=t;
    }
    else
    {
        cur=start;
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=t;
    }
}

void display()
{
    node *cur;
    if(start == NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    cur=start;
    cout<<"\nContents Of List...\n";
    while(cur!=NULL)
    {
        cout<<endl<<cur->info;
        cur=cur->next;
    }
}

void rev_display(node *p)
{
    if(p->next!=NULL)
    {
        rev_display(p->next);
    }
    cout<<"\n"<<p->info;
}

void insert_begin()
{
    node *t;
    t=(node *)malloc(sizeof(node));
    cout<<"\nEnter a value\n";
    cin>>t->info;
    t->next=start;
    start=t;
}

void insert_after()
{
    int x;
    node *t,*cur;
    if(start==NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    cout<<"\nEnter a no after insert\n";
    cin>>x;
    cur=start;
    while(cur!=NULL)
    {
        if(cur->info==x)
        {
            break;
        }
        cur=cur->next;
    }
    if(cur == NULL)
    {
        cout<<"\n"<<x<<" is not present";
        return;
    }
    t=(node *)malloc(sizeof(node));
    cout<<"\nEnter a value\n";
    cin>>t->info;
    t->next=cur->next;
    cur->next=t;
}

void insert_before()
{
    int x;
    node *t,*cur,*prev;
    if(start == NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    cur=prev=start;
    cout<<"\nEnter a value to insert before\n";
    cin>>x;
    while(cur!=NULL)
    {
        if(cur->info==x)
        {
            break;
        }
        prev=cur;
        cur=cur->next;
    }
    if(cur == NULL)
    {
        cout<<"\n"<<x<<" is not present";
        return;
    }
    t=(node *)malloc(sizeof(node));
    cout<<"\nEnter a value\n";
    cin>>t->info;
    t->next=cur;
    if(cur == prev)
    {
        start=t;
    }
    prev->next=t;
}

void insert_bet()
{
    int x,y;
    node *t,*cur,*prev;
    if(start == NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    cur=prev=start;
    cout<<"\nEnter two values to insert between two no\n";
    cin>>x>>y;
    while(cur!=NULL)
    {
        if(prev->info==x && cur->info==y)
        {
            break;
        }
        prev=cur;
        cur=cur->next;
    }
    if(cur == NULL)
    {
        cout<<"\n"<<x<<" is not present";
        return;
    }
    t=new node;
    cout<<"\nEnter a value\n";
    cin>>t->info;
    t->next=cur;
    prev->next=t;
}

void search1()
{
    int x;
    node *cur;
    if(start == NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    cur=start;
    cout<<"\nEnter a value to search\n";
    cin>>x;
    while(cur!=NULL)
    {
        if(cur->info==x)
        {
            break;
        }
        cur=cur->next;
    }
    if(cur == NULL)
    {
        cout<<"\n"<<x<<" is not present";
    }
    else
    {
        cout<<"\n"<<x<<" is present";
    }
}

void update()
{
    int x;
    node *cur;
    if(start == NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    cur=start;
    cout<<"\nEnter a value to update\n";
    cin>>x;
    while(cur!=NULL)
    {
        if(cur->info==x)
        {
            break;
        }
        cur=cur->next;
    }
    if(cur == NULL)
    {
        cout<<endl<<x<<" is not present";
    }
    else
    {
        cout<<endl<<x<<" is present";
        cout<<"\nEnter a new value\n";
        cin>>cur->info;
    }
}

void delete_end()
{
    int x;
    node *cur,*prev;
    if(start == NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    prev=cur=start;
    while(cur->next!=NULL)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev == cur)
    {
        start=NULL;
    }
    else
    {
        prev->next=NULL;
    }
    cout<<"\nDeleted NO="<<cur->info;
    free(cur);
}

void delete_begin()
{
    node *cur;
    if(start == NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    cur=start;
    start=cur->next;
    cout<<"\nDeleted NO="<<cur->info;
    free(cur);
}

void delete_par()
{
    int x;
    node *cur,*prev;
    if(start == NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    prev=cur=start;
    cout<<"\nEnter a value to delete\n";
    cin>>x;
    while(cur!=NULL)
    {
        if(cur->info==x)
        {
            break;
        }
        prev=cur;
        cur=cur->next;
    }
    if(cur == NULL)
    {
        cout<<"\n"<<x<<" is not present";
        return;
    }
    if(prev == cur)
    {
        start=cur->next;
    }
    else
    {
        prev->next=cur->next;
    }
    cout<<"\nDeleted NO="<<cur->info;
    free(cur);
}

void delete_after()
{
    int x;
    node *cur,*prev;
    if(start == NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    prev=start;
    cout<<"\nEnter a value after delete\n";
    cin>>x;
    while(prev!=NULL)
    {
        if(prev->info==x)
        {
            break;
        }
        prev=prev->next;
    }
    if(prev == NULL || prev->next == NULL)
    {
        cout<<"\nVoid deletion";
        return;
    }
    cur=prev->next;
    prev->next=cur->next;
    cout<<"\nDeleted NO="<<cur->info;
    free(cur);
}

void delete_before()
{
    int x;
    node *cur,*prev;
    if(start == NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    cout<<"\nEnter a value to delete before\n";
    cin>>x;
    prev=cur=start;
    while(cur->next!=NULL)
    {
        if(cur->next->info==x)
        {
            break;
        }
        prev=cur;
        cur=cur->next;
    }
    if(cur->next == NULL)
    {
        cout<<"\nVoid deletion";
        return;
    }
    if(prev == cur)
    {
        start=cur->next;
    }
    else
    {
        prev->next=cur->next;
    }
    cout<<"Deleted NO="<<cur->info;
    free(cur);
}

void delete_bet()
{
    int x,y;
    node *t,*cur,*prev;
    if(start == NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    cout<<"\nEnter two value to delete between two no\n";
    cin>>x>>y;
    prev=start;
    while(prev!=NULL)
    {
        if(prev->info==x)
        {
            break;
        }
        prev=prev->next;
    }
    if(prev == NULL)
    {
        cout<<"\nVoid Deletion";
        return;
    }
    cur=prev->next;
    while(cur!=NULL)
    {
        if(cur->info==y)
        {
            break;
        }
        cur=cur->next;
    }
    if(cur==NULL || prev->next==NULL)
    {
        cout<<"\nVoid Deletion";
        return;
    }
    cout<<"\nList of deleted Nos\n";
    while(prev->next!=cur)
    {
        t=prev->next;
        prev->next=t->next;
        cout<<"\n"<<t->info;
        free(t);
    }
}

int main()
{
    int ch;
    do
    {
        cout<<"\n1.Insert End\n2.Insert Begin\n3.Insert After\n4.Insert Before\n5.Insert Between\n6.Display";
        cout<<"\n7.Reverse Display\n8.Search\n9.Update\n10.Delete Particular\n11.Delete Begin\n12.Delete End\n13.Delete After";
        cout<<"\n14.Delete Before\n15.Delete Between\n0.Exit";
        cout<<"\nEnter Your Choice\n";
        cin>>ch;
        switch(ch)
        {
            case 1:insert_end();break;
            case 2:insert_begin();break;
            case 3:insert_after();break;
            case 4:insert_before();break;
            case 5:insert_bet();break;
            case 6:display();break;
            case 7:rev_display(start);break;
            case 8:search1();break;
            case 9:update();break;
            case 10:delete_par();break;
            case 11:delete_begin();break;
            case 12:delete_end();break;
            case 13:delete_after();break;
            case 14:delete_before();break;
            case 15:delete_bet();break;
            case 0:exit(0);
        }
        getch();
        system("cls");
    }
    while(2);
    return 2;
}
