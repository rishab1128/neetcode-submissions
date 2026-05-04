class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int dp[105];
    int func(string s, int n)
    {
        if(s[0]=='0')
            return 0;
        if(s.size()==1||s.size()==0)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        string t=s.substr(0,2);
        int num=stoi(t);
        string rest1=s.substr(1);
        if(num<=26)
        {
            string rest2=s.substr(2);
            return dp[n]=func(rest1,n-1)+func(rest2,n-2);
        }
        return dp[n]=func(rest1,n-1);
    }
    
    int numDecodings(string s) 
    {
        for(int i=0; i<105; i++)
            dp[i] = -1;
        int n=s.size();
        int ans=func(s,n);
        return ans;
    }
};