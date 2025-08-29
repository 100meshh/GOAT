class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //brute force
        int i=0,j=0;
        vector<int>ans;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]==nums2[j]){
                int element=-1;
                for(int k=j+1;k<nums2.size();k++){
                    if(nums2[k]>nums1[i]) {
                        element=nums2[k] ;
                        break;
                    }
                }
                ans.push_back(element);
                i++;
                j=0;
            }
            else
            j++;
        }
        return ans;
    }
};