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
int helper(TreeNode* root,int ans){
    if(!root)return 0;
    ans=ans*10+root->val;
    if (!root->left && !root->right) return ans;
    int leftside=helper(root->left,ans);
    int rightside=helper(root->right,ans);
    return leftside+rightside;
}
    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
};