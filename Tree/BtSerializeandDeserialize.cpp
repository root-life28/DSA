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

string serialize(struct node *root)
{
    if(!root) return "" ;
        queue<struct node*> q ;
        q.push(root) ;
        
        string res = "" ;
        
        while(q.size()){
            auto node = q.front() ; q.pop() ;
            if(node) res += to_string(node->val) ;
            else res.push_back('#') ;
            res.push_back(',');
            
            if(node){ q.push(node->left) ; q.push(node->right) ; }
            
        }
        res.pop_back() ;
        return res ;

}

struct node *DFS(string s)
{
    if(s.empty()) return nullptr;

    stringstream ss(s);

    string st="";
    queue<struct node *>q;
   getline(ss,st,',');
   struct node *root=createNode(stoi(st));
   q.push(root);

   while (q.size())
   {
     auto n=q.front();q.pop();

     getline(ss,st,',');
     if(st=="#")n->left=nullptr;

     else {
        struct node *x=createNode(stoi(st));
        n->left=x;
        q.push(x);
     }
    getline(ss,st,',');
    if(st=="#")n->right=nullptr;

     else {
        struct node *x=createNode(stoi(st));
        n->right=x;
        q.push(x);
     }


   }
   
   return root;

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

    string x=serialize(root);
   cout<<x<<endl;
    struct node*y=DFS(x);

  print(y);


 
    return 0;
}