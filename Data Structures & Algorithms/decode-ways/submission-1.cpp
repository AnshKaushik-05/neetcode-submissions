class Solution {
public:
    int f(string&s,int n){
        vector<int>dp(n+1,-1);
        dp[n]=1;

        for(int i=n-1;i>=0;i--){
            if(s[i]-'0'==0){
                dp[i]=0;
            }
            else{
                int usePair=0;
                if(i<n-1){
                    int num=(s[i]-'0')*10+(s[i+1]-'0');
                    if(num<=26)usePair=dp[i+2];
                } 
                int noPair=dp[i+1];
                dp[i]=usePair+noPair;
            }
        }
        return dp[0];
    }

    int numDecodings(string s) {
        int n=s.size();
        return f(s,n);
    }
};
