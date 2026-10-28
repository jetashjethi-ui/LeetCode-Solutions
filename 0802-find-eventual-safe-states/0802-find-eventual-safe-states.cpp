class Solution {
public:
    bool detect_cycle(int node,vector<int>&visited,vector<int>&path_visited,vector<vector<int>>& graph,map<int,int>&safe){
        visited[node]=1;
        path_visited[node]=1;
        for(auto adj:graph[node]){
            if(safe.find(adj)!=safe.end()){
                safe[node]=1;
                return true;
            }
            if(!visited[adj]){
                if(detect_cycle(adj,visited,path_visited,graph,safe)){
                    safe[node]=1;
                    return true;
                }
            }
            else if(path_visited[adj]){
                safe[node]=1;
                return true;
            }
        }
        path_visited[node]=0;
        return false;

    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>visited(n,0);
        vector<int>path_visited(n,0);
        map<int,int>safe;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                if(detect_cycle(i,visited,path_visited,graph,safe)){safe[i]=1;}
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(safe.find(i)==safe.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};