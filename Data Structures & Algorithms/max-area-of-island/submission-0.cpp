class Solution {
public:
    int dfs(const vector<vector<int>>& grid,int i,int j,vector<vector<bool>>&vis,int m,int n){
        vis[i][j]=true;
        int area=1; //area of this node , the recursive function returns the area of the connected nodes

        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1 && !vis[x][y]){ //we only visit land nodes
                area+=dfs(grid,x,y,vis,m,n);
            } 
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxArea=0;

        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    maxArea=max(maxArea,dfs(grid,i,j,vis,m,n));
                }
            }
        }
        return maxArea;
    }
};
