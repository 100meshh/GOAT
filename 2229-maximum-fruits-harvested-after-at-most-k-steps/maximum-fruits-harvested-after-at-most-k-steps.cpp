class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int windowStart = 0, currentSum = 0, maxCollected = 0;
        for (int windowEnd = 0; windowEnd < fruits.size(); ++windowEnd) {
            currentSum += fruits[windowEnd][1];
            while (windowStart <= windowEnd && minSteps(fruits[windowStart][0], fruits[windowEnd][0], startPos) > k) {
                currentSum -= fruits[windowStart][1];
                windowStart++;
            }
            maxCollected = max(maxCollected, currentSum);
        }
        return maxCollected;
    }

    int minSteps(int leftPos, int rightPos, int start) {
        return min(abs(start - leftPos) + (rightPos - leftPos),
                   abs(start - rightPos) + (rightPos - leftPos));
    }
};
