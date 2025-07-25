class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool containsNonNegative = false;
        int highestNumber = INT_MIN;

        for (int element : nums) {
            if (element >= 0) {
                containsNonNegative = true;
            }
            if (element > highestNumber) {
                highestNumber = element;
            }
        }
        if (!containsNonNegative)
            return highestNumber;

        bool presence[101] = {false};
        for (int element : nums) {
            if (element >= 0 && element < 101) {
                presence[element] = true;
            }
        }

        int accumulatedSum = 0;
        for (int i = 1; i < 101; i++) {
            if (presence[i]) {
                accumulatedSum += i;
            }
        }

        return accumulatedSum;
    }
};