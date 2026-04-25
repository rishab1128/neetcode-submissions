class Solution {
public:
    int n,m;
    vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<char>>& arr, int x, int y, vector<vector<int>>&vis)
    {
        vis[x][y] = 1;
        for(int i=0; i<4; i++)
        {
            int newX = x+dir[i][0] , newY = y+dir[i][1];
            if(newX>=0 and newX<n and newY>=0 and newY<m and arr[newX][newY]=='1' and !vis[newX][newY]){
                dfs(arr,newX,newY,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& arr) 
    {
        n = arr.size() , m = arr[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr[i][j]=='1' and !vis[i][j])
                {
                    cnt++;
                    dfs(arr,i,j,vis);
                }
            }
        }
        return cnt;
        
        
    }
};
