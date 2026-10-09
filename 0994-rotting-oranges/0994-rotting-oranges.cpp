class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh==0) return 0;
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        int ans=0;
        while(!q.empty()&&fresh>0){
            int sz=q.size();
            ans++;
            for(int i=0;i<sz;i++){
                pair<int,int> node=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int r=node.first+row[k];
                    int c=node.second+col[k];
                    if(r>=0&&r<m&&c>=0&&c<n&&grid[r][c]==1){
                        grid[r][c]=2;
                        fresh--;
                        q.push({r,c});
                    }
                }
            }
        }
        return fresh==0?ans:-1;
    }
};