//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int longestKSubstr(string s, int k) {
        map<char, int> freq;  
        int maxLength = -1;  
        int left = 0;  

        for (int right = 0; right < s.size(); ++right) {
            freq[s[right]]++;  

            while (freq.size() > k) {
                freq[s[left]]--;  
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);  
                }
                left++;  
            }

            if (freq.size() == k) {
                maxLength = max(maxLength, right - left + 1);  
            }
        }

        return maxLength;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends