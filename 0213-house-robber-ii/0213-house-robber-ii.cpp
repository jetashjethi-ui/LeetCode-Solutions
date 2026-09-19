class Solution {
public:
    int maxi(vector<int>& nums) {
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
        return dp[nums.size()-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==0){return 0;}
        if(nums.size()==1){return nums[0];}
        vector<int>arr1;
        vector<int>arr2;
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                arr1.push_back(nums[i]);
            }
            if(i!=nums.size()-1){
                arr2.push_back(nums[i]);
            }
        }
        int a=maxi(arr1);
        int b=maxi(arr2);
        return max(a,b);
    }
};