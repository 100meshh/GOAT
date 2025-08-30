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
    bool isBST(TreeNode* root,long long &Prev){
        if(!root)return 1;
        if(!isBST(root->left,Prev)) return 0;   //bst has 2 sides
        if(root->val<=Prev) return 0; //inorder not followed
        Prev=root->val;
        return isBST(root->right,Prev);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long Prev=LLONG_MIN;
        return isBST(root,Prev);
        
    }
};