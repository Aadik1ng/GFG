//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isValid(int sr, int sc, vector<vector<int>>& image, int oldColor, vector<vector<int>>& seen) {
        return sr >= 0 && sr < image.size() && sc >= 0 && sc < image[0].size() && image[sr][sc] == oldColor && !seen[sr][sc];
    }
    
    void bfs(int sr, int sc, vector<vector<int>>& image, int newColor, vector<vector<int>>& seen) {
        int oldColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;
        seen[sr][sc] = 1;
        
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (isValid(nr, nc, image, oldColor, seen)) {
                    image[nr][nc] = newColor;
                    seen[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();
        int cols = image[0].size();
        vector<vector<int>> seen(rows, vector<int>(cols, 0));
        bfs(sr, sc, image, newColor, seen);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends