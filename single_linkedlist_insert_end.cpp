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
}

