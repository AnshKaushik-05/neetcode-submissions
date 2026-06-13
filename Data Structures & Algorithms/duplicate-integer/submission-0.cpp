#include<map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int>freqMap;
        for(int x : nums){
            freqMap[x]++;
            if(freqMap[x]>1) return true;
        }
        return false;
    }
};