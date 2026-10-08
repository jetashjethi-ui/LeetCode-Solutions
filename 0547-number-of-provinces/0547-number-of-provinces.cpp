class Solution {
    public:
        void dfs(vector<bool>&visited,int node,vector<vector<int>>&isConnected){
            visited[node]=true;
            for(int i=0;i<isConnected.size();i++){
                if(isConnected[node][i]==1&& visited[i]!=true){
                    dfs(visited,i,isConnected);
                }
            }
        }
        int findCircleNum(vector<vector<int>>& isConnected) {
            vector<bool>visited(isConnected.size(),false);
            int count=0;
            for(int i=0;i<isConnected.size();i++){
                if(visited[i]==false){
                    count++;
                    dfs(visited,i,isConnected);
                }
            }
            return count;
        }
    };