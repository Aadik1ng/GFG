//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    bool ispar(string x)
    {
        stack<char> st;
        for(int i = 0; i < x.size(); ++i) {
            switch (x[i]) {
                case '{':
                case '[':
                case '(':
                    st.push(x[i]);
                    break;
                case '}':
                    if(st.empty() || st.top() != '{')
                        return false;
                    st.pop();
                    break;
                case ']':
                    if(st.empty() || st.top() != '[')
                        return false;
                    st.pop();
                    break;
                case ')':
                    if(st.empty() || st.top() != '(')
                        return false;
                    st.pop();
                    break;
            }
        }
        return st.empty();
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends