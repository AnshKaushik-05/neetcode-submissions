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

        //Step 1: Find the middle
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        //Step 2: Reverse the second half
        ListNode* prev=NULL;
        ListNode* cur=slow->next;
        while(cur!=NULL){
            ListNode* temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }

        //Step 3: Disconnect the halves
        slow->next=NULL;

        //Step 4: Merge alternately
        slow=head;
        while(prev!=NULL){
            ListNode* temp1=slow->next;
            slow->next=prev;
            slow=temp1;

            ListNode* temp2=prev->next;
            prev->next=slow;
            prev=temp2;
        }
    }
};
