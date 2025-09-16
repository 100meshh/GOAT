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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        // line -> row -> sorted set of values
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*, pair<int,int>>> q; // node, {line, row}

        q.push({root, {0,0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;
            int line = it.second.first;  // column
            int row  = it.second.second; // depth

            mpp[line][row].insert(node->val);

            if (node->left) {
                q.push({node->left, {line-1, row+1}});
            }
            if (node->right) {
                q.push({node->right, {line+1, row+1}});
            }
        }

        for (auto &col : mpp) {
            vector<int> colNodes;
            for (auto &row : col.second) {
                colNodes.insert(colNodes.end(), row.second.begin(), row.second.end());
            }
            ans.push_back(colNodes);
        }

        return ans;
    }
};
