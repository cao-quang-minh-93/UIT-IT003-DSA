#include <bits/stdc++.h>

#define f(a,b,n) for(int a=b;a<=n;a++)
#define fd(a,b,n) for(int a=b;a>=n;a--)

using namespace std;

////////////////////////////////////////////////

struct node
{
    int info;
    node *next;
};

struct List
{
	node* head;
	node* tail;
};

void Init(List &l)
{
    l.head = NULL;
    l.tail = NULL;
}

node* getNode(int x)
{
    node *p = new node;
    if (p!=NULL)
    {
        p->info = x;
        p->next=NULL;
    }
    return p;
}

void inputList(List& l, int n)
{
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        node *p = getNode(x);
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
}

void outputList(List l)
{
    node *p = l.head;
    if (p == NULL)
        cout<<"List is empty";
    else
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}

node *findElement(List l, int i)
{
    if (l.head == NULL)
    {
        cout << "List is empty";
        return NULL;
    }

    int dem = 1;
    node *p = l.head;
    while (p != NULL)
    {
        if (i == dem)
            return p;
        dem++;
        p = p->next;
    }

    if (i > dem)
    {
        cout << "The index is invalid";
        return NULL;
    }
}

////////////////////////////////////////////////

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("process.inp","r",stdin);
    freopen("process.out","w",stdout);
    List L;
    Init(L);
    int n; cout<<"Enter a number: "; cin>>n;
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n);
    cout<<"\nThe created Linked List: ";
    outputList(L);

    int i; cout<<"\nEnter a number: "; cin>>i;
    cout<<"\nThe element at index "<<i<<": ";
    node *p = findElement(L,i);
    if(p) cout<<p->info;


    return 0;
}

