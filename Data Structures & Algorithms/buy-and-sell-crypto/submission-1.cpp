class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPriceSoFar=prices[0];
        int maxProfitSoFar=0;
        for(int x : prices){
            maxProfitSoFar=max(maxProfitSoFar,x-minPriceSoFar);
            minPriceSoFar=min(minPriceSoFar,x);
        }
        return maxProfitSoFar;
    }
};
