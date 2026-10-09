class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>dist(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        int d=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                pair<int,int>node=q.front();
                q.pop();
                int r=node.first,c=node.second;
                for(int k=0;k<4;k++){
                    int nr=r+row[k];
                    int nc=c+col[k];
                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&dist[nr][nc]==-1){
                        dist[nr][nc]=d+1;
                        q.push({nr,nc});
                    }
                }
            }
            d++;
        }
        return dist;
    }
};