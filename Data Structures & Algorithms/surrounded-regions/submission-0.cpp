class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        queue<vector<int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0; i<n; i++)
        {
            if(board[i][0]=='O')
            {
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(board[i][m-1]=='O')
            {
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }

        for(int j=1; j<m-1; j++)
        {
            if(board[0][j]=='O')
            {
                q.push({0,j});
                vis[0][j] = 1;
            }
            if(board[n-1][j]=='O')
            {
                q.push({n-1,j});
                vis[n-1][j] = 1;
            }
        }

        vector<vector<int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        set<vector<int>>st;

        while(!q.empty())
        {
            int x = q.front()[0] , y = q.front()[1];
            q.pop();
            st.insert({x,y});
            for(int k=0; k<4; k++)
            {
                int dx = x+dir[k][0] , dy = y+dir[k][1];
                if(dx>=0 and dx<n and dy>=0 and dy<m and board[dx][dy]=='O' and !vis[dx][dy])
                {
                    vis[dx][dy] = 1;
                    q.push({dx,dy});
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O' and !st.count({i,j}))
                    board[i][j] = 'X';
            }
        }


    }
};
