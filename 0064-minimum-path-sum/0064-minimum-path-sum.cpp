class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>dp(n,0);
        dp[0]=grid[0][0];
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0&&j==0){
                    curr[j]=grid[i][j];
                }
                else if(i==0){
                    curr[j]=curr[j-1]+grid[i][j];
                }
                else if(j==0){
                    curr[j]=dp[j]+grid[i][j];
                }
                else{
                    curr[j]=min(dp[j],curr[j-1])+grid[i][j];
                }
            }
            dp=curr;
        }
        return dp[n-1];
    }
};