//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    int remove_duplicate(vector<int> &arr) {
        if (arr.empty()) return 0;

        int cnt = 1; 
        for (int i = 1; i < arr.size(); i++) {
            if ((arr[i] ^ arr[cnt - 1]) != 0) {
                arr[cnt] = arr[i];
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.remove_duplicate(arr);
        for (int i = 0; i < ans; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends