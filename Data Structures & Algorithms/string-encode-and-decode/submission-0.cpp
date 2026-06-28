class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(string s : strs){
            int len=s.size();
            encoded+=to_string(len)+'#'+s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int n=s.size();
        int i=0;
        while(i<n){
            int num=0;
            while(s[i]!='#'){
                num=num*10+(s[i]-'0');
                i++;
            }
            i++;
            string temp="";
            while(num--){
                temp+=s[i];
                i++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
