class Solution {
public:
    void ans(int n,int close,int open,vector<string> &sol,string temp){
        if(temp.length()==2*n){
            sol.push_back(temp);
            return;
        }
        if(open<n){
            ans(n,close,open+1,sol,temp+'(');
        }
        if(close<open){
            ans(n,close+1,open,sol,temp+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>sol;
        string temp="";
        ans(n,0,0,sol,temp);
        return sol;
    }
};