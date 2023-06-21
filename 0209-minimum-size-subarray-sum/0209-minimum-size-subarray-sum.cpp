class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int length = INT_MAX;
        int sum = 0;
        int left = 0;
        int right = 0;

        while(right < nums.size()){
            sum += nums[right++];
            while(sum >= target){
                length = min(right-left,length);
                sum -= nums[left++];
            }
        }
        if(length == INT_MAX)
            return 0;
        else 
            return length;
    }
};