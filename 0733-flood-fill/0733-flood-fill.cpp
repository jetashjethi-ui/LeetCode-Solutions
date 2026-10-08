class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origColor=image[sr][sc];
        if(origColor==color){return image;}
        int m=image.size();
        int n=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int row[]={-1,1,0,0};
        int col[]={0,0,-1,1};
        vector<pair<int,int>>ans;
        ans.push_back({sr,sc});
        image[sr][sc]=color;

        while(!q.empty()){
            pair<int,int>node=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=node.first+row[i];
                int nc=node.second+col[i];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&image[nr][nc]==origColor){
                    ans.push_back({nr,nc});
                    q.push({nr,nc});
                    image[nr][nc]=color;
                }
            }
        }
        for(auto i:ans){
            image[i.first][i.second]=color;
        }
        return image;
    }
};