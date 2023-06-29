class Solution {
public:

    void dfs(vector<vector<char>>& grid,int row,int col){
        if(grid[row][col] == 'O'){ //if boundry has O conver it into #
            grid[row][col] = '#';  //then chekc its adjacent using dfs
        
        if(row > 1)  //to check prev row
            dfs(grid,row-1,col);
        if(row+1 < grid.size())  //to check next row
            dfs(grid,row+1,col);
        if(col>1)           //to check the left side of the col
            dfs(grid,row,col-1);
        if(col + 1 < grid[row].size())  //to check right side
            dfs(grid,row,col+1);
        }
    }

    void solve(vector<vector<char>>& board) {
       //APPROACH TRAVERSE THE BOUNDRY AND THEN MARK THE 0 TO # AND THEN CALL DFS
       //TO CHECK ITS ADJACENTS AFTER THIS TRAVERSE WHOLE MATRIX .

       if(board.size() == 0) return;
       int row = board.size();
       int col = board[0].size();

       //to traverse first and last col
       for(int i = 0;i<row;i++){
           dfs(board,i,0);
           dfs(board,i,col-1);
       }

       //for first and last row
       for(int i=0;i<col;i++){
           dfs(board,0,i);
           dfs(board,row-1,i);
       }

       for(int i=0;i<row;i++){
           for(int j = 0;j<col;j++){
                if(board[i][j] == 'O')  //convert O to X
                    board[i][j] = 'X';
                else if(board[i][j] == '#')  //if there # convert it into O 
                    board[i][j] = 'O';
           }
       }
    }
};


        //misses one edge case
        // int n = board.size();
        // int m = board[0].size();
        // queue<pair<int,int>> q;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(board[i][j] == 'X')
        //             q.push({i,j});
        //         if(board[i][j] == 'O' && (i == 0 || j == 0 || i == n-1 || j == m-1)){
        //             board[i][j] = '#';
        //         }
        //     }
        // }


        // while(!q.empty()){
        //     auto fnode = q.front();
        //     int x = fnode.first;
        //     int y = fnode.second;
        //     q.pop();

        //     int dx[] = {-1,0,1,0};
        //     int dy[] = {0,-1,0,1};

        //     for(int i=0;i<4;i++){
        //         int newx = x + dx[i];
        //         int newy = y + dy[i];

        //         if(newx >= 0 && newy >= 0 && newx < n && newy < m 
        //         && board[newx][newy] == 'O'){
        //             q.push({newx,newy});
        //             board[newx][newy] = 'X';
        //         }
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(board[i][j] == '#')
        //             board[i][j] = 'O';
        //     }
        // }