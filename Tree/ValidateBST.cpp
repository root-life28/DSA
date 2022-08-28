#include<bits/stdc++.h>
using namespace std;
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
bool isValidate(struct node *root,long long int left,long long int right)
{
    if(root==NULL)return true;
   if(root->val>=right||root->val<=left) return false;

    return isValidate(root->left,left,root->val)&&isValidate(root->right,root->val,right);
}
bool BSTValidation( struct node *root)
{
    return isValidate(root,LONG_LONG_MIN,LONG_LONG_MAX);
}


int main()
{
    struct node *root=NULL;
    root=insertNode(root,6);

    insertNode(root,2);
    insertNode(root,0);
    insertNode(root,4);
    insertNode(root,7);
    insertNode(root,9);
    insertNode(root,3);
    insertNode(root,5);

    cout<<BSTValidation(root)<<endl;

 
    return 0;
}