//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string findLongestWord(string S, vector<string> d) {
        string longestWord = "";

        for ( string word : d) {
            int i = 0, j = 0;
            while (i < S.size() && j < word.size()) {
                if (S[i] == word[j]) {
                    j++;
                }
                i++;
            }
            if (j == word.size() && (word.size() > longestWord.size() || (word.size() == longestWord.size() && word < longestWord))) {
                longestWord = word;
            }
        }

        return longestWord;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> d(n + 1);
        for (int i = 0; i < n; i++)
            cin >> d[i];
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findLongestWord(S, d) << endl;
    }
    return 0;
}

// } Driver Code Ends