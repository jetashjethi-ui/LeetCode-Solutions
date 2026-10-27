class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),0);
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            if(color[i]!=0) continue;
            q.push(i);
            color[i]=-1;
            while(!q.empty()){
                int node=q.front();
                int last_pass=color[node];
                q.pop();
                for(auto neighbour:graph[node]){
                    if(color[neighbour]==0){
                        color[neighbour]=-last_pass;
                        q.push(neighbour);
                    }
                    else{
                        if(color[neighbour]==last_pass){
                            return false;
                        }

                    }

                }
            }
        }    
        return true;
    }  
}; 