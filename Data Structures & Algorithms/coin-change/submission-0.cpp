class Solution {
public:
    long long recur(vector<int>&coins, int amt, int idx, vector<vector<long long>>&dp)
    {   
        if(amt > 0 and idx >= (int)coins.size())
            return INT_MAX;
        if(amt==0)
            return 0;
        if(dp[idx][amt]!=INT_MAX)
            return dp[idx][amt];
        long long op1 = INT_MAX, op2 = INT_MAX;
        if(coins[idx]<=amt)
            op1 = 1+recur(coins,amt-coins[idx],idx,dp);
        op2 = recur(coins, amt, idx+1,dp);
        return dp[idx][amt] = min(op1,op2);
    }
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        vector<vector<long long>>dp(n, vector<long long>(amount+1));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=amount; j++)
                dp[i][j] = INT_MAX;
        }

        long long ans = recur(coins,amount,0,dp);
        if(ans == INT_MAX)
            return -1;
        return (int)ans;
    }
};
