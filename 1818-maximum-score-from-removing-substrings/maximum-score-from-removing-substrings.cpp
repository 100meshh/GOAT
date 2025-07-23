class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Helper to remove target pairs and count gain
        auto removePair = [](string &s, char first, char second, int value) -> pair<string, int> {
            string stack;
            int score = 0;
            for (char c : s) {
                if (!stack.empty() && stack.back() == first && c == second) {
                    stack.pop_back();
                    score += value;
                } else {
                    stack.push_back(c);
                }
            }
            return {stack, score};
        };

        int total = 0;
        if (x >= y) {
            auto [temp, score1] = removePair(s, 'a', 'b', x);  // remove "ab"
            auto [finalStr, score2] = removePair(temp, 'b', 'a', y);  // remove "ba"
            total = score1 + score2;
        } else {
            auto [temp, score1] = removePair(s, 'b', 'a', y);  // remove "ba"
            auto [finalStr, score2] = removePair(temp, 'a', 'b', x);  // remove "ab"
            total = score1 + score2;
        }

        return total;
    }
};
