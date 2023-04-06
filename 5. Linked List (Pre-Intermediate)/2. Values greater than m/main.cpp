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

void Init(List &l)
{
    l.head = NULL;
    l.tail = NULL;
}

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

void inputList(List& l, int n)
{
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
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
}



void outputList(List l)
{
    Node *p = l.head;
    if (p == NULL)
        cout<<"List is empty";
    else
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
}

void outputGreaterThan(List l, int m)
{
    Node *p = l.head;
    bool check=0;
    if (l.head == NULL)
    {
        cout<<"List is empty";
        return ;
    }
    else
    {
        while (p != NULL)
        {
            if (p->info > m)
            {
                cout<<p->info<<" ";
                check = 1;
            }
            p = p->next;
        }
        if (!check)
            cout<<"None";
    }
}
////////////////////////////////////////////////

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("process.inp","r",stdin);
    freopen("process.out","w",stdout);
    List L; // Khai bao 1 danh sach
    Init(L); // Khoi tao danh sach
    int n; cout<<"Enter a number: "; cin>>n; // Nhap so luong phan tu cua ds
    cout<<"\nEnter a sequence of "<<n<<" numbers: ";
    inputList(L,n); // Nhap 1 day gom n so va luu vao ds. Phan tu moi duoc them vao cuoi ds
    cout<<"\nThe created Linked List: ";
    outputList(L); // Xuat ds. Neu ds rong thi xuat thong bao "List is empty"


    cout<<"\nEnter a number: "; int m; cin>>m;
    cout<<"\nValues greater than "<<m<<": ";
    outputGreaterThan(L,m);
    /*Xuat tat ca cac gia tri duoc luu trong ds lon hon m.
     Neu ds rong thi xuat thong bao "List is empty".
     Neu ds khong rong nhung khong co gia tri thoa yeu cau thi xuat "None"*/

    return 0;
}
