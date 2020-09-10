#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

//struct node
class node
{
    public:
       int info;
       node *next;
};
node *start=NULL;

int main()
{
    node *t,*cur;
    do
    {
        system("cls");
        //t=(node *)malloc(sizeof(node));
        t=new node();
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
        cout<<"\nAnother Node(y/n):";
        fflush(stdin);
    }while(getchar()!='n');
    cout<<"\nContents:\n";
    cur=start;
    while(cur != NULL)
    {
        cout<<"\n"<<cur->info;
        cur=cur->next;
    }
    getch();
    return 2;
}
