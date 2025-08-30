class Solution {
public:
    // helper function to generate all BSTs in range [start, end]
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> res;
        
        // base case: empty tree
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }

        // try each number as root
        for (int i = start; i <= end; i++) {
            // generate all left and right subtrees
            vector<TreeNode*> leftTrees = build(start, i - 1);
            vector<TreeNode*> rightTrees = build(i + 1, end);


            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};
