class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();

        int index=0;
        int msf=1;

        //odd length palindrome
        for(int idx=0;idx<n;idx++){
            int i=idx-1,j=idx+1;
            while(i>=0 && j<=n-1){
                if(s[i]!=s[j]){
                    break;
                }
                i--;
                j++;
            }
            i++;
            j--;
            if(msf<j-i+1){
                index=i;
                msf=j-i+1;
            }
        }

        //even-length palindrome
        for(int idx=0;idx<n-1;idx++){
            if(s[idx]==s[idx+1]){
                int i=idx-1,j=idx+2;
                while(i>=0 && j<=n-1){
                    if(s[i]!=s[j]){
                        break;
                    }
                    i--;
                    j++;
                }
                i++;
                j--;
                if(msf<j-i+1){
                    index=i;
                    msf=j-i+1;
                }
            }
        }

        return s.substr(index,msf);
    }
};
