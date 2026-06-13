class Solution {
public:
    void dfs(const vector<vector<char>>& grid,int i,int j,vector<vector<bool>>&vis,int m,int n){
        vis[i][j]=true;

        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y]=='1' && vis[x][y]!=true){
                dfs(grid,x,y,vis,m,n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int numOfIslands=0;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    dfs(grid,i,j,vis,m,n);
                    numOfIslands++;
                }
            }
        }
        return numOfIslands;
    }
};
