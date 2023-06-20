class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int> ans(n,-1);

        int window = 2*k+1;   //this is the size of window whose avg we calculate

        if( n < window)       //base case
            return ans;

        long long sum = 0;  

        for(int i = 0;i<n;i++){

            sum += nums[i];

            if(i - window >= 0){    //this means we have crossed the window size remove the element  
                sum -= nums[i-window]; //from left side at index 0 ;
            }
            
            if(i >= window - 1){   //index is greater equal to window-1 then calculate the avg
                ans[i-k] = sum/window;   //and add it to the its correct position index - k
            }
        }
        return ans;
    }
};