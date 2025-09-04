class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& ans) {
        ans.push_back(temp);

        for(int i = start; i < nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1]) continue; // skip duplicates
            temp.push_back(nums[i]);
            backtrack(nums, i+1, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, temp, ans);
        return ans;
    }
};
