class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>&board){
        int m=board.size(),n=board[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        board[i][j]='T';
        int row[]={0,0,1,-1};
        int col[]={1,-1,0,0};
        while(!q.empty()){
            pair<int,int> node=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int r=node.first+row[k];
                int c=node.second+col[k];
                if(r>=0&&r<m&&c>=0&&c<n&&board[r][c]=='O'){
                    board[r][c]='T';
                    q.push({r,c});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                bfs(i,0,board);
            }
            if(board[i][n-1]=='O'){
                bfs(i,n-1,board);
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                bfs(0,i,board);
            }
            if(board[m-1][i]=='O'){
                bfs(m-1,i,board);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }
    }
};