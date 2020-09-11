#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

#define size 10
class listarray
{
public:
    int info[size];
    int n=0;

    int searchpar(int);
    void insert_end();
    void insert_begin();
    void insert_before();
    void insert_after();
    void insert_bet();
    void display();
    void rev_display();
    void search1();
    void update();
    void del();
    void delbegin();
    void delend();
    void delafter();
    void delbefore();
    void delbet();
    void sort1();
};

void listarray :: insert_end()
{
    int x;
    if(n==size)
    {
        cout<<"\nList is Full";
        return;
    }
    cout<<"\nEnter a value to insert";
    cin>>x;
    info[n]=x;
    n++;
}

void listarray :: insert_begin()
{
    int x;
    if(n==size)
    {
        cout<<"\nList is Full";
        return;
    }
    cout<<"\nEnter a value to insert begin";
    cin>>x;
    for(int i=n-1;i>=0;i--)
    {
        info[i+1]=info[i];
    }
    info[0]=x;
    n++;
}

int listarray :: searchpar(int x)
{
    int f;
    f=-1;
    for(int i=0;i<n;i++)
    {
        if(info[i]==x)
        {
            f=i;
            break;
        }
    }
    return (f);
}

void listarray :: insert_after()
{
    int x,y,f;
    if(n==0 || n==size)
    {
        cout<<"\nVoid Insertion";
        return;
    }
    cout<<"\nEnter a no after insert";
    cin>>y;
    f=searchpar(y);
    if(f==-1)
    {
        cout<<"\n"<<y<<" is not present";
        return;
    }
    for(int i=n-1;i>f;i--)
    {
        info[i+1]=info[i];
    }
    cout<<"\nEnter a value to insert";
    cin>>x;
    info[f+1]=x;
    n++;
}

void listarray :: insert_before()
{
    int f,y,x;
    if(n==0 || n==size)
    {
        cout<<"\nVoid Insertion";
        return;
    }
    cout<<"\nEnter a no before insertion";
    cin>>y;
    f=searchpar(y);
    if(f==-1)
    {
        cout<<endl<<y<<" is not present";
        return;
    }
    for(int i=n-1;i>=f;i--)
    {
        info[i+1]=info[i];
    }
    cout<<"\nEnter a value to insert";
    cin>>x;
    info[f]=x;
    n++;
}

void listarray :: insert_bet()
{
    int x,y,z,p1,p2;
    if(n==0 || n==size)
    {
        cout<<"\nVoid Insertion";
        return;
    }
    cout<<"\nEnter two no between insert";
    cin>>y>>z;
    p1=searchpar(y);
    p2=searchpar(z);
    if(p1==-1 || p2==-1 || p1+1!=p2)
    {
        cout<<"\nVoid Insertion";
        return;
    }
    for(int i=n-1;i>=p2;i--)
    {
        info[i+1]=info[i];
    }
    cout<<"\nEnter a value to insert";
    cin>>x;
    info[p2]=x;
    n++;
}

void listarray :: display()
{
    if(n==0)
    {
        cout<<"\nList is empty";
        return;
    }
    cout<<"\nContents of List";
    for(int i=0;i<n;i++)
    {
        cout<<endl<<info[i];
    }
}

void listarray :: rev_display()
{
    if(n==0)
    {
        cout<<"\nList is empty";
        return;
    }
    cout<<"\nContents of list reversely";
    for(int i=n-1;i>=0;i--)
    {
        cout<<endl<<info[i];
    }
}

void listarray :: search1()
{
    int f,x;
    if(n==0)
    {
        cout<<"\nList is empty";
        return;
    }
    cout<<"\nEnter a no to search";
    cin>>x;
    f=searchpar(x);
    if(f==-1)
    {
        cout<<"\n"<<x<<" is not present";
    }
    else
    {
        cout<<endl<<x<<" is present at position "<<f;
    }
}

void listarray :: update()
{
    int x,f;
    if(n==0)
    {
        cout<<"List is empty";
        return;
    }
    cout<<"\nEnter a no to update";
    cin>>x;
    f=searchpar(x);
    if(f==-1)
    {
        cout<<"\n"<<x<<" is not present";
    }
    else
    {
        cout<<"\n"<<x<<" is present at postion "<<f;
        cout<<"\nEnter a new value";
        cin>>info[f];
    }
}

void listarray :: sort1()
{
    int x;
    if(n==0)
    {
        cout<<"\nList is empty";
        return;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(info[i]>info[j])
            {
                x=info[i];
                info[i]=info[j];
                info[j]=x;
            }
        }
    }
}

void listarray :: del()
{
    int x,f;
    if(n==0)
    {
        cout<<"\nList is empty";
        return;
    }
    cout<<"\nEnter a value to delete";
    cin>>x;
    f=searchpar(x);
    if(f==-1)
    {
        cout<<"\n"<<x<<" is not present";
        return;
    }
    cout<<endl<<x<<" is deleted at position "<<f;
    for(int i=f+1;i<n;i++)
    {
        info[i-1]=info[i];
    }
    n--;
}

void listarray :: delend()
{
    int x;
    if(n==0)
    {
        cout<<"\nList is empty";
        return;
    }
    x=info[n-1];
    n--;
    cout<<"\nDeleted no is"<<x;
}

void listarray :: delbegin()
{
    int x;
    if(n==0)
    {
        cout<<"\nList is empty";
        return;
    }
    x=info[0];
    for(int i=1;i<n;i++)
    {
        info[i-1]=info[i];
    }
    n--;
    cout<<"\nDeleted no is "<<x;
}

void listarray :: delafter()
{
    int x,f;
    if(n==0)
    {
        cout<<"\nList is empty";
        return;
    }
    cout<<"\nEnter a no after delete";
    cin>>x;
    f=searchpar(x);
    if(f==-1 || f==n-1)
    {
        cout<<"\nVoid deletion";
        return;
    }
    cout<<"\nDeleted no is "<<info[f+1];
    for(int i=f+2;i<n;i++)
    {
        info[i-1]=info[i];
    }
    n--;
}

void listarray :: delbefore()
{
    int x,f;
    if(n==0)
    {
        cout<<"\nList is empty";
        return;
    }
    cout<<"\nEnter a value to delete before";
    cin>>x;
    f=searchpar(x);
    if(f==-1 || f==n-n)
    {
        cout<<"\nVoid deletion";
        return;
    }
    cout<<"\nDeleted no is "<<info[f-1];
    for(int i=f;i<n;i++)
    {
        info[i-1]=info[i];
    }
    n--;
}

void listarray :: delbet()
{
    int x,y,p1,p2;
    if(n==0)
    {
        cout<<"\nList is empty";
        return;
    }
    cout<<"\nEnter two no between delete";
    cin>>x>>y;
    p1=searchpar(x);
    p2=searchpar(y);
    if(p1==-1 || p2==-1 || p1+1==p2)
    {
        cout<<"\nVoid Deletion";
        return;
    }
    cout<<"\nList is deleted No";
    while(info[p1+1]!=y)
    {
        cout<<endl<<info[p1+1];
        for(int i=p1+2;i<n;i++)
        {
            info[i-1]=info[i];
        }
        n--;
    }
}

int main()
{
    listarray l1;
    int ch;
    do
    {
        cout<<"\n1.Insert End\n2.Insert Begin\n3.Insert After\n4.Insert Before\n5.Insert Between\n6.Display";
        cout<<"\n7.Reverse Display\n8.Search\n9.Update\n10.Delete\n11.Delete Begin\n12.Delete End\n13.Delete After";
        cout<<"\n14.Delete Before\n15.Delete Between\n16.Sort\n0.Exit";
        cout<<"\nEnter Your Choice";
        cin>>ch;
        switch(ch)
        {
            case 1:l1.insert_end();break;
            case 2:l1.insert_begin();break;
            case 3:l1.insert_after();break;
            case 4:l1.insert_before();break;
            case 5:l1.insert_bet();break;
            case 6:l1.display();break;
            case 7:l1.rev_display();break;
            case 8:l1.search1();break;
            case 9:l1.update();break;
            case 10:l1.del();break;
            case 11:l1.delbegin();break;
            case 12:l1.delend();break;
            case 13:l1.delafter();break;
            case 14:l1.delbefore();break;
            case 15:l1.delbet();break;
            case 16:l1.sort1();break;
            case 0:exit(0);
        }
        getch();
        system("cls");
    }
    while(2);
    return 1;
}
