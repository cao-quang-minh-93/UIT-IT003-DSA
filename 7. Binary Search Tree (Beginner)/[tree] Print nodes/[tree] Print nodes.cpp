

#include <iostream>
using namespace std;

////////////////////////////////////////////////
struct Node
{
    int info;
    Node* left;
    Node* right;
};

typedef Node* Tree;

Node* getNode(int x)
{
    Node *p = new Node;
    if (p!=NULL)
    {
        p->info = x;
        p->left=NULL;
        p->right=NULL;
    }
    return p;
}
////////////////////////////////////////////////
void insertNode(Tree &root, int info)
{
    if (root == NULL)
        root = getNode(info);
    else
        if (info < root->info)
            insertNode(root->left, info);
        else
            if (info > root->info)
                insertNode(root->right, info);
}

void inputTree(Tree& root)
{
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertNode(root,x);
    }
}


void NLR(Tree root)
{
    if (root != NULL)
    {
        cout << root->info << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LRN(Tree root)
{
    if (root != NULL)
    {
        LRN(root->left);
        LRN(root->right);
        cout << root->info << " ";
    }
}

void LNR(Tree root)
{
    if (root != NULL)
    {
        LNR(root->left);
        cout << root->info << " ";
        LNR(root->right);
    }
}

void listLeafs(Tree root)
{
    if(root != NULL)
    {
        listLeafs(root->left);
        listLeafs(root->right);
        if(root->left == NULL && root->right == NULL)
        cout << root->info << " ";
    }
}

void listInternalNodes(Tree root,int check)
{

    if(root != NULL)
    {
        if((root->left != NULL || root->right != NULL) && check!=0)
            cout << root->info << " ";
        listInternalNodes(root->left,1);
        listInternalNodes(root->right,1);
    }
}

void listNodesWithOneChild(Tree root)
{
    if(root != NULL)
    {
        if((root->left == NULL && root->right != NULL) ||(root->left != NULL && root->right == NULL))
            cout << root->info << " ";
        listNodesWithOneChild(root->left);
        listNodesWithOneChild(root->right);
    }
}

void listNodesWithTwoChildren(Tree root)
{
    if(root != NULL)
    {
        if(root->left != NULL && root->right != NULL)
            cout << root->info << " ";
        listNodesWithTwoChildren(root->left);
        listNodesWithTwoChildren(root->right);
    }
}

////////////////////////////////////////////////

int main()
{
	Tree T = NULL;
	inputTree(T);
	cout<<"\nNLR: "; NLR(T);
	cout<<"\nLRN: "; LRN(T);
	cout<<"\nLNR: "; LNR(T);

	cout<<"\nLeaf nodes: "; listLeafs(T);
	cout<<"\nInternal nodes: "; listInternalNodes(T,0);
	cout<<"\nNodes with one child: "; listNodesWithOneChild(T);
	cout<<"\nNodes with two children: "; listNodesWithTwoChildren(T);

	return 0;
}
