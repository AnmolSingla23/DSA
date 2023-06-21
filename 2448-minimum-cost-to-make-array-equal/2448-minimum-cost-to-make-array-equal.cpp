class Solution {
public:

    long long solve(vector<int>& nums, vector<int>& cost,long long &mid){
        long long ans = 0;
        for(int i = 0;i<nums.size();i++){
            ans += abs(nums[i] - mid)*cost[i];  //multiply the abs value with the cost
        }
        return ans;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {

        int n = nums.size();
        vector<pair<int,int> > arr;

        for(int i = 0;i<n;i++){
            arr.push_back({nums[i],cost[i]});  //store both the arrays in pair form
        }

        sort(arr.begin(),arr.end());  //sort the pair acc to nums array

        //lets make the cost as freq like from 1st example 1 is 2 times 2 is 14 times 3 is 3 times
        // and 5 occurs only once so total freq is sum of cost or total freq

        long long count = 0;
        for(int i = 0;i<n;i++){
            count += cost[i];  //get the total number of eleemnts
        }

        long long mid;
        long long total = 0;
        int i = 0;
        while(total < count/2+1 && i<n){
            total += arr[i].second;    //find the nums where the median of count will be there
            mid = arr[i].first;      //we are taking median as we know cost is min at center
            i++;
        }

        return solve(nums,cost,mid);   //calculaate the final cost
        
    }
};