class Solution {
public:
    bool f(const string& s,const vector<string>&wordDict,int n,int i,vector<int>&dp){
        //base case
        if(i==n)return true;
        //look-up
        if(dp[i]!=-1)return dp[i];
        
        //recursive case
        for(const string& str : wordDict){
            int idx=i;
            int len=str.size();
            int j=0;
            while(j<len && idx<n){
                if(str[j]!=s[idx])break;
                idx++;
                j++;
            }
            if(j==len){
                if(f(s,wordDict,n,i+len,dp))return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return f(s,wordDict,n,0,dp);
    }
};
