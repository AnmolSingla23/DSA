class Solution {
public:
    
     void solve(int start, vector<int> &cookies, int k,vector<int> &nums,int &ans){
        
        if(start == cookies.size()){  //when start reaches end check
            int maxi = INT_MIN;
            for(int i=0;i<k;i++){  //if all have got cookies and who got max cookies
                maxi = max(maxi,nums[i]);
            }
            ans = min(ans,maxi);
            return;
        }

        for(int i=0;i<k;i++){//first give cookies to 1st child then using backtracking
            nums[i] += cookies[start];   //fill others and start removing from prev
            solve(start+1,cookies,k,nums,ans);  //child
            nums[i] -= cookies[start];
        }
    }

    
    int distributeCookies(vector<int>& cookies, int k) {
        
        int ans = INT_MAX;
        vector<int> nums(k,0);  //create a array of size of children with 0 cookies
        solve(0,cookies,k,nums,ans);  
        return ans;
        
    }
};