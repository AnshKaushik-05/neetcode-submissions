class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>tfreqMap;
        int tCnt=0;
        for(char ch : t){
            tfreqMap[ch]++;
            if(tfreqMap[ch]==1){
                tCnt++;
            }
        }

        int i=0,j=0;
        int n=s.size();
        int minLen=INT_MAX;
        int idx=0;
        while(j<n){
            tfreqMap[s[j]]--;
            if(tfreqMap[s[j]]==0){
                tCnt--;
            }

            if(tCnt==0){
                //record the window length
                if(minLen>j-i+1){
                    minLen=j-i+1;
                    idx=i;
                }

                //shrink the window
                while(tCnt==0){
                    if(minLen>j-i+1){
                        minLen=j-i+1;
                        idx=i;
                    }
                    tfreqMap[s[i]]++;
                    if(tfreqMap[s[i]]>0){
                        tCnt++;
                    }
                    i++; 
                }
            }
            j++;
        }
        string str=(minLen==INT_MAX)?"":s.substr(idx,minLen);
        return str;
    }
};
