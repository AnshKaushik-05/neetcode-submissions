class Solution {
public:
    bool f(const string& s,const vector<string>&wordDict,int n){
        //vector<int>dp(n+1,-1);
        vector<int>dp(n+1,false);
        dp[n]=true;
        
        for(int i=n-1;i>=0;i--){
            for(const string& str : wordDict){
                int idx=i;
                int len=str.size();
                int j=0;
                while(j<len && idx<n){
                    if(str[j]!=s[idx])break;
                    idx++;
                    j++;
                }
                if(j==len && dp[i+len]){
                    dp[i]=true;
                    break;
                }
            }
            //if(dp[i]==-1) dp[i]=false;
        }   
        return dp[0]; 
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        return f(s,wordDict,n);
    }
};
