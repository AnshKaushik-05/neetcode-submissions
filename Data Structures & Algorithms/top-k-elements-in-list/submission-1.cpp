#include<unordered_map>
#include<queue>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freqMap;
        priority_queue<pair<int,int>>maxHeap;
        for(int x : nums){
            freqMap[x]++;
        }
        for(auto& p : freqMap){
            maxHeap.push({p.second,p.first});
        }

        vector<int>output;
        while(k--){
            pair<int,int>p=maxHeap.top();
            maxHeap.pop();
            output.push_back(p.second);
        }
        return output;
    }
};
