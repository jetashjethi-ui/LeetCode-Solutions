class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>hash(nums.begin(),nums.end());
        int maxi=0;
        for(int i:hash){
            if(hash.find(i-1)==hash.end()){
                int count=1;
                int x=i;
                while(hash.find(x+1)!=hash.end()){
                    x=x+1;
                    count++;
                }
                maxi=max(maxi,count);
            }
        }
        return maxi;
    }
};