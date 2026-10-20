class Solution {
public:
    void generate(string digits,int idx,string temp,vector<string>&sol){
        if(idx==digits.size()){
            sol.push_back(temp);
            return;
        }
        if(digits[idx]=='2'){
            generate(digits,idx+1,temp+'a',sol);
            generate(digits,idx+1,temp+'b',sol);
            generate(digits,idx+1,temp+'c',sol);
        }
        else if(digits[idx]=='3'){
            generate(digits,idx+1,temp+'d',sol);
            generate(digits,idx+1,temp+'e',sol);
            generate(digits,idx+1,temp+'f',sol);
        }
        else if(digits[idx]=='4'){
            generate(digits,idx+1,temp+'g',sol);
            generate(digits,idx+1,temp+'h',sol);
            generate(digits,idx+1,temp+'i',sol);
        }
        else if(digits[idx]=='5'){
            generate(digits,idx+1,temp+'j',sol);
            generate(digits,idx+1,temp+'k',sol);
            generate(digits,idx+1,temp+'l',sol);
        }
        else if(digits[idx]=='6'){
            generate(digits,idx+1,temp+'m',sol);
            generate(digits,idx+1,temp+'n',sol);
            generate(digits,idx+1,temp+'o',sol);
        }
        else if(digits[idx]=='7'){
            generate(digits,idx+1,temp+'p',sol);
            generate(digits,idx+1,temp+'q',sol);
            generate(digits,idx+1,temp+'r',sol);
            generate(digits,idx+1,temp+'s',sol);
        }
        else if(digits[idx]=='8'){
            generate(digits,idx+1,temp+'t',sol);
            generate(digits,idx+1,temp+'u',sol);
            generate(digits,idx+1,temp+'v',sol);
        }
        else if(digits[idx]=='9'){
            generate(digits,idx+1,temp+'w',sol);
            generate(digits,idx+1,temp+'x',sol);
            generate(digits,idx+1,temp+'y',sol);
            generate(digits,idx+1,temp+'z',sol);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>sol;
        string temp="";
        generate(digits,0,temp,sol);
        return sol;
    }
};