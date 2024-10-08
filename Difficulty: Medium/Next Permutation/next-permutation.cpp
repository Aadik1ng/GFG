//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<int> nextPermutation(int N, vector<int> arr) {
        int k = -1;
        for (int i = N - 2; i >= 0; --i) {
            if (arr[i] < arr[i + 1]) {
                k = i;
                break;
            }
        }
        
        if (k == -1) {
            reverse(arr.begin(), arr.end());
            return arr;
        }
        
        int l = -1;
        for (int i = N - 1; i > k; --i) {
            if (arr[i] > arr[k]) {
                l = i;
                break;
            }
        }
        
        swap(arr[k], arr[l]);
        
        reverse(arr.begin() + k + 1, arr.end());
        
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends