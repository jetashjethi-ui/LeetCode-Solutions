class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int pos=0,neg=0;
        vector<int>ans;
        while(pos<n&&neg<n){
            while(nums[pos]<0){
                pos++;
            }
            while(nums[neg]>0){
                neg++;
            }
            ans.push_back(nums[pos]);
            ans.push_back(nums[neg]);
            pos++;
            neg++;
        }
        return ans;
    }
};