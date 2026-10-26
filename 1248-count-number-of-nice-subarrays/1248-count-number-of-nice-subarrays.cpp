class Solution {
public:
    int at_most_k(vector<int>&nums,int t){
        int low=0,high=0;
        int count_odd=0;
        int ans=0;
        while(high<nums.size()){
            if(nums[high]%2!=0){
                count_odd++;
            }
            while(count_odd>t){
                if(nums[low]%2==0){
                    low++;
                }
                else{
                    count_odd--;
                    low++;
                    break;
                }
            }
            ans+=(high-low+1);
            high++;
        }
        return ans;

    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return at_most_k(nums,k)-at_most_k(nums,k-1);
    }
};