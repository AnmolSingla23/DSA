class Solution {
public:
    int trap(vector<int>& height) {
        
        int start = 0;
        int end = height.size()-1;
        long long area = 0;
        long long lmax = 0;
        long long rmax = 0;
        
        while(start <= end){
            if(height[start] < height[end]){
                if(height[start] > lmax){ //if the current bar is greater then the max bar from left
                    lmax = height[start];  //update the current greatest
                }
                else{
                    area = area + lmax - height[start];  //if current is smaller then add the amount of water thaat can be stored
                    start++;
                }
            }
            else{
                if(height[end] > rmax){
                    rmax = height[end];
                }
                else{
                    area = area + rmax - height[end];
                    end--;
                }
            }
        }
        return area;
    }
};