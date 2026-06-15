class Solution {
public:
    bool isPalindrome(string s) {
        int i=0 , j=s.size()-1;
        while(i<j){ //not i!=j
            bool isI=isalnum(s[i]);
            bool isJ=isalnum(s[j]);
            if(isI && isJ){
                if(tolower(s[i])!=tolower(s[j])){
                    return false;
                }else{
                    i++;
                    j--;
                }
            }
            else if(!isI && isJ){
                i++;
            }
            else if(isI && !isJ){
                j--;
            }
            else{ //!isI && !isJ
                i++;
                j--;
            }
        }
        return true;
    }
};
