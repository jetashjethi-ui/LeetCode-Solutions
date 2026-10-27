class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&path){
        path[node]=true;
        visited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i]){
                if(dfs(i,adj,visited,path)){
                    return true;
                }
            }
            else if(path[i]){
                return true;
            }
        }
        path[node]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        vector<bool>visited(numCourses,false);
        vector<bool>path(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,path)){return false;}
            }
        }
        return true;
    }
};