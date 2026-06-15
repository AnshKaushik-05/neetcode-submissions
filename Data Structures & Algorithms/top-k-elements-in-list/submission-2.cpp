#include<unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>freqMap;

        for(int x : nums){
            freqMap[x]++;
        }
        
        vector<vector<int>>bucket(n+1);
        for(auto& p : freqMap){
            bucket[p.second].push_back(p.first);
        }

        vector<int>ans;
        for(int i=n;i>0;i--){
            for(int x : bucket[i]){
                if(k==0) return ans;
                ans.push_back(x);
                k--;
            }
        }
        return ans;
    }
};
