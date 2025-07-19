class Solution {
public:
    int squareRoot(int x) {
        int low = 0, high = x, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((long long)mid * mid == x) return mid;
            if ((long long)mid * mid < x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for (int g : gifts) {
            pq.push(g);
        }

        while (k-- && !pq.empty()) {
            int maxGift = pq.top();
            pq.pop();
            int updated = squareRoot(maxGift);
            pq.push(updated);
        }

        long long total = 0;
        while (!pq.empty()) {
            total += pq.top();
            pq.pop();
        }

        return total;
    }
};
