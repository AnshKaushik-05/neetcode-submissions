class Solution {
public:
    //f(i,j,k) : returns whether we can form the word[k...end] starting from index(i,j)
    bool f(vector<vector<char>>& board, string&word,int m,int n,int slen,int i,int j,int k){
        if(k==slen) return true;
        if(i<0 || i>=m || j<0 || j>=n) return false;
        if(board[i][j]=='#' || board[i][j]!=word[k]) return false;

        char temp=board[i][j];
        board[i][j]='#';
        bool w=f(board,word,m,n,slen,i,j+1,k+1);
        bool x=f(board,word,m,n,slen,i,j-1,k+1);
        bool y=f(board,word,m,n,slen,i-1,j,k+1);
        bool z=f(board,word,m,n,slen,i+1,j,k+1);
        board[i][j]=temp;
        return w||x||y||z;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int slen=word.size();
        bool flag=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    flag=f(board,word,m,n,slen,i,j,0);
                    if(flag) return true;
                }
            }
        }
        return false;
    }
};
