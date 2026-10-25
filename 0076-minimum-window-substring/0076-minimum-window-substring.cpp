class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>mp;
        for(auto i:t){
            mp[i]++;
        }
        int ans=INT_MAX;
        int count=0;
        int left=0;
        int start=0;
        for(int right=0;right<s.size();right++){
            if(mp.find(s[right])!=mp.end()){
                if(mp[s[right]]>0){
                    count++;
                }
                mp[s[right]]--;
            }
            while(count==t.size()){
                if(right-left+1<ans){
                    ans=right-left+1;
                    start=left;
                }
                if(mp.find(s[left])!=mp.end()){
                    mp[s[left]]++;
                    if(mp[s[left]]>0){
                        count--;
                    }
                }
                left++;
            }
        }
        return ans==INT_MAX ? "" : s.substr(start,ans);
    }
};