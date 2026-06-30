class Solution {
public:
    int f(string&s,int n){
        int dp_i_plus_1=1,dp_i_plus_2=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]-'0'==0){
                int c=0;
                dp_i_plus_2=dp_i_plus_1;
                dp_i_plus_1=c;
            }
            else{
                int usePair=0;
                if(i<n-1){
                    int num=(s[i]-'0')*10+(s[i+1]-'0');
                    if(num<=26)usePair=dp_i_plus_2;
                } 
                int noPair=dp_i_plus_1;
                int c=noPair+usePair;
                dp_i_plus_2=dp_i_plus_1;
                dp_i_plus_1=c;
            }
        }
        return dp_i_plus_1;
    }

    int numDecodings(string s) {
        int n=s.size();
        return f(s,n);
    }
};
