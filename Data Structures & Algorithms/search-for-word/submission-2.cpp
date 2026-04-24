class Solution {
public:
    vector<vector<int>>dir;
    int n,m;
    bool found;
    void dfs(vector<vector<char>>& board, int i, int j, string& word, vector<vector<int>>vis, int idx)
    {
        if(idx==(int)word.size())
        {
            found = true;
            return;
        }
        
        for(int t=0; t<4; t++)
        {
            int x = i+dir[t][0] , y =j+dir[t][1];
            if(x>=0 and x<n and y>=0 and y<m and vis[x][y]==0 and board[x][y]==word[idx])
            {
                vis[x][y] = 1;
                dfs(board,x,y,word,vis,idx+1);
                vis[x][y] = 0;
            }
        }
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        dir={{1,0},{0,1},{-1,0},{0,-1}};
        n = board.size() , m = board[0].size();
        found = false;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]==word[0])
                {
                    vis[i][j] = 1;
                    dfs(board,i,j,word,vis,1);
                    vis[i][j] = 0;
                }
            }
        }
        return found;
        
    }
};
