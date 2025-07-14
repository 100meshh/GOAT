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
    //reverse ll
    ListNode* reverse(ListNode* head){
        ListNode* curr=head;
        ListNode* prev=NULL, *next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
}
    int getDecimalValue(ListNode* head) {
        ListNode* temp=reverse(head);
        int x,total=0,i=0;
        while(temp!=NULL){
            x=temp->val;
            total=total+pow(2,i)*x;
            i++;
            temp=temp->next;
        }
        return total;
    }
};