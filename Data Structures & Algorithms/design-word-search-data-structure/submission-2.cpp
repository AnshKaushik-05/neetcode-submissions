class node{
public:
    char ch;
    bool terminal;
    unordered_map<char,node*>childMap;

    node(char ch){
        this->ch=ch;
        this->terminal=false;
    }
};

class WordDictionary {
    node* root;

    bool f(const string&word,int i,node* cur){
        if(i==word.size()){
            return cur->terminal;
        }

        char ch=word[i];
        if(ch=='.'){
            for(auto& p : cur->childMap){
                if(f(word,i+1,p.second))return true;
            }
            return false;
        }

        if(cur->childMap.find(ch)==cur->childMap.end()){
            return false;
        }else{
            return f(word,i+1,cur->childMap[ch]);
        }

    }
    
public:
    WordDictionary() {
        this->root=new node('#');
    }
    
    void addWord(string word) {
        node* cur=root;
        for(char ch : word){
            if(cur->childMap.find(ch)==cur->childMap.end()){
                node* n=new node(ch);
                cur->childMap[ch]=n;
            }
            cur=cur->childMap[ch];
        }
        cur->terminal=true;
    }
    
    
    bool search(string word) {
        return f(word,0,root);
    }
};
