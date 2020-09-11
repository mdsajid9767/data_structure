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

    void insert_begin(int);
    void display();
};
node *start=NULL;

void node :: insert_begin(int x)
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
        t->next=start;
        start=t;
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
    n1.insert_begin(10);
    n1.insert_begin(12);
    n1.insert_begin(15);
    n1.insert_begin(20);
    n1.insert_begin(99);
    n1.display();
    getch();
    return 2;
}


