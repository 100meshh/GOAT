class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;  // stores all unique OR values
        unordered_set<int> prev;    // OR values ending at previous index
        
        for (int num : arr) {
            unordered_set<int> cur;
            cur.insert(num); // start a new subarray at current index
            
            for (int x : prev) {
                cur.insert(x | num);
            }

            for (int x : cur) {
                result.insert(x);
            }

            prev = cur; // update for next iteration
        }

        return result.size();
    }
};
