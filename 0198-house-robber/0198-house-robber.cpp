class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        if(nums.size()==1){return nums[0];}
        vector<int>dp(nums.size(),-1);
        dp[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            int selected=nums[i];
            if(i>=2){
                selected=nums[i]+dp[i-2];
            }
            int not_selected=dp[i-1];
            dp[i]=max(selected,not_selected);
        }
        return max(dp[nums.size()-1],dp[nums.size()-2]);
    }
};