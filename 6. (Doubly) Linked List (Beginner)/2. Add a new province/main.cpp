#include <bits/stdc++.h>

#define f(a,b,n) for(int a=b;a<=n;a++)
#define fd(a,b,n) for(int a=b;a>=n;a--)

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
void inputprovices(province &im)
{
    cin>>im.ID;
    cin.ignore();
    getline(cin,im.NAME);
    cin>>im.POP;
    cin>>im.AREA;
}

void inputListProvinces(List &L)
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        province im;
        inputprovices(im);
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
////////////////////////////////////////////////
void addAfter(List& l, province x, node* q)
{
    node* p = getNode(x);
        p->next = q->next;
        q->next = p;
        if (l.tail == q)
            l.tail = p;
}

node *check(List L, string im)
{
    node *p =L.head;
    while(p != NULL)
    {
        if(p->info.NAME == im) return p;
        else p=p->next;
    }
    return NULL;
}

void task(List &l)
{
    string add;
    cin.ignore();
    getline(cin,add);
    province x;
    node *p = check(l,add);
    if (p==NULL)
        cout<<"Not found"<<endl;
    else
        {
            cout<<"Input a new province:"<<endl;
            inputprovices(x);
            addAfter(l,x,p);
            cout<<"Updated List:"<<endl;
            cout<<"ID\t|Province\t|Population\t|Area"<<endl;
            outputListProvinces(l);
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
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);
    cout<<"Enter the name to search:"<<endl;

    task(L);
    return 0;
}
////////////////////////////////////////////////
/*******************--QMIN--*******************/