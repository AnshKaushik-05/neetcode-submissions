class Solution {
public:
    int f(vector<int>&coins,int amount,vector<int>&dp){
        //bace case
        if(amount==0)return 0;
        //look up
        if(dp[amount]!=-1)return dp[amount];

        //recursive case
        int minNumOfCoins=INT_MAX;
        for(int c : coins){
            if(amount-c>=0){
                int num=f(coins,amount-c,dp);
                if(num==INT_MAX)continue;
                minNumOfCoins=min(minNumOfCoins,1+num);
            }
        }
        return dp[amount]=minNumOfCoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int num=f(coins,amount,dp);
        if(num==INT_MAX)return -1;
        return num;
    }
};
