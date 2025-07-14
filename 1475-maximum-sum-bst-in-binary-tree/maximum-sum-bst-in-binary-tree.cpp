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
//     int maxSumBST(TreeNode* root) {
        
//     }
// };

class Nodeval {
public:
    bool bst;
    int sum;
    int min, max;

    Nodeval() {
        bst = true;
        sum = 0;
        min = INT_MAX;
        max = INT_MIN;
    }
};

class Solution {
public:
    int maxSum = 0;

    Nodeval largestbst(TreeNode* root) {
        if (!root) return Nodeval();

        Nodeval left = largestbst(root->left);
        Nodeval right = largestbst(root->right);

        Nodeval curr;

        if (left.bst && right.bst && left.max < root->val && root->val < right.min) {
            curr.bst = true;
            curr.sum = left.sum + right.sum + root->val;
            curr.min = min(root->val, left.min);
            curr.max = max(root->val, right.max);

            maxSum = max(maxSum, curr.sum);
        } else {
            curr.bst = false;
        }

        return curr;
    }

    int maxSumBST(TreeNode *root) {
        maxSum = 0;
        largestbst(root);
        return maxSum;
    }
};