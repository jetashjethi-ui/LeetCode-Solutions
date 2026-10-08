#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){return 0;}
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int count=0;
        int dRow[]={-1,1,0,0};
        int dCol[]={0,0,-1,1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]||grid[i][j]=='0'){continue;}
                else{
                    count++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    visited[i][j]=true;
                    while(!q.empty()){
                        pair<int,int>root=q.front();
                        q.pop();
                        int r=root.first;
                        int c=root.second;
                        for(int k=0;k<4;k++){
                            int nr=r+dRow[k];
                            int nc=c+dCol[k];
                            if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]=='1'&&!visited[nr][nc]){
                                visited[nr][nc]=true;
                                q.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};