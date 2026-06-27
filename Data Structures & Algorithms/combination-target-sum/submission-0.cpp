class Solution {
public:
    vector<int>temp;
    vector<vector<int>>ans;

    void f(vector<int>&nums, int target, int start){
        if(target==0){
            ans.push_back(temp);
            return;
        }


        for(int i=start;i<nums.size();i++){
            if(target-nums[i]<0) continue;
            temp.push_back(nums[i]);
            f(nums,target-nums[i],i);
            temp.pop_back();
        }

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        f(nums,target,0);
        return ans;
    }
};
