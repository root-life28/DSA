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

int dfs(struct node *root,int mx)
{
    if(root==NULL) return 0;
    

    int temp=1?root->val>=mx:0;
    mx=max(mx,root->val);

    temp+=dfs(root->left,mx);
    temp+=dfs(root->right,mx);

    return temp;
    
}

int GoodNode(struct node *root)
{
    int ans=dfs(root,root->val);

    return ans;

}


int main()
{
    struct node *root=NULL;
    root=insertNode(root,2);

    insertNode(root,6);
    insertNode(root,8);
    insertNode(root,0);
    insertNode(root,4);
    insertNode(root,7);
    insertNode(root,9);
    insertNode(root,3);
    insertNode(root,5);

  cout<<GoodNode(root);

 
    return 0;
}