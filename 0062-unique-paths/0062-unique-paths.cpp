class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n,0); 
        dp[0]=1;
        for(int i=0;i<m;i++){
            vector<int> curr(n);
            for(int j=0;j<n;j++){
                if(j-1>=0){
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