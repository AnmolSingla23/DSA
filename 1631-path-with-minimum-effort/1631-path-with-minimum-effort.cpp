class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        //creating a min heap {distance,{x coordinate,y coordinate}}
        vector<vector<int>> dist(heights.size(),vector<int> (heights[0].size(),INT_MAX)); //distance matrix
                                            
        pq.push({0,{0,0}});  //push the starting point and its address
        dist[0][0] = 0;    

        while(!pq.empty()){
            auto fnode = pq.top();
            int ndis = fnode.first;   //take the dis at that node
            int x = fnode.second.first;
            int y = fnode.second.second;
            pq.pop();

            if(x == heights.size()-1 && y == heights[0].size()-1){
                return dist[x][y];   //see if we have reached the end point so return as we are applying djkistra and greedy 
            }                        //it will return the minimum distance

            int dx[] = {-1,0,1,0};
            int dy[] = {0,-1,0,1};

            for(int i = 0;i<4;i++){
                int newx = x + dx[i];  //new coordinates
                int newy = y + dy[i];

                if(newx >= 0 && newx < heights.size() && newy >= 0 && newy < heights[0].size()){
                    int currdis = abs(heights[x][y] - heights[newx][newy]);  //calculate the abs diff between old and new 
                    int newdis = max(currdis,ndis);      //find the maximum of abs diff and diff present in distance matrix
                    if(dist[newx][newy] > newdis){       //if new coodinates at dist is greater then newdis so update it
                        dist[newx][newy] = newdis;
                        pq.push({newdis,{newx,newy}});  //and then push the newdis with its coordinates
                    }
                }
            }
        }
        return 0;
    }
};