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
void print (struct node *root,int &c,int &ans)
{
   
    
     if(root==NULL) return ;
    print(root->left,c,ans);
    c--;
    if(c==0) ans=root->val;
    print(root->right,c,ans);


}

int main()
{
    struct node *root=NULL;
    root=insertNode(root,50);

    insertNode(root,48);
    insertNode(root,70);
    insertNode(root,30);
    insertNode(root,65);
    insertNode(root,90);
    insertNode(root,20);
    insertNode(root,32);
    insertNode(root,67);
    insertNode(root,98);
    insertNode(root,15);
    insertNode(root,25);
    insertNode(root,31);
    insertNode(root,35);
    insertNode(root,66);
    insertNode(root,69);
    insertNode(root,94);
    insertNode(root,99);

    int x=4;
    int ans=0;
     
     print(root,x,ans);
     cout<<ans;
   
 
    return 0;
}