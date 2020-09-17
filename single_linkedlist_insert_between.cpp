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

    void insert_begin();
    void insert_between();
    void display();
};
node *start=NULL;

void node :: insert_begin()
{
    node *t,*cur;
    t=new node();
    do
    {
        //system("cls");
        t=new node();
        cout<<"\nEnter a value to insert begin\n";
        cin>>t->info;
        if(start == NULL)
        {
            start=t;
        }
        else
        {
            t->next=start;
            start=t;
        }
        cout<<"\nDo you want to insert another node(y/n):";
        fflush(stdin);
    }while(getchar()!='n');
}

void node :: insert_between()
{
    do
    {
        int x,y;
        node *t,*cur,*prev;
        if(start == NULL)
        {
            cout<<"\nList is empty";
            exit(0);
        }
        prev=cur=start;
        cout<<"\nEnter two no between insert node\n";
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
        if(prev==NULL || cur==NULL || prev->next!=cur)
        {
            cout<<"\nInsert not possible";
            return;
        }
        t=new node();
        cout<<"\nEnter a no to insert\n";
        cin>>t->info;
        t->next=cur;
        prev->next=t;
        display();
        cout<<"\nDo you want to insert between another no(y/n):";
        fflush(stdin);
    }while(getchar()!='n');
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
    n1.insert_begin();
    n1.display();
    n1.insert_between();
    n1.display();
    getch();
    return 2;
}