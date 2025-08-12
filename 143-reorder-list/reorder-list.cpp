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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        vector<int> arr;
        ListNode* curr = head;
        while (curr) {
            arr.push_back(curr->val);
            curr = curr->next;
        }
        //2ptr
        vector<int> temp;
        int start = 0, end = arr.size() - 1;
        while (start <= end) {
            if (start == end) {
                temp.push_back(arr[start]);
            } else {
                temp.push_back(arr[start]);
                temp.push_back(arr[end]);
            }
            start++;
            end--;
        }


//arr to ll
    curr = head;
    
    // for (int val : temp) {
    //     curr->val = val;
    //     curr = curr->next;
    // }

    for (int i = 0; i < temp.size(); i++) {
    curr->val = temp[i];
    curr = curr->next;
    }

    }
};