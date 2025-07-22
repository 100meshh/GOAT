class Solution {
public:
    // int maximumUniqueSubarray(vector<int>& nums) {
    //     int i=0,j=0;
    //     int ans=0;
    //     while(j<nums.size()){
            
    //     }
    // }


int maximumUniqueSubarray(vector<int>& nums) {
    vector<int> freq(10001, 0);  // Frequency array for numbers 1 to 10^4
    int left = 0;
    int current_sum = 0;
    int max_sum = 0;

    for (int right = 0; right < (int)nums.size(); ++right) {
        freq[nums[right]]++;
        current_sum += nums[right];

        // If duplicate detected, shrink from left until no duplicates
        while (freq[nums[right]] > 1) {
            freq[nums[left]]--;
            current_sum -= nums[left];
            left++;
        }

        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}
};