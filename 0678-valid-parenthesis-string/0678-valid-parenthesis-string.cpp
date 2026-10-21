class Solution {
public:
    bool checkValidString(string s) {
        int open=0,close=0;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]=='('||s[i]=='*')open++;
            else open--;
            
            if(s[n-1-i]==')'||s[n-1-i]=='*')close++;
            else close--;
            
            if(open<0||close<0)return false;
        }
        
        return true;
    }
};