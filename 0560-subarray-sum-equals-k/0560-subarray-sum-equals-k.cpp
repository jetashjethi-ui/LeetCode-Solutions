class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>h;
        int prev=0;
        int count=0;
        h[0]=1;
        for(int i=0;i<nums.size();i++){
            prev+=nums[i];
            int target=prev-k;
            if(h.find(target)!=h.end()){
                count+=h[target];
            }
            h[prev]++;
        }
        return count;
    }
};