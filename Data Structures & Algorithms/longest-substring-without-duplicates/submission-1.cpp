#include<unordered_set>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>wnd;
        int maxLenSoFar=0;
        int len=0;
        int n=s.size();
        int i=0,j=0;
        while(j<n){
            if(wnd.find(s[j])==wnd.end()){
                wnd.insert(s[j]);
                len++;
            }
            else{
                maxLenSoFar=max(maxLenSoFar,len);
                while(wnd.find(s[j])!=wnd.end()){
                    wnd.erase(s[i]);
                    i++;
                }
                wnd.insert(s[j]);
                len=wnd.size();
            }
            j++;
        }
        maxLenSoFar=max(maxLenSoFar,len);
        return maxLenSoFar;
    }
};
