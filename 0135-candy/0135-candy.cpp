class Solution {
public:
    int candy(vector<int>& ratings) {
        int low=0;
        vector<int>ans(ratings.size(),1);
        while(low<ratings.size()){
            if(low<ratings.size()-1&&ratings[low]==ratings[low+1]){
                low++;
                continue;
            }
            int assign=1;
            while(low<ratings.size()-1&&ratings[low]<ratings[low+1]){
                ans[low]=assign;
                assign++;
                low++;
            }
            int temp=low;
            while(temp<ratings.size()-1&&ratings[temp]>ratings[temp+1]){
                temp++;
            }
            int count=1;
            for(int i=temp;i>low;i--){
                ans[i]=count;
                count++;
            }
            ans[low]=max(assign,count);
            if(temp==low){
                low++;
            }
            else{
                low=temp;
            }
        }
        int total=0;
        for(int i=0;i<ans.size();i++){
            total+=ans[i];
        }
        return total;
    }
};