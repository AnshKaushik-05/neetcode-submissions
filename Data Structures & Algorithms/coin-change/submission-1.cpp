class Solution {
public:
    int f(vector<int>&coins,int amount){
        vector<int>dp(amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int minNumOfCoins=INT_MAX;
            for(int c : coins){
                if(i-c>=0){
                    int num=dp[i-c];
                    if(num==INT_MAX)continue;
                    minNumOfCoins=min(minNumOfCoins,1+num);
                }
            }
            dp[i]=minNumOfCoins;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int num=f(coins,amount);
        if(num==INT_MAX)return -1;
        return num;
    }
};
