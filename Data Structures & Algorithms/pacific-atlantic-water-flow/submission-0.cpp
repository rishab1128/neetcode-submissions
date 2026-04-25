class Solution {
public:
    int n,m;
    vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
    void process(queue<vector<int>>&q, set<vector<int>>&st, vector<vector<int>>&vis, vector<vector<int>>&hts)
    {
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                auto vec = q.front();
                int x = vec[0], y = vec[1];
                q.pop();
                st.insert(vec);
                for(int k=0; k<4; k++)
                {
                    int dx = x+dir[k][0] , dy = y+dir[k][1];
                    if(dx>=0 and dx<n and dy>=0 and dy<m and !vis[dx][dy] and hts[dx][dy]>=hts[x][y])
                    {
                        vis[dx][dy] = 1;
                        q.push({dx,dy});
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& hts) 
    {
        n = hts.size() , m = hts[0].size();

        queue<vector<int>>q1;
        set<vector<int>>pacific;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0; j<m; j++)
        {
            q1.push({0,j});
            vis[0][j] = 1;
        }
        for(int i=0; i<n; i++)
        {
            q1.push({i,0});
            vis[i][0] = 1;
        }
        process(q1,pacific,vis,hts);


        queue<vector<int>>q2;
        set<vector<int>>atlantic;
        vector<vector<int>>vis2(n,vector<int>(m,0));
        for(int j=0; j<m; j++)
        {
            q2.push({n-1,j});
            vis2[n-1][j] = 1;
        }
        for(int i=0; i<n; i++)
        {
            q2.push({i,m-1});
            vis2[i][m-1] = 1;
        }
        process(q2,atlantic,vis2,hts);
        
        vector<vector<int>>ans;
        for(auto &vec: pacific)
        {
            if(atlantic.count(vec))
                ans.push_back(vec);
        }
        return ans;
        
        
    }
};
