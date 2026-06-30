class Solution {
public:
    int f(string&s,int n,int i,vector<int>&dp){
        //base case
        if(i==s.size())return 1;
        if(s[i]-'0'==0)return 0;
        //look-up
        if(dp[i]!=-1)return dp[i];

        //recurisve case
        int usePair=0;
        if(i<n-1){
            int num=(s[i]-'0')*10+(s[i+1]-'0');
            if(num<=26)usePair=f(s,n,i+2,dp);
        } 
        int noPair=f(s,n,i+1,dp);
        return dp[i]=usePair+noPair;
    }

    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return f(s,n,0,dp);
    }
};
