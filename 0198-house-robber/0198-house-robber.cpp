class Solution {
public:
    int maxi(vector<int>&nums,int idx,vector<int>&dp){
        if(idx<0){return 0;}
        if(idx==0){return nums[0];}
        if(dp[idx]!=-1){return dp[idx];}
        int selected=nums[idx]+maxi(nums,idx-2,dp);
        int not_selected=maxi(nums,idx-1,dp);
        return dp[idx]=max(selected,not_selected);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return maxi(nums,nums.size()-1,dp);
    }
};