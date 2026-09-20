class Solution {
public:
    int maxi(vector<int>&prices,int idx,int already_bought,vector<vector<int>>&dp){
        if(idx==prices.size()){
            return 0;
        }
        int temp=-1e9;
        if(dp[idx][already_bought]!=-1){return dp[idx][already_bought];}
        if(already_bought==1){
            int sold=maxi(prices,idx+1,0,dp)+prices[idx];
            int left=maxi(prices,idx+1,1,dp);
            temp=max(sold,left);
        }
        else{
            int picked=maxi(prices,idx+1,1,dp)-prices[idx];
            int not_picked=maxi(prices,idx+1,0,dp);
            temp=max(picked,not_picked);
        }
        return dp[idx][already_bought]=temp;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return maxi(prices,0,0,dp);
    }
};