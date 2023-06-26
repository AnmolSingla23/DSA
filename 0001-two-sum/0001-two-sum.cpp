class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> ans;
        
        
        //this has the time compllexity of o(n2)
        // for(int i=0;i<nums.size();i++){
        //     for(int j = i+1;j<nums.size();j++){
        //         int sum = nums[i] + nums[j];
        //         if(sum  == target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;
        
        
        //SECOND APPROACH BETTER THEN LAST O(NLOGN) + O(N) TIME COMPLEXITY
//         sort(nums.begin(),nums.end());
        
//         int i=0;
//         int j = nums.size()-1;
//         int sum = 0;
//         while(i < j){
//             sum = nums[i] + nums[j];
//             if(sum == target){
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 break;
//             }
//             if(sum > target)
//                 j--;
//             else i++;
//         }
//         return ans;
        
        
        //best approach map reduces the time complexity of finding to o(1) so overall is O(n)
        unordered_map<int,int> mp;
        
        for(int i = 0;i<nums.size();i++){
            int remaining = target - nums[i];  //calculate the remainig sum
            if(mp.count(remaining)){   //chk if it is present or not
                ans.push_back(i);
                ans.push_back(mp[remaining]);
                break;
            }
            mp[nums[i]] = i;  //if not add that number corresponding to its index
        }
        return ans;
    }
};