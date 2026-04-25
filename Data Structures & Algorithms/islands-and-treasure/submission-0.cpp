class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& arr) {

        const int INF = 2147483647;
        queue<vector<int>>q;
        int n = arr.size() ,  m = arr[0].size();
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(arr[i][j]==0){
                    q.push({i,j,0});
                }
                    
            }
        }
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                vector<int>vec = q.front();
                q.pop();
                int x = vec[0], y = vec[1], dist = vec[2];
                for(int i=0; i<4; i++)
                {
                    int dx = x+dir[i][0] , dy=y+dir[i][1];
                    if(dx>=0 and dx<n and dy>=0 and dy<m and arr[dx][dy]==INF)
                    {
                        arr[dx][dy] = dist+1;
                        q.push({dx,dy,dist+1});
                    }
                }
            }
        }

        
    }
};
