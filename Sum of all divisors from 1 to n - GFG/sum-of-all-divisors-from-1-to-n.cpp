//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:

    long long solve(int n,long long &sum){
            
        for(int i=1;i<=n;i++){
            if(n%i == 0)
                sum += i;
        }
        return sum;
    }
    
    
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        
        //TLE FOR VERY LARGE CASES
        // long long sum = 0;
        
        // for(int i=1;i<=N;i++){
        //     sum = solve(i,sum);
        // }
        // return sum;
        
        long long sum = 0;
        
        for(int i=1;i<=N;i++){
            sum += (N/i)*i;  // N/i will be number of occurences that will happen and *i will be sum
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends