class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<pair<int,int>,int>> q;
        int ans = 0;
        int fresh = 0;
        for(int i=0;i<grid.size();i++){
            for(int j = 0;j<grid[i].size();j++){
                if(grid[i][j] == 2)
                    q.push({{i,j},0});
                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        vector<vector<int> > arr = grid;

        while(!q.empty()){
            auto fnode = q.front();
            int x = fnode.first.first;
            int y = fnode.first.second;
            int time = fnode.second;
            q.pop();

            int dx[] = {-1,0,1,0};
            int dy[] = {0,-1,0,1};

            for(int i=0;i<4;i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx >= 0 && newy >= 0 && newx < arr.size() && newy < arr[0].size() && arr[newx][newy] == 1){
                    ans = max(time+1,ans);
                    q.push({{newx,newy},time+1});
                    fresh--;
                    arr[newx][newy] = 2;
                }
            }
        }
        if(fresh > 0) return -1;
        else
            return ans;
    }
};                                                                                                     