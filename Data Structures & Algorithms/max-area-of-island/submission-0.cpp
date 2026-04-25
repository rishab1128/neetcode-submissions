class Solution {
public:
    int n,m;
    vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& arr, int x, int y, vector<vector<int>>&vis, int&area)
    {
        vis[x][y] = 1;
        area++;
        for(int i=0; i<4; i++)
        {
            int newX = x+dir[i][0] , newY = y+dir[i][1];
            if(newX>=0 and newX<n and newY>=0 and newY<m and arr[newX][newY]==1 and !vis[newX][newY]){
                dfs(arr,newX,newY,vis,area);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& arr) {
        n = arr.size() , m = arr[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr[i][j]==1 and !vis[i][j])
                {
                    int area = 0;
                    dfs(arr,i,j,vis,area);
                    ans = max(ans,area);
                }
            }
        }
        return ans;
        
    }
};
