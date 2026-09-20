class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int>dp(n,0);
        dp[0]=1;
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    curr[j]=0;
                }
                else if(j-1>=0){
                    curr[j]=dp[j]+curr[j-1];
                }
                else{
                    curr[j]=dp[j];
                }
            }
            dp=curr;
        }
        return dp[n-1];
    }
};