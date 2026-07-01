class Solution {
public:
    int f(vector<int>&nums){
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int j=0;j<=n;j++){
            dp[n][j]=0;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=-1;j<i;j++){
                int insert=0;
                if(j==-1 || nums[j]<nums[i]){
                    insert=1+dp[i+1][i+1];
                }
                int donotInsert=dp[i+1][j+1];
                dp[i][j+1]=max(insert,donotInsert);
            }
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        return f(nums);
    }
};
