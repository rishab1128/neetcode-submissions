class Solution {
public:
    vector<vector<int>>dir;
    int n,m;
    bool found;
    void dfs(vector<vector<char>>& board, int i, int j, string& word, int idx)
    {
        if(idx==(int)word.size())
        {
            found = true;
            return;
        }
        
        for(int t=0; t<4; t++)
        {
            int x = i+dir[t][0] , y =j+dir[t][1];
            if(x>=0 and x<n and y>=0 and y<m and board[x][y]==word[idx])
            {
                char ch = board[x][y];
                board[x][y] = '#';
                dfs(board,x,y,word,idx+1);
                board[x][y] = ch;
            }
        }
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        dir={{1,0},{0,1},{-1,0},{0,-1}};
        n = board.size() , m = board[0].size();
        found = false;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]==word[0])
                {
                    char ch = board[i][j];
                    board[i][j] = '#';
                    dfs(board,i,j,word,1);
                    board[i][j] = ch;
                }
            }
        }
        return found;
        
    }
};
