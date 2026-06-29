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
        if(n==1) return nums[0];
        
        vector<int> dp(n, -1);
        int ans1 = f(nums, n - 1, 0, dp);
        fill(dp.begin(), dp.end(), -1);
        int ans2 = f(nums, n, 1, dp);
        return max(ans1, ans2);
    }
};
