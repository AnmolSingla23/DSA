class Solution {
public:
    
    bool toposort(int n, unordered_map<int,list<int>> &adj){
        vector<int> ans;
        unordered_map<int,int> indegree;
        queue<int> q;
        
        //to find the indegree
        for(auto i:adj){
            for(auto nbr:i.second){
                indegree[nbr]++;
            }
        }
        
        //insert the ones with indegree zero into the queue
        for(int i=0;i<n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int fnode = q.front();
            q.pop();
            
            ans.push_back(fnode);
            
            for(auto i:adj[fnode]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        
        if(ans.size() == n) return true;
        else
            return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
                                                                            unordered_map<int,list<int>> adj; //create a adj list
        for(auto task:prerequisites){
            int u = task[0];
            int v = task[1];
            adj[v].push_back(u);
        }
        return toposort(numCourses,adj);
    }
};