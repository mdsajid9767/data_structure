#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

class node
{
public:
    int info;
    node *next;

    void insert_end(int);
    void display();
    void insert_pos(int,int);
};
node *start=NULL;

void node :: insert_end(int x)
{
    node *t,*cur;
    t=new node();
    t->info=x;
    if(start == NULL)
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

void node :: insert_pos(int p,int x)
{
    int pos=0;
    node *t,*cur,*prev;
    prev=cur=start;
    while(cur!=NULL)
    {
        pos++;
        if(pos == p)
        {
            break;
        }
        prev=cur;
        cur=cur->next;
    }
    t=new node();
    t->info=x;
    if(p == 1)
    {
        cout<<"\nInsert "<<x<<" is position "<<p;
        t->next=cur;
        start=t;
    }
    else if(pos == p)
    {
        cout<<"\nInsert "<<x<<" is position "<<p;
        t->next=cur;
        prev->next=t;
    }
    else if(pos+1 == p)
    {
        cout<<"\nInsert "<<x<<" is position "<<p;
        prev->next=t;
        t->next=NULL;
    }
    else
    {
        cout<<"\nPosition "<<p<<" is out of range\n";
        exit(0);
    }
}

void node :: display()
{
    if(start == NULL)
    {
        cout<<"\nList is empty";
        return;
    }
    node *cur;
    cur=start;
    cout<<"\nContents Of List...\n";
    while(cur!=NULL)
    {
        cout<<"  "<<cur->info;
        cur=cur->next;
    }
}

int main()
{
    node n1;
    n1.insert_end(10);
    n1.insert_end(12);
    n1.insert_end(15);
    n1.insert_end(20);
    n1.display();
    n1.insert_pos(3,30);
    //n1.insert_pos(7,40);
    n1.display();
    getch();
    return 2;
}


