#include<unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>valueMap; // <value,index>
        for(int j=0;j<nums.size();j++){
            if(valueMap.find(target-nums[j])!=valueMap.end()){
                return {valueMap[target-nums[j]],j};
            }
            valueMap[nums[j]]=j;
        }
    
    }
};
