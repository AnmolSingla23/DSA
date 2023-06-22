class Solution {
public:
        
    void dfs(vector<vector<char> > &grid,int row,int col){
            int n = grid.size();
            int m = grid[0].size();

            if(row < 0 || row >= n || col < 0 || col >= m)   //base case
                return ;

            if(grid[row][col] == '0')   //if we are on water/'0' return as there is no more land
                return ;
            grid[row][col] = '0';   //if we are on 1 mark it 0 so that we donot tareverse it again

            dfs(grid,row+1,col);    //perform recursion call on all 4 sides
            dfs(grid,row-1,col);
            dfs(grid,row,col+1);
            dfs(grid,row,col-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;
        for(int i = 0;i<n;i++){   //using nested loop we are checking all the points
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1'){  //if the curr point is 1 so check all the adjoing points
                    dfs(grid,i,j);      //by performing dfs search
                    islands++;        //increase the count islands
                }
            }
        }
        return islands;
    }
};