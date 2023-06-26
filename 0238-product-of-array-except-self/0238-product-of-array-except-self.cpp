class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     
        vector<int> arr(nums.size()); 
        int temp = 1;
        for(int i = 0;i<nums.size();i++){  //create a vector with product of all elements prev from curr
            arr[i] = temp;
            temp = nums[i]*temp;
        }
        
        temp = 1;
        for(int i=arr.size()-1;i>=0;i--){  //then start from last and find the product from right side from 
            arr[i] = temp*arr[i];          //curr except curr thhis will five us the answer
            temp = temp*nums[i];
        }
        return arr;
    }
};