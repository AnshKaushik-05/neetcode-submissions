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
        vector<ListNode*>listVector;
        ListNode* temp=head;
        while(temp!=NULL){
            listVector.push_back(temp);
            temp=temp->next;
        }

        int i=0,j=listVector.size()-1;
        while(i<j){
            listVector[i]->next=listVector[j];
            i++;
            listVector[j]->next=listVector[i];
            j--;
        }
        listVector[i]->next=NULL;
    }
};
