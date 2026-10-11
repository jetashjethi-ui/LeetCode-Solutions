class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1,right=n-1;//m+n-1
        while(left>=0&&right>=0){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums1[left+right+1]);
                left--;
            }
            else{
                swap(nums2[right],nums1[left+right+1]);
                right--;
            }
        }
        while(right>=0){
            nums1[right]=nums2[right];
            right--;
        }
        
    }
};