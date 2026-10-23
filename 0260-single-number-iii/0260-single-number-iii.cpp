class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x=0;
        for(long long i=0;i<nums.size();i++){
            x^=nums[i];
        }
        x=(x&(x-1))^x;
        long long X1=0,X2=0;
        for(long long i=0;i<nums.size();i++){
            if((x&nums[i])==0){
                X1^=nums[i];
            }
            else{
                X2^=nums[i];
            }
        }
        vector<int> ans;
        ans.push_back(X1);
        ans.push_back(X2);
        return ans;

    }
};