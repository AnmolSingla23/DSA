class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        long long maxsum = INT_MIN;
        long long currsum = 0;
        
        for(int i = 0;i<nums.size();i++){
            currsum += nums[i];
            if(currsum > maxsum){
                maxsum = currsum;
            }
            
            if(currsum < 0){
                currsum = 0;
            }
        }
        return maxsum;
    }
};