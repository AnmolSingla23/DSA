class Solution {
public:
    
    vector<int> toposort(int n, unordered_map<int,list<int>> &adj){
        
        queue<int> q;
        unordered_map<int,int> indegree;
        vector<int> ans;
        
        //calculate the indegree
        for(auto i:adj){
            for(auto nbr:i.second){
                indegree[nbr]++;
            }
        }
        
        //push node with 0 indegree
        for(int i=0;i<n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        //store the toposort
        while(!q.empty()){
            int fnode = q.front();
            q.pop();
            
            ans.push_back(fnode);
            
            for(auto nbr:adj[fnode]){
                indegree[nbr]--;  
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        if(ans.size() == n)
            return ans;
        else return {};
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
                                                                            unordered_map<int,list<int>> adj; //create a adj list
             for(auto task:prerequisites){
                 int u = task[0];
                 int v = task[1];
                 adj[v].push_back(u);
             }
        vector<int> ans;
        ans = toposort(numCourses,adj);
        return ans;
    }        
};