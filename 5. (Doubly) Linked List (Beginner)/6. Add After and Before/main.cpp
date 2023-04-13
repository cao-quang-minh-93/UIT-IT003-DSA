#include <bits/stdc++.h>

#define f(a,b,n) for(int a=b;a<=n;a++)
#define fd(a,b,n) for(int a=b;a>=n;a--)
#define ll long long


using namespace std;

////////////////////////////////////////////////
/*****************--DECLARE--******************/
struct DNode
{
	int info;
	DNode *pNext, *pPrev;
};

struct DList
{
	DNode *pHead, *pTail;
};
////////////////////////////////////////////////
DNode *getNode (int x)
{
    DNode *p = new DNode;
    if (p == NULL)
    {
        cout << "Full Memory";
        exit(1);
    }
    else
    {
        p->info = x;
        p->pNext = p->pPrev = NULL;
        return p;
    }
}

void init (DList &l)
{
    l.pHead = l.pTail = NULL;
}

void addTail(DList &l, int x)
{
    DNode *p = getNode(x);
    if (l.pHead == NULL)
        l.pTail = l.pHead = p;
    else
    {
        p->pPrev = l.pTail;
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void addHead(DList &l, int x)
{
    DNode *p = getNode(x);
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        p->pNext = l.pHead;
        l.pHead->pPrev = p;
        l.pHead = p;
    }
}

void addAfter(DList &l, int val, int newVal)
{
    DNode *p = l.pHead;
    while (p != NULL)
    {
        if (p->info == val)
        {
            DNode *newNode = getNode(newVal);
            newNode->pNext = p->pNext;
            newNode->pPrev = p;
            if (p->pNext != NULL)
                p->pNext->pPrev = newNode;
            else
                l.pTail = newNode;
            p->pNext = newNode;
            return;
        }
        p = p->pNext;
    }
    cout << "\nCan't find the value " << val;
}

void addBefore(DList &l, int val, int newVal)
{
    DNode *p = l.pHead;
    while (p != NULL)
    {
        if (p->info == val)
        {
            DNode *newNode = getNode(newVal);
            newNode->pNext = p;
            newNode->pPrev = p->pPrev;
            if (p->pPrev != NULL)
                p->pPrev->pNext = newNode;
            else
                l.pHead = newNode;
            p->pPrev = newNode;
            return;
        }
        p = p->pNext;
    }
    cout << "\nCan't find the value " << val;
}

void createList(DList &l)
{
    int x;
    while (1)
    {
        cin >> x;
        if (x == -1)
            return;
        addTail(l, x);
    }
}

void printList(DList l)
{
    DNode *p = l.pHead;
    if (p == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        while (p != NULL)
        {
            cout << p->info << " ";
            p = p->pNext;
        }
    }
}
////////////////////////////////////////////////
/*******************--MAIN--*******************/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("process.inp","r",stdin);
    freopen("process.out","w",stdout);
	DList L;
	init(L);
	int x,y,choice;

	cout<<"MENU:";
    cout<<"\n1. Create a DList";
    cout<<"\n2. Print the DList";
    cout<<"\n3. Insert a value at the front";
    cout<<"\n4. Insert a value at the end";
    cout<<"\n5. Insert a value after a given value (only for the first value found)";
    cout<<"\n6. Insert a value before a given value (only for the first value found)";
    cout<<"\n7. Insert a value after a given value (for all the same values)";
    cout<<"\n8. Insert a value before a given value (for all the same values)";
    cout<<"\n20. Exit"<<endl;

	while(true)
    {
        cout<<"\n\t\tPLEASE SELECT YOUR CHOICE: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\nEnter your positive integers until you enter -1 to finish: ";
            createList(L);
            break;
        case 2:
            cout<<"\nYour current DList: ";
            printList(L);
            break;
        case 3:
            cout<<"\nEnter a number: ";
            cin>>x;
            addHead(L,x);
            break;
        case 4:
            cout<<"\nEnter a number: ";
            cin>>x;
            addTail(L,x);
            break;
        case 5:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addAfter(L,x,y);
            break;
        case 6:
            cout<<"\nEnter two numbers: ";
            cin>>x>>y;
            addBefore(L,x,y);
            break;
        case 20:
            cout<<"\nGOOD BYE";
            return 0;

        }
    }

	return 0;
}
////////////////////////////////////////////////
/*******************--QMIN--*******************/
