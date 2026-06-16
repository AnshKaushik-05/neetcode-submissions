class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        for(char ch : s){
            if(ch=='(' or ch=='[' or ch=='{'){
                stk.push(ch);
            }
            else{
                if(stk.empty()) return false;

                char ob=stk.top();
                if(ch==')' and ob=='(') stk.pop();
                else if(ch=='}' and ob=='{') stk.pop();
                else if(ch==']' and ob=='[') stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};
