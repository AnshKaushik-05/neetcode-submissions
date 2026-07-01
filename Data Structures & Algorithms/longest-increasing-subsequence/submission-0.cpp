class Solution {
public:
    int f(vector<int>&nums,int n,int i,int j,vector<vector<int>>&dp){
        //base case
        if(i==n)return 0;
        //look-up
        if(dp[i][j+1]!=-1) return dp[i][j+1];

        //recursive case
        int insert=0;
        if(j==-1 || nums[j]<nums[i]){
            insert=1+f(nums,n,i+1,i,dp);
        }
        int donotInsert=f(nums,n,i+1,j,dp);
        return dp[i][j+1]=max(insert,donotInsert);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(nums,n,0,-1,dp);
    }
};
