class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>&grid){
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]=0;
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        while(!q.empty()){
            pair<int,int> node=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int r=node.first+row[k];
                int c=node.second+col[k];
                if(r>=0&&r<m&&c>=0&&c<n&&grid[r][c]==1){
                    grid[r][c]=0;
                    q.push({r,c});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                bfs(i,0,grid);
            }
            if(grid[i][n-1]==1){
                bfs(i,n-1,grid);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                bfs(0,i,grid);
            }
            if(grid[m-1][i]==1){
                bfs(m-1,i,grid);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};