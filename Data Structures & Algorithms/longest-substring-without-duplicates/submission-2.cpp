#include<unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>wnd;
        int maxLenSoFar=0;
        int len=0;
        int n=s.size();
        int i=0,j=0;
        while(j<n){
            if(wnd.find(s[j])==wnd.end()){
                wnd[s[j]]=j;
                len++;
            }else{
                maxLenSoFar=max(maxLenSoFar,len);
                i=max(wnd[s[j]]+1,i);
                wnd[s[j]]=j;
                len=j-i+1;
            }
            j++;
        }
        maxLenSoFar=max(maxLenSoFar,len);
        return maxLenSoFar;
    }
};
