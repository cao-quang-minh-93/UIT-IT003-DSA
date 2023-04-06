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

void addAfter(List& l, int f, int x, Node* q)
{
    Node* p = getNode(x);
    if (q != NULL) {
        p->next = q->next;
        q->next = p;
        if (l.tail == q) {
            l.tail = p;
        }
    } else {
        addHead(l, x);
    }
}

void deleteNode(List& l, int n)
{
    Node* p = l.head;
    Node* prev = NULL;
    while (p != NULL)
    {
        if (p->info == n)
        {
            if (prev == NULL)
            {
                l.head = p->next;
                if (l.tail == p)
                    l.tail = NULL;
            }
            else
            {
                prev->next = p->next;
                if (l.tail == p)
                    l.tail = prev;
            }
            delete p;
            return;
        }
        prev = p;
        p = p->next;
    }
}


void deleteAll(List& l, int x)
{
    Node* p = l.head;
    Node* prev = NULL;
    while (p != NULL)
    {
        if (p->info == x)
        {
            if (prev == NULL)
            {
                l.head = p->next;
                if (l.tail == p)
                    l.tail = NULL;
            }
            else
            {
                prev->next = p->next;
                if (l.tail == p)
                    l.tail = prev;
            }
            Node* temp = p;
            p = p->next;
            delete temp;
        }
        else
        {
            prev = p;
            p = p->next;
        }
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
    freopen("process.inp","r",stdin);
    freopen("process.out","w",stdout);
    int x,f;
    List l;
    l.head=l.tail=NULL;
    while(1)
    {
        int a;
        cin>>a;
        if(a==6) break;
        else
            if(a==0)
            {
                cin>>x;
                addHead(l,x);
            }
            else
                if (a==1)
                {
                    cin>>x;
                    addTail(l,x);
                }
                else
                    if (a==2)
                    {
                        cin>>f>>x;
                        Node* q = l.head    ;
                        while (q != NULL && q->info != f)
                            q = q->next;
                        addAfter(l,f,x,q);
                    }
                    else
                        if(a==3)
                        {
                            cin>>x;
                            deleteNode(l,x);
                        }
                        else
                            if(a==4)
                            {
                                cin>>x;
                                deleteAll(l,x);
                            }
                            else
                                if(a==5)
                                {
                                    if (l.head != NULL)
                                        deleteNode(l,l.head->info);
                                }
    }
    PrintList(l);
    return 0;
}
