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

void print (struct node *root)
{
    if(root==NULL) return ;

    cout<<root->val<<" ";
    print(root->left);
    print(root->right);
}

vector<int> RightView(struct node *root)
{
    
    vector<int> ans;
    if(root==NULL) return ans;
    queue<struct node *>qu;
    qu.push(root);

    while (!qu.empty())
    {
        int size=qu.size();
  
       int temp=0;
        for (int i = 0; i < size; i++)
        {
            auto x=qu.front();
            qu.pop();
            temp=x->val;
            if(x->left!=NULL) qu.push(x->left);
            if(x->right!=NULL)qu.push(x->right);
        }
        
       cout<<temp<<" ";
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

    vector<int> vr=RightView(root);

    for(auto x:vr)cout<<x<<" ";

 
    return 0;
}