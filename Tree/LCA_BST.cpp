#include<bits/stdc++.h>
using namespace std;

int ans=0;

struct node{
    int val;
    struct node *left,*right;
   
};

struct node *createNode(int val)
{
     struct node *temp=new struct node;
     temp->val=val;
     temp->left=temp->right=NULL;
     return temp;
}

struct node *insertNode(struct node *root,int val)
{
    if(root==NULL) return root= createNode(val);

    if(val<=root->val)
     root->left= insertNode(root->left,val);
    else root->right=insertNode(root->right,val);

    return root;  
}

void print (struct node *root)
{
    if(root==NULL) return ;

    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

int LCA(struct node *root,int a,int b)
{
    if(root->val>a&&root->val>b)
    {
        LCA(root->left,a,b);
    }
    else if(root->val<a&&root->val<b)
    {
        LCA(root->left,a,b);
    }
    else 
    {
        return ans=root->val;
    }

    return ans;
}

int main()
{
    struct node *root=NULL;
    root=insertNode(root,6);

    insertNode(root,2);
    insertNode(root,8);
    insertNode(root,0);
    insertNode(root,4);
    insertNode(root,7);
    insertNode(root,9);
    insertNode(root,3);
    insertNode(root,5);


    cout<<LCA(root,2,4);

 
    return 0;
}