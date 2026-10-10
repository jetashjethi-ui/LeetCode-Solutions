class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int m=matrix.size();
            int n=matrix[0].size();
            vector<int>ans;
            int top=0,bottom=m-1,left=0,right=n-1;
            for(int i=0;i<2*min(m,n);i++){
                if(i%4==0){
                    for(int j=left;j<=right;j++){
                        ans.push_back(matrix[top][j]);
                    }
                    top++;
                }
                else if(i%4==1){
                    for(int j=top;j<=bottom;j++){
                        ans.push_back(matrix[j][right]);
                    }
                    right--;
                }
                else if(i%4==2){
                    for(int j=right;j>=left;j--){
                        ans.push_back(matrix[bottom][j]);
                    }
                    bottom--;
                }
                else{
                    for(int j=bottom;j>=top;j--){
                        ans.push_back(matrix[j][left]);
                    }
                    left++;
                }
                if(top>bottom||left>right){
                break;
                }
            }
            return ans;
        }
    };