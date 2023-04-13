#include <bits/stdc++.h>

#define f(a,b,n) for(int a=b;a<=n;a++)
#define fd(a,b,n) for(int a=b;a>=n;a--)
#define ll long long


using namespace std;

////////////////////////////////////////////////
/*****************--DECLARE--******************/
struct province
{
    int ID;
    string NAME;
    int POP;
    double AREA;
};

struct node
{
    province info;
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

node* getNode(province x)
{
    node *p = new node;
    if (p!=NULL)
    {
        p->info = x;
        p->next=NULL;
    }
    return p;
}

void addHead (List &l, province x)
{
    node *p = getNode(x);
    if (l.head == NULL)
        l.head = l.tail = p;
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

void addTail(List& l, province x)
{
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


////////////////////////////////////////////////
void inputListProvinces(List &L)
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        province im;
        cin>>im.ID;
        cin.ignore();
        getline(cin,im.NAME);
        cin>>im.POP;
        cin>>im.AREA;
        addTail(L,im);
    }
}
void outputProvince(province p)
{
    cout<<p.ID<<"\t"<<p.NAME<<"\t"<<p.POP<<"\t"<<p.AREA<<endl;
}

void outputListProvinces(List l)
{
    node *p = l.head;
    while(p!=NULL)
    {
        outputProvince(p->info);
        p = p->next;
    }
}

void outputProvincesMore1MillionPop(List l)
{
    node *p = l.head;
    while(p!=NULL)
    {
        if(p->info.POP > 1000)
            outputProvince(p->info);
        p = p->next;
    }
}

node* findProMaxArea(List l)
{
    node *p = l.head;
    node *maxNode = p;
    double maxArea = p->info.AREA;
    while(p != NULL)
    {
        if(p->info.AREA > maxArea)
        {
            maxArea = p->info.AREA;
            maxNode = p;
        }
        p = p->next;
    }
    return maxNode;
}
////////////////////////////////////////////////
/*******************--MAIN--*******************/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("process.inp","r",stdin);
    freopen("process.out","w",stdout);
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);

    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);

    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p->info);

    return 0;
}

////////////////////////////////////////////////
/*******************--QMIN--*******************/
