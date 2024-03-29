#include <bits/stdc++.h>

#define f(a,b,n) for(int a=b;a<=n;a++)
#define fd(a,b,n) for(int a=b;a>=n;a--)
using namespace std;

////////////////////////////////////////////////
struct Node
{
    int info;
    Node *next;
};

struct List
{
	Node* head;
	Node* tail;
};

Node* getNode(int x)
{
    Node *p = new Node;
    if (p!=NULL)
    {
        p->info = x;
        p->next=NULL;
    }
    return p;
}

void addHead (List &l, int x)
{
	Node *p = getNode(x);
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}

void addTail(List& l, int x)
{
    Node *p = getNode(x);
    if (l.head == NULL)
    {
        l.head = l.tail = p;
    }
    else
    {
        l.tail->next = p;
        l.tail = p;
        p->next = NULL;
    }
}

void PrintList(List l)
{
    Node *p;
    p = l.head;
    while(p!=NULL)
    {	cout<<p->info<<" ";
        p=p->next;
    }
}

////////////////////////////////////////////////
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int x;
    List l;
    l.head=l.tail=NULL;
    while(1)
    {
        int a;
        cin>>a;
        if(a==3) break;
        else
            if(a==0)
            {
                cin>>x;
                addHead(l,x);
            }
            else
            {
                cin>>x;
                addTail(l,x);
            }

    }
    PrintList(l);
    return 0;
}
