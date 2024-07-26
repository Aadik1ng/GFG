//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>& arr, int n, long long s) {
        int j = 0; // Initialize start pointer
        long long sum = 0;
        vector<int> ans;
        
        for (int i = 0; i < n; ++i) {
            sum += arr[i]; // Add current element to sum
            
            while (sum > s && j < i) {
                sum -= arr[j];
                j++;
            }
            
            if (sum == s) {
                ans.push_back(j + 1); // Convert to 1-based index
                ans.push_back(i + 1); // Convert to 1-based index
                break;
            }
        }
        
        // If ans is empty, return {-1} indicating no subarray found
        if (ans.empty()) {
            return {-1};
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends