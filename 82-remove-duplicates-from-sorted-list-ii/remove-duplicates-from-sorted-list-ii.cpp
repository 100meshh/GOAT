/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> arr;
        vector<int> temp;
        ListNode* curr = head;

        while (curr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }

        unordered_map<int,int> freq;
        for (int x : arr) {
            freq[x]++;
        }

        for (int x : arr) {              
            if (freq[x] == 1) temp.push_back(x);
        }

        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        for (int i = 0; i < temp.size(); i++) {
            tail->next = new ListNode(temp[i]);
            tail = tail->next; 
        }

        return dummy->next;
    }
};
