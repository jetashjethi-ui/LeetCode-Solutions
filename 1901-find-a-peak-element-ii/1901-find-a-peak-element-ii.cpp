class Solution {
public:
    int rows(vector<vector<int>>&mat,int col){
        int maxi=-1;
        for(int i=0;i<mat.size();i++){
            maxi=max(maxi,mat[i][col]);
        }
        for(int i=0;i<mat.size();i++){
            if(mat[i][col]==maxi){return i;}
        }
        return -1;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low=0,high=mat[0].size()-1;
        while(low<=high){
            int mid=(high+low)/2;
            int row=rows(mat,mid);
            int left=mid-1>=0?mat[row][mid-1]:-1;
            int right=mid+1<mat[0].size()?mat[row][mid+1]:-1;
            if(mat[row][mid]>left&&mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<right){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return {-1,-1};
    }
};