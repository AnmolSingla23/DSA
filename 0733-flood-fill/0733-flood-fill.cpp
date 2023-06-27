class Solution {
public:
    
    void dfs(int row,int col, int color,vector<vector<int> > &ans, map<pair<int,int>, bool> &vis,int oldcolor){
        
        vis[{row,col}] = true;
        ans[row][col] = color;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for(int i = 0;i<4;i++){
            int newx = row + dx[i];
            int newy = col + dy[i];
            
            if(newx >=0 && newx < ans.size() && newy >= 0 && newy < ans[0].size()
               && !vis[{newx,newy}] && ans[newx][newy] == oldcolor){
                dfs(newx,newy,color,ans,vis,oldcolor);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        map<pair<int,int>, bool> vis;
        int oldcolor = image[sr][sc];
        vector<vector<int> > ans = image;
        
        dfs(sr,sc,color,ans,vis,oldcolor);
        return ans;
    }
};