class Solution {
public:
     static bool mycomp(vector<int> &a,vector<int> &b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        
        sort(nums.begin(),nums.end(),mycomp);
        int n = nums.size();
        
        // vector<vector<int> > inter;
        // inter.push_back(nums[0]);

        int interv = nums[0][1];
        int ans = 1;

        // for(int i=1;i<nums.size();i++){
        //     if(inter.back()[1] <= nums[i][0]){
        //         inter.push_back(nums[i]);
        //     }
        // }
        // return nums.size() - inter.size();

        for(int i=1;i<n;i++){
            if(interv <= nums[i][0]){
                ans++;
                interv = nums[i][1];
            }
        }
        return n-ans;
    }
};