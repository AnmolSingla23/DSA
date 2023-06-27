class Solution {
public:
    
    void dfs(vector<vector<int>>& nums,int src, unordered_map<int,bool> &vis){
        vis[src] = true;  //mark the row true which is visited
        
        int size = nums[src].size();  //the check the whole row
        
        for(int col=0;col<size;col++){
            if(col != src && nums[src][col] == 1){
                if(!vis[col])
                dfs(nums,col,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int provinces = 0;
        unordered_map<int,bool> vis;  
        
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i]){
                dfs(isConnected,i,vis);
                provinces++;
            }
        }
        return provinces;
    }
};