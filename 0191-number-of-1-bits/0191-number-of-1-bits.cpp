class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        while(n>0){ 
            if(n&1){    //this will check use and operation with 1 if right most is 1 it will count
                count++;
            }
            n >>= 1; //and then we right shift by 1
        }
        return count;
    }
};