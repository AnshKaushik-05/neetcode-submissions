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

class cmp{
public:
    bool operator()(ListNode* a,ListNode* b){
        if(a->val<b->val){
            return false;
        }
        return true;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        priority_queue<ListNode*,vector<ListNode*>,cmp>minHeap;
        for(int i=0;i<n;i++){
            if(lists[i]!=NULL)
                minHeap.push(lists[i]);
        }

        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;

        while(!minHeap.empty()){
            ListNode* cur=minHeap.top();
            minHeap.pop();
            if(cur->next!=NULL) minHeap.push(cur->next);
            temp->next=cur;
            temp=temp->next;
        }
        return dummy->next;
    }
};
