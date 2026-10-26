class Solution {
public:
    int numberOfSubstrings(string s) {
        int count_a=0,count_b=0,count_c=0;
        int low=0,high=0;
        int ans=0;
        while(high<s.size()){
            if(s[high]=='a'){count_a++;}
            else if(s[high]=='b'){count_b++;}
            else{count_c++;}
            while(count_a>=1&&count_b>=1&&count_c>=1){
                ans+=s.size()-high;
                if(s[low]=='a'){count_a--;}
                else if(s[low]=='b'){count_b--;}
                else{count_c--;}
                low++;
            }
            high++;

        }
        return ans;
    }
};