class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
        sort(citations.begin(),citations.end());

        int ans = 0;
        for(int i=n-1;i>=0;i--){
            if(ans < citations[i]){
                ans++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};