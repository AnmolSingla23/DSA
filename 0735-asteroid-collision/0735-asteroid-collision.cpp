class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        
         stack<int> s;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] > 0 || s.empty()){  //if the number is positive or stack is empty push
                s.push(nums[i]);     //it in stack
            }
            else{
                while(!s.empty() && s.top() > 0 && s.top() < abs(nums[i])){
                    s.pop();  //if stack is not empty and top is pos and top is less then 
                }           //next abs elemnt then pop the top of stack
                if(!s.empty() && s.top() == abs(nums[i])){   //if top is equal to next still 
                    s.pop();   //pop the top of stack
                }
                else{
                    if(s.empty() || s.top() < 0){  
                        s.push(nums[i]);
                    }
                }
            }
        }
        vector<int> ans(s.size());
        for(int i=s.size()-1;i>=0;i--){   //reverse push the stack in array
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }
};