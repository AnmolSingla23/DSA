//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
       vector<int> ans;
       sort(candies,candies+N);
       int sum1=0,sum2=0;
       int i=0,j=N-1;
       while(i<N){
           
           sum1+=candies[i];
           N=N-K;
           i++;
       }
       ans.push_back(sum1);
       i=0;
       while(j>=i){
           sum2+=candies[j];
           i=i+K;
           j--;
           
       }
       ans.push_back(sum2);
       return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends