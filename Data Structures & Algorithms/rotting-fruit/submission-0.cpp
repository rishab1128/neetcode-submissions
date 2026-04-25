class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) 
    {
        queue<vector<int>>q;
        int n = arr.size() ,  m = arr[0].size();
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        int fresh = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr[i][j]==2)
                    q.push({i,j,0});

                if(arr[i][j]==1)
                    fresh++;
            }
        }
        int ans = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                vector<int>vec = q.front();
                q.pop();
                int x = vec[0], y = vec[1], time = vec[2];
                ans = max(ans,time);
                for(int i=0; i<4; i++)
                {
                    int dx = x+dir[i][0] , dy=y+dir[i][1];
                    if(dx>=0 and dx<n and dy>=0 and dy<m and arr[dx][dy]==1)
                    {
                        arr[dx][dy] = 2;
                        fresh--;
                        q.push({dx,dy,time+1});
                    }
                }
            }
        }
        if(fresh > 0)
            return -1;

        return ans;
        
    }
};
