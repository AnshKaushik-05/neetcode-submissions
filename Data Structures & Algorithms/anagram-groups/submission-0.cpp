#include<map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>strMap;
        for(const string& str : strs){
            vector<int>freqMap(26,0);
            for(char ch : str){
                freqMap[ch-'a']++;
            }
            strMap[freqMap].push_back(str);
        }
        vector<vector<string>>ans;
        for(const auto& p : strMap){ //OR pair<vector<int>,vector<string>>p
            ans.push_back(p.second);
        }
        return ans;
    }
};
