class Solution {
public:
    int unique(int row,int col,vector<vector<int>>&dp){
        if(row<0||col<0){return 0;}
        if(row==0&&col==0){return 1;}
        if(dp[row][col]!=-1){return dp[row][col];}
        int row_minus=unique(row-1,col,dp);
        int col_minus=unique(row,col-1,dp);
        return dp[row][col]=row_minus+col_minus;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return unique(m-1,n-1,dp);
    }
};