class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even =0;
        int odd=0;
        int alt=1;
        int prev= nums[0];
        if(prev%2==0)even++;
        else odd++;
        for(int i=1;i<nums.size();i++){
            if(nums[i]%2 != prev %2){
                alt++;
                prev=nums[i];
            }
            if(nums[i]%2==0) even++;
            else odd++;
        }
        return max(alt,max(even,odd));
    }
};