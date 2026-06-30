class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();

        //odd length palindrome
        int numOddLen=0;
        for(int idx=0;idx<n;idx++){
            numOddLen++;
            int i=idx-1,j=idx+1;
            while(i>=0 && j<=n-1){
                if(s[i]!=s[j]){
                    break;
                }
                numOddLen++;
                i--;
                j++;
            }
        }

        //even-length palindrome
        int numEvenLen=0;
        for(int idx=0;idx<n-1;idx++){
            if(s[idx]==s[idx+1]){
                numEvenLen++;
                int i=idx-1,j=idx+2;
                while(i>=0 && j<=n-1){
                    if(s[i]!=s[j]){
                        break;
                    }
                    numEvenLen++;
                    i--;
                    j++;
                }
            }
        }

        return numOddLen+numEvenLen;
    }
};
