#include <iostream>
using namespace std;

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
////////////////////////////////////////////////

int countNodes(Tree root)
{
    if(root == NULL) return 0;
    return countNodes(root->left) + countNodes(root->right) +1;
}

int countLeafs(Tree root)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL)
            return countLeafs(root->left) + countLeafs(root->right) +1;
        else
            return countLeafs(root->left) + countLeafs(root->right);
}

int cnt(Tree root)
{
    if (root == 0) return 0;
    else
    if((root->left == NULL && root->right == NULL))
        return 0;
    return cnt(root->left) + cnt(root->right) +1;
}


int countInternalNodes(Tree root)
{
    if(root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
    return 0;
    return cnt(root) -1;
}

int countOneChild(Tree root)
{
    if(root == NULL) return 0;
    if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        return countOneChild(root->left) + countOneChild(root->right)+1;
    return countOneChild(root->left) + countOneChild(root->right);
}

int countTwoChildren(Tree root)
{
    if(root == NULL) return 0;
    if(root->left != NULL && root->right != NULL)
        return countTwoChildren(root->left) + countTwoChildren(root->right)+1;
    return countTwoChildren(root->left) + countTwoChildren(root->right);
}

int countLess(Tree root,int x)
{
    if(root == NULL) return 0;
    if(root->info < x) return countLess(root->left,x)+ countLess(root->right,x) +1;
    return countLess(root->left,x) + countLess(root->right,x);
}

int countBetweenValues(Tree root,int x,int y)
{
    if(root == NULL) return 0;
    if(root->info > x && root->info <y) return countBetweenValues(root->left,x,y)+ countBetweenValues(root->right,x,y) +1;
    return countBetweenValues(root->left,x,y) + countBetweenValues(root->right,x,y);
}

int main()
{
	Tree T = NULL;
	inputTree(T);

    cout<<"Number of nodes: " << countNodes(T)<<endl;
	cout<<"Number of leaf nodes: " << countLeafs(T)<<endl;
	cout<<"Number of internal nodes: "<< countInternalNodes(T)<<endl;
	cout<<"Number of nodes with one child: "<< countOneChild(T)<<endl;
	cout<<"Number of nodes with two children: "<< countTwoChildren(T)<<endl;

	int x;cout<<"Enter x: ";cin>>x;
	cout<<"\nNumber of nodes less than "<<x<<": "<< countLess(T,x)<<endl;
	int y; cout<<"Enter x,y: ";cin>>x>>y;
	cout<<"\nNumber of nodes greater than "<<x<<" and less than "<<y<<": "<< countBetweenValues(T,x,y)<<endl;

	return 0;
}
