class Solution {
public:
    int f(vector<int>&nums,int n,int i,vector<int>&dp){
        //base case
        if(i==n || i==n+1)return 0;
        //look-up
        if(dp[i]!=-1)return dp[i];

        //recursve case
        int dontRobProfit=f(nums,n,i+1,dp);
        int robProfit=nums[i]+f(nums,n,i+2,dp);
        return dp[i]=max(dontRobProfit,robProfit);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(nums,n,0,dp);
    }
};
