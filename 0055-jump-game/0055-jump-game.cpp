class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<=1){return true;}
        int jumps,i=0,j=1;
        while(j<nums.size()&&i<nums.size()){
            jumps=nums[i];
            if(jumps<=0){return false;}
            if(nums[i]-(j-i)<=nums[j]){
                i=j;
            }
            j++;
        }
        return true;
    }
};