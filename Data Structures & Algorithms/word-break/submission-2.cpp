class node{
public:
    char ch;
    bool terminal;
    map<char,node*>childMap;

    node(char ch){
        this->ch=ch;
        this->terminal=false;
    } 
};

class trie{
public:
    node* root;
    trie(){
        root=new node('#');
    }

    //time : O(len of str.log26) ~ O(len of str)
    void insert(string str){
        node* cur=root;
        for(char ch : str){
            if(cur->childMap.find(ch)==cur->childMap.end()){
                //child with value 'ch' doesn't exist
                node* n=new node(ch);
                cur->childMap[ch]=n; //making new node the child node of the cur node
            }
            cur=cur->childMap[ch];
        }
        cur->terminal=true;
    }
};

class Solution {
public:
    bool f(const string& s,const vector<string>&wordDict,int n){
        trie t;
        for(const string& str : wordDict){
            t.insert(str);
        }

        vector<int>dp(n+1,false);
        dp[n]=true;
        
        for(int i=n-1;i>=0;i--){
            node* cur=t.root;
            int idx=i;
            while(idx<n){
                char ch=s[idx];
                if(cur->childMap.find(ch)!=cur->childMap.end()){
                    cur=cur->childMap[ch];
                    idx++;
                    if(cur->terminal && dp[idx]){
                        dp[i]=true;
                        break;
                    }
                }else{
                    break;
                }
            }
        }   
        return dp[0]; 
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        return f(s,wordDict,n);
    }
};
