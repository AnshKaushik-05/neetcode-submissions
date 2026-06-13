#include<climits>
#include<queue>
#include<utility>
class Solution {
public:
    void bfs(vector<vector<int>>& grid,vector<vector<bool>>&vis,int m,int n){
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }
        
        //no need to maintain a distMap, as we have to modify grid in-place and grid[treasure chest]==0

        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};
        while(!q.empty()){
            pair<int,int>p=q.front();
            int i=p.first;
            int j=p.second;
            q.pop();

            for(int k=0;k<4;k++){
                int x=i+dx[k];
                int y=j+dy[k];
                if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==2147483647 && !vis[x][y]){
                    vis[x][y]=true;
                    grid[x][y]=grid[i][j]+1;
                    q.push({x,y});
                }
            }
            
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //the problem translates to sssp ,where each group of INF forms an island/land-blocks 
        //which could be traversed , we assume grid[i][j]==INF is a block within the group of 
        //land cells which holds a treasure chest , treasure chest acts as the source 
        //and there are multiple chest so it becomes a multi-source shortest path problem
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        bfs(grid,vis,m,n);
    }
};
