#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    
 };
 
class Solution {
public:
    int index=0;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int inOrderStart, int inOrderEnd)
    {
        if(index>=preorder.size()||inOrderStart>inOrderEnd) return NULL;
        
        
        int ele=preorder[index++];
        TreeNode*root=new TreeNode(ele);
        int pos=find(inorder.begin(), inorder.end(), ele) - inorder.begin(); 
        
        root->left=build(preorder,inorder,inOrderStart,pos-1);
        root->right=build(preorder,inorder,pos+1,inOrderEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

      
        
        return build(preorder,inorder,0,preorder.size()-1);
        
    }
};