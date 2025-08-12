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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0);
        ListNode* tail=head;
        ListNode* curr1=l1;
        ListNode* curr2=l2;
        int sum=0,carry=0;

        while(curr1 && curr2){
            sum=curr1->val+curr2->val+carry;
            tail->next=new ListNode(sum%10);
            curr1=curr1->next;
            curr2=curr2->next;
            tail=tail->next;
            carry=sum/10;
        }
        while(curr1){
            sum=curr1->val+carry;
            tail->next=new ListNode(sum%10);
            curr1=curr1->next;
            tail=tail->next;
            carry=sum/10;
        }
        while(curr2){
            sum=curr2->val+carry;
            tail->next=new ListNode(sum%10);
            curr2=curr2->next;
            tail=tail->next;
            carry=sum/10;
        }
        while(curr2){
            sum=curr2->val+carry;
            tail->next=new ListNode(sum%10);
            curr2=curr2->next;
            tail=tail->next;
            carry=sum/10;
        }
        while(carry){
            tail->next =new ListNode(carry%10);
            tail=tail->next;
            carry/=10;
        }
        tail=head;
        head=head->next;
        delete tail;
        return head;
    }
};