//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   int singleElement(int arr[], int N) {
        int ones = 0, twos = 0;
        for (int i = 0; i < N; ++i) {
            int num = arr[i];
            
            twos |= ones & num;
            
            ones ^= num;
            
            int threes = ones & twos;
            
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends