class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& nums, vector<double>& price, int start, int end) {
        
        vector<vector<pair<int,double>>> adjlist(n);
        
        for(int i =0;i<nums.size();i++){
            adjlist[nums[i][0]].push_back({nums[i][1],price[i]});
            adjlist[nums[i][1]].push_back({nums[i][0],price[i]});
        }
        
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start});
        
        vector<double> distance(n,INT_MIN);
        
        while(!pq.empty()){                                         
            auto top = pq.top();
            pq.pop();
            
            double dist = top.first;
            int node = top.second;
            
            for(auto nbr:adjlist[node]){
                int anode = nbr.first;
                double adis = nbr.second;
                if(distance[anode] < dist * adis){
                    distance[anode] = dist*adis;
                    pq.push({distance[anode],anode});
                }
            }
        }
        if(distance[end] == INT_MIN) return 0.0000;
        else
            return distance[end];
        
    }
};