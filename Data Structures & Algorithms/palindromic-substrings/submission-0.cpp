class Solution {
public:
    int countSubstrings(string s) {

        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        //dp[i][j] ->says whether s[i...j] is a palinfromic substring or not
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    dp[i][j] = 1;
            }
        }
        int ans = n;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i==1 || dp[i+1][j-1]){
                        dp[i][j] = 1;
                        ans++;
                    }
                }
            }
        }
        return ans;
        
        
    }
};