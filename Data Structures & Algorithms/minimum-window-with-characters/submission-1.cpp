class Solution {
public:
    bool compareMaps(unordered_map<int,int>&sfreqMap, unordered_map<int,int>&tfreqMap){
        for(auto& p : tfreqMap){
            int freqInT=p.second;
            if(freqInT>sfreqMap[p.first])return false;
        }
        return true;
    }

    string minWindow(string s, string t){
        int n=s.size();
        unordered_map<int,int>sfreqMap;
        unordered_map<int,int>tfreqMap;
        int tCnt=0;
        for(char ch : t){
            tfreqMap[ch]++;
            if(tfreqMap[ch]==1){
                tCnt++;
            }
        }

        int i=0,j=0;
        int idx;
        int minSoFar=INT_MAX;
        while(j<n){
            sfreqMap[s[j]]++;
            
            while(compareMaps(sfreqMap,tfreqMap)){
                if(j-i+1<minSoFar){
                    idx=i;
                    minSoFar=j-i+1;
                }
                sfreqMap[s[i]]--;
                i++;
            }
            j++;
        }

        string str=(minSoFar==INT_MAX)?"":s.substr(idx,minSoFar);
        return str;
    }
};
