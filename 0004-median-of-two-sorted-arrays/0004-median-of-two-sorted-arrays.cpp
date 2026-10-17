class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n=nums1.size();
        int m=nums2.size();
        int low=0,high=n;
        int l1,l2,r1,r2;
        while(low<=high){
            int mid=(low+high)/2;
            int p2=((n+m+1)/2)-mid;
            if(mid==0){
                l1=INT_MIN;
            }
            else{
                l1=nums1[mid-1];
            }
            if(mid==n){
                r1=INT_MAX;
            }
            else{
                r1=nums1[mid];
            }
            if(p2==0){
                l2=INT_MIN;
            }
            else{
                l2=nums2[p2-1];
            }
            if(p2==m){
                r2=INT_MAX;
            }
            else{
                r2=nums2[p2];
            }
            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                return max(l1,l2);
            }
            else if(l1>r2){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return 0.0;
    }
};