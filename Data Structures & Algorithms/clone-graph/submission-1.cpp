/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* orgNode,Node* newNode,vector<Node*>&addr){
        // vis[orgNode->val]=true;
        addr[orgNode->val]=newNode; 

        for(Node* ngb : orgNode->neighbors){
            if(addr[ngb->val]==NULL){  //the ngb has not been visited yet
                Node* temp=new Node(ngb->val);
                newNode->neighbors.push_back(temp);
                dfs(ngb,temp,addr);
            }
            else{
                newNode->neighbors.push_back(addr[ngb->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr)return nullptr;

        // vector<bool>vis(101,false);
        vector<Node*>addr(101,NULL);

        Node* newStart=new Node(node->val);
        dfs(node,newStart,addr);
        return newStart;
    }
};
