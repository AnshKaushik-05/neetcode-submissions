class Solution {
public:
    int f(vector<int>&nums,int n){
        vector<int>dp(n+2,-1);
        dp[n+1]=0;
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            dp[i]=max(dp[i+1],nums[i]+dp[i+2]);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        return f(nums,n);
    }
};
