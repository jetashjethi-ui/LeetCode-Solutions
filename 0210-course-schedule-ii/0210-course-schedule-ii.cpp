class Solution {
public:
    bool dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&path,vector<int>&ans){
        path[node]=true;
        visited[node]=true;
        for(auto i:adj[node]){
            if(!visited[i]){
                if(dfs(i,adj,visited,path,ans)){
                    return true;
                }
            }
            else if(path[i]){
                return true;
            }
        }
        path[node]=false;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<bool>hasPrereq(numCourses,false);
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
            hasPrereq[i[0]]=true;
        }
        vector<bool>visited(numCourses,false);
        vector<bool>path(numCourses,false);
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            if(!hasPrereq[i] && !visited[i]){
                if(dfs(i,adj,visited,path,ans)){return {};}
            }
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(i,adj,visited,path,ans)){return {};}
            }
        }

        return ans;
    }
};