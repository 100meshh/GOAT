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
    ListNode* insertionSortList(ListNode* head) {
        vector<int>arr;
        ListNode* curr=head;
        if(!head)return NULL;
        while(curr){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        //sort arr by insertion sort
        for(int i=1;i<arr.size();i++){
            for(int j=i;j>0;j--){
                if(arr[j]<arr[j-1])swap(arr[j-1],arr[j]);
                else break;
            }
        }
        //put back in ll
        curr=head;
        for(int i=0;i<arr.size();i++){
            curr->val=arr[i];
            curr=curr->next;
        }
        return head;
    }
};