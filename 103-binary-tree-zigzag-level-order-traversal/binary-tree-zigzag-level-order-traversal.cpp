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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty() || !st2.empty()) {
            vector<int> level;

            // left -> right
            while(!st1.empty()) {
                TreeNode* node = st1.top(); st1.pop();
                level.push_back(node->val);

                if(node->left) st2.push(node->left);
                if(node->right) st2.push(node->right);
            }
            if(!level.empty()) ans.push_back(level);

            level.clear();

            //right -> left
            while(!st2.empty()) {
                TreeNode* node = st2.top(); st2.pop();
                level.push_back(node->val);

                if(node->right) st1.push(node->right);
                if(node->left) st1.push(node->left);
            }
            if(!level.empty()) ans.push_back(level);
        }

        return ans;
    }
};
