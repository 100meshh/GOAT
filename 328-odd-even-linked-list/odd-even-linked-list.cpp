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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* l1=new ListNode(0);
        ListNode* l2=new ListNode(0);
        ListNode* temp_l1=l1;
        ListNode* temp_l2=l2;

        ListNode* curr=head;


        ListNode* odd=head;
        ListNode* even=head->next;
        while(odd && even){
            temp_l1->next=odd;
            temp_l1=temp_l1->next;

            temp_l2->next=even;
            temp_l2=temp_l2->next;

            odd=even->next;
            if(odd)even=odd->next;
            else break;
        }
        if(odd!=NULL){
            temp_l1->next=odd;
            temp_l1=temp_l1->next;
        }
        temp_l2->next = nullptr; // to remove pointer of even (4)->(5) imppp
        l1=l1->next;
        l2=l2->next;
        temp_l1->next=l2;
        return l1;
    }
};