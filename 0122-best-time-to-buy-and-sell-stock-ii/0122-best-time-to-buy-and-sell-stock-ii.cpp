class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>dp(2,-1);
        dp[0]=0;
        dp[1]=-prices[0];
        for(int i=1;i<prices.size();i++){
                vector<int> temp(2,0);
                temp[0]=max(dp[0],dp[1]+prices[i]);
                temp[1]=max(dp[1],dp[0]-prices[i]);
                dp=temp;
        }
        return max(dp[0],dp[1]);
    }
};