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
    int maxSum(TreeNode*root,int &mx)
    {
        if(root==NULL) return 0;
       
        int left=max(0,maxSum(root->left,mx));
        int right=max(0,maxSum(root->right,mx));
        
        mx=max(mx,left+right+root->val);
        
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        
        int mx=INT_MIN;
       int x= maxSum(root,mx);
        return mx;
    }
};