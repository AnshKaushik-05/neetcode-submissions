class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqMap[26]={0};
        for(char ch : s){
            freqMap[ch-'a']++;
        }
        for(char ch : t){
            freqMap[ch-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freqMap[i]!=0){
                return false;
            }
        }
        return true;
    }
};
