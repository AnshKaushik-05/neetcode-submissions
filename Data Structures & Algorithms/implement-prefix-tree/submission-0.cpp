class node{
public:
    char ch;
    map<char,node*>childMap;
    bool terminal;

    node(char ch){
        this->ch=ch;
        terminal=false;
    }
};

class PrefixTree {
public:
    node* root;
    PrefixTree() {
        root=new node('#');
    }
    
    void insert(string word) {
        node* cur=root;
        for(char x : word){
            if(cur->childMap.find(x)==cur->childMap.end()){
                node* n=new node(x);
                cur->childMap[x]=n;
            }
            cur=cur->childMap[x];
        }
        cur->terminal=true;
    }
    
    bool search(string word) {
        node* cur=root;
        for(char x : word){
            if(cur->childMap.find(x)==cur->childMap.end()){
                return false;
            }
            cur=cur->childMap[x];
        }
        if(cur->terminal==true){
            return true;
        }return false;
    }
    
    bool startsWith(string prefix) {
        node* cur=root;
        for(char x : prefix){
            if(cur->childMap.find(x)==cur->childMap.end()){
                return false;
            }
            cur=cur->childMap[x];
        }
        return true;
        
    }
};
