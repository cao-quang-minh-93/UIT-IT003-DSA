#include <iostream>
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
        {
            cin>>x;
            addHead(l,x);
        }
    }
    PrintList(l);
    return 0;
}
