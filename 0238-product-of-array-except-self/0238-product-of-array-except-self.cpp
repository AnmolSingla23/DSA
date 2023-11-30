class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> temp(nums.size(),1);
        int product = 1;
        for(int i=0;i<nums.size();i++){
            temp[i] = product*temp[i];
            product = product*nums[i];
        }
        
        product = 1;
        for(int i=nums.size()-1;i>=0;i--){
            temp[i] = temp[i]*product;
            product = product*nums[i];
        }
        return temp;
    }
};