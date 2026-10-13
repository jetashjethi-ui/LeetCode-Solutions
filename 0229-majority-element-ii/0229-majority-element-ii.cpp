class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count_1=0,count_2=0;
        int ele_1=-1,ele_2=-1;
        for(int i=0;i<nums.size();i++){
            if(count_1==0&&nums[i]!=ele_2){
                ele_1=nums[i];
                count_1++;
            }
            else if(count_2==0&&nums[i]!=ele_1){
                ele_2=nums[i];
                count_2++;
            }
            else if(nums[i]==ele_1){count_1++;}
            else if(nums[i]==ele_2){count_2++;}
            else{
                count_1--;
                count_2--;
            }
        }
        count_1=0;
        count_2=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele_1){count_1++;}
            else if(nums[i]==ele_2){count_2++;}
        }
        if(count_1>=(nums.size()/3+1)){
            ans.push_back(ele_1);
        }
        if(count_2>=(nums.size()/3+1)&&ele_2!=ele_1){
            ans.push_back(ele_2);
        }
        return ans;
    }
};