/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void inoder(TreeNode *root,vector<int>&ans){
      if(!root) return;
      inoder(root->left,ans);
      ans.push_back(root->val);
      inoder(root->right,ans);
  }
    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
        inoder(root,ans);
        int mini=INT_MAX;
        for(int i=1;i<ans.size();i++){
            int ret=ans[i]-ans[i-1];
            mini=min(mini,ret);
        }
        return mini;
    }
};