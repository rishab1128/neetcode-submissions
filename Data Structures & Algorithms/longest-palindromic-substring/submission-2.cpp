class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.size();
        int dp[n][n];
        //dp[i][j] -> lps starting at i and ending at j
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
        }
        
        int maxLen = 1;
        int start = 0;

        for(int i=n-1; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i==1 || dp[i+1][j-1]>0)
                        dp[i][j] = max(dp[i][j],2+dp[i+1][j-1]);
                }
                if(dp[i][j] > maxLen)
                {
                    maxLen = dp[i][j];
                    start = i;
                }
            }
        }

        string ans = s.substr(start,maxLen);
        return ans;
        
    }
};
