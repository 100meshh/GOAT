class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
      int maxLength = 2;
        for (int remainderTarget = 0; remainderTarget < k; ++remainderTarget) {
            vector<int> dp(k, 0);
            for (int num : nums) {
                int remainder = num % k;
                int requiredPrevRemainder = (remainderTarget - remainder + k) % k;
                dp[remainder] = dp[requiredPrevRemainder] + 1;
            }

            for (int length : dp) {
                maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }   
};