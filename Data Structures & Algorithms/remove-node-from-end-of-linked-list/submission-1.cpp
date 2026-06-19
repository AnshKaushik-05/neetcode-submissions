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
        ListNode* ptr1=new ListNode();
        ptr1->next=head;
        ListNode* ptr2=new ListNode();
        ptr2->next=head;
        while(n--){
            ptr1=ptr1->next;
        }
        while(ptr1->next!=NULL){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        ListNode* temp;
        temp=ptr2->next;
        ptr2->next=temp->next;
        if(temp==head){
            delete temp;
            return ptr2->next;
        }
        delete temp;
        return head;
    }
};
