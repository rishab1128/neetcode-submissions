class Solution {
public:
    int n;
    unordered_set<string>dict;
    int dp[201];
    int recur(string s, int idx)
    {
        if(idx >= n)
            return true;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans = 0;
        for(int len=1; len <= n-idx; len++)
        {
            string str = s.substr(idx,len);
            if(dict.count(str))
                ans = ans | recur(s,idx+len);
        }
        return dp[idx] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0; i<201; i++)
        {
            dp[i] = -1;
        }
        n = s.size();
        for(auto&ele: wordDict)
            dict.insert(ele);
        int ans = recur(s,0);
        return (bool)ans;
    }
};
