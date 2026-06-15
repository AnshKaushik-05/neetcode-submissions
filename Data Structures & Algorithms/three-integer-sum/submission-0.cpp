class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>output;
        int n=nums.size();

        sort(nums.begin(),nums.end());
        for(int k=0;k<n;k++){
            if(k>0 && nums[k]==nums[k-1]) continue;
            if(nums[k]>0)break;
            int targetSum=-nums[k]; //long long targetSum = -1LL * nums[k];
            int i=k+1,j=n-1;
            while(i<j){
                if(nums[i]+nums[j]==targetSum){
                    output.push_back({nums[k],nums[i],nums[j]});
                    i++;
                    j--;
                    while(i<n && nums[i]==nums[i-1]) i++;
                    while(j>=0 && nums[j]==nums[j+1]) j--;
                }
                else if(nums[i]+nums[j]<targetSum){
                    i++;
                }
                else{ //nums[i]+nums[j]>targetSum
                    j--;
                }
            }
        }
        return output;
    }
};
