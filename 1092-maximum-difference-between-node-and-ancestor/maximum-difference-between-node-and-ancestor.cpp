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
// class Solution {
// public:
// int findMaxDiff(TreeNode* root,int &maxvalue,int &ans){
//     if(!root)return 0;
//     maxvalue=max(maxvalue,root->val);
//     ans=max(ans,maxvalue-root->val);
//     TreeNode* left = findMaxDiff(root->left,maxvalue,ans);
//     TreeNode* right = findMaxDiff(root->right,maxvalue,ans);
//     return ans;
// }
//     int maxAncestorDiff(TreeNode* root) {
//         return findMaxDiff(root,root->val,0);
        
//     }
// };

// class Solution {
// public:
//     int findMaxDiff(TreeNode* root, int maxvalue, int ans) {
//         if(!root) return ans;

//         maxvalue = max(maxvalue, root->val);
//         ans = max(ans, maxvalue - root->val);

//         int leftAns = findMaxDiff(root->left, maxvalue, ans);
//         int rightAns = findMaxDiff(root->right, maxvalue, ans);

//         return max(leftAns, rightAns);
//     }

//     int maxAncestorDiff(TreeNode* root) {
//         return findMaxDiff(root, root->val, 0);
//     }
// };

// class Solution {
// public:
//     int helper(TreeNode* root, int curMax, int curMin) {
//         if (!root) return curMax - curMin;

//         curMax = max(curMax, root->val);
//         curMin = min(curMin, root->val);

//         int leftDiff = helper(root->left, curMax, curMin);
//         int rightDiff = helper(root->right, curMax, curMin);

//         return max(leftDiff, rightDiff);
//     }

//     int maxAncestorDiff(TreeNode* root) {
//         if (!root) return 0;
//         return helper(root, root->val, root->val);
//     }
// };

class Solution {
public:
    int helper(TreeNode* root,int maxi,int mini){
        if(!root)return maxi-mini;

        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        int left=helper(root->left,maxi,mini);
        int right=helper(root->right,maxi,mini);
        return max(left,right);
    }

    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return helper(root, root->val, root->val);
    }
};
