class Solution {
public:
    int f(vector<int>&nums,int n,int s){
        vector<int>dp(n+2,-1);
        dp[n+1]=0;
        dp[n]=0;
        for(int i=n-1;i>=s;i--){
            dp[i]=max(dp[i+1],nums[i]+dp[i+2]);
        }
        return dp[s];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        return max(f(nums,n-1,0),f(nums,n,1));
    }
};
