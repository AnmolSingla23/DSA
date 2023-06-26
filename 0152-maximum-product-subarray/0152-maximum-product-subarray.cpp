class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        int maxprod = nums[0];
        int minprod = nums[0];
        int prod = nums[0];
        
        for(int i=1;i<nums.size();i++){
            
            if(nums[i] < 0)
                swap(maxprod,minprod); //if index is negative swap the values so that we can see if theres any another negatice element in array we can multiply with it 

            maxprod = max(maxprod*nums[i],nums[i]);  
            minprod = min(minprod*nums[i],nums[i]);
            
            prod = max(maxprod,prod);
        }
        return prod;
    }
};