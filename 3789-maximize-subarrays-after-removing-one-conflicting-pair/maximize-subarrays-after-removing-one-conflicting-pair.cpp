class Solution {
private:
    static constexpr uint MAXN = 100'000;
    static uint leftConflicts[MAXN][2];
    static uint64_t contribution[MAXN];

    static void insertConflict(const uint v, uint &first, uint &second) {
        const uint isGreaterThanSecond = -(v > second);
        const uint isGreaterThanFirst = -(v > first);
        const uint goesInMiddle = isGreaterThanSecond & ~isGreaterThanFirst;

        second = (first & isGreaterThanFirst) + (v & goesInMiddle) + (second & ~isGreaterThanSecond);
        first = (v & isGreaterThanFirst) + (first & ~isGreaterThanFirst);
    }

public:
    static long long maxSubarrays(const uint n, const vector<vector<int>> &conflictingPairs) {
        for (const auto &pair : conflictingPairs) {
            const uint u = pair[0], v = pair[1];
            const uint maxVal = max(u, v);
            const uint minVal = min(u, v);
            auto &confList = leftConflicts[maxVal - 1];
            insertConflict(minVal, confList[0], confList[1]);
        }

        uint64_t totalValidSubarrays = 0, maxContribution = 0;
        uint leftMost = 0, secondLeft = 0;

        for (uint right = 1; right <= n; ++right) {
            auto &confList = leftConflicts[right - 1];
            insertConflict(confList[0], leftMost, secondLeft);
            insertConflict(confList[1], leftMost, secondLeft);

            totalValidSubarrays += right - leftMost;
            const auto added = contribution[leftMost] += leftMost - secondLeft;
            maxContribution = max(maxContribution, added);

            confList[0] = confList[1] = 0;
        }

        fill_n(contribution, n, 0);
        return totalValidSubarrays + maxContribution;
    }
};

uint Solution::leftConflicts[MAXN][2];
uint64_t Solution::contribution[MAXN];
