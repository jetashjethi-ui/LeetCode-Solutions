class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            vector<vector<int>>ans;
            for(int i=0;i<nums.size();i++){
                 if(i>0&&nums[i]==nums[i-1]){continue;}
                 int mid=i+1,end=nums.size()-1;
                 while(mid<end){
                    int sum=nums[i]+nums[mid]+nums[end];
                    if(sum>0){
                        end--;
                    }
                    else if(sum<0){
                        mid++;
                    }
                    else{
                        ans.push_back({nums[i],nums[mid],nums[end]});
                        mid++;
                        end--;
                        while(mid<end&&nums[mid]==nums[mid-1]){mid++;}
                        while(mid<end&&nums[end]==nums[end+1]){end--;}
                    }
                 }
            }
            return ans;
        }
    };