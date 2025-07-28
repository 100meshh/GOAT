class Solution {
public:
    int maxOr = 0;
    int count = 0;

    void dfs(vector<int>& nums, int index, int currentOr) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }

        // Include current element
        dfs(nums, index + 1, currentOr | nums[index]);

        // Exclude current element
        dfs(nums, index + 1, currentOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        // Step 1: Compute max OR possible
        for (int num : nums) {
            maxOr |= num;
        }

        // Step 2: DFS to count subsets reaching max OR
        dfs(nums, 0, 0);

        return count;
    }
};
