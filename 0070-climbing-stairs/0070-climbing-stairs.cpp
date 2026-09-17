class Solution {
public:
    int no_of_ways(int n,vector<int>& dp){
        if(n==0){
            return 1;
        }
        if(n==1){return 1;}
        if(dp[n]!=-1){return dp[n];}
        dp[n]=no_of_ways(n-1,dp)+no_of_ways(n-2,dp);
        return no_of_ways(n-1,dp)+no_of_ways(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans=no_of_ways(n,dp);
        return ans;
    }
};