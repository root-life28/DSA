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

vector<vector<int>> levelOrder(struct node *root)
{
    vector<vector<int>>res;
    if(root==NULL) return res;
    queue<struct node *>qu;
    qu.push(root);

    while (!qu.empty())
    {
        int size=qu.size();
       vector<int>vr;
       
        for (int i = 0; i < size; i++)
        {
            auto x=qu.front();
            qu.pop();
            vr.push_back(x->val);
            if(x->left!=NULL) qu.push(x->left);
            if(x->right!=NULL)qu.push(x->right);
        }
        
        res.push_back(vr);
    }
    
    return res;
}


int main()
{
    struct node *root=NULL;
    root=insertNode(root,4);

    insertNode(root,2);
    insertNode(root,5);
    insertNode(root,1);
    insertNode(root,3);
    insertNode(root,6);

    vector<vector<int>>res=levelOrder(root);

    for(auto x:res){
    for(auto y:x)cout<<y<<" "; 
    cout<<endl;
    }

    return 0;
}