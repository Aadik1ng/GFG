//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Function to find the largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n) {
        stack<int> s;  // Stack to store indices of histogram bars
        long long maxArea = 0;  // Initialize maximum area
        int index = 0;

        while (index < n) {
            if (s.empty() || arr[s.top()] <= arr[index]) {
                s.push(index++);
            } else {
                int topOfStack = s.top();
                s.pop();

                long long height = arr[topOfStack];

                long long width;
                if (s.empty()) {
                    width = index; 
                } else {
                    width = index - s.top() - 1;  
                }

                long long area = height * width;

                maxArea = max(maxArea, area);
            }
        }

        while (!s.empty()) {
            int topOfStack = s.top();
            s.pop();

            long long height = arr[topOfStack];
            long long width;
            if (s.empty()) {
                width = index;  
            } else {
                width = index - s.top() - 1; 
            }

            long long area = height * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends