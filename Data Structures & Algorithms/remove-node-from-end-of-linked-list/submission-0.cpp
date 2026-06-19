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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        temp=head;
        ListNode* prev;
        int k=len-n;
        if(k==0){
            prev=head;
            head=head->next;
            delete prev;
            return head;
        }
        while(k--){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
        return head;
    }
};
