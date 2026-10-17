class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int summ=0,maxi=nums[0];
        for(int i=0;i<nums.size();i++){
            summ+=nums[i];
            maxi=max(maxi,nums[i]);
        }
        int low=maxi,high=summ;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int temp=0;
            int t=1;
            for(int i=0;i<nums.size();i++){
                if(temp+nums[i]<=mid){
                    temp+=nums[i];
                }
                else{
                    t++;
                    temp=nums[i];
                }
            }
            if(t<=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};