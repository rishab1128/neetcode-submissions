class Solution {
public:
    int recur(vector<int>&arr, int idx, vector<int>&dp)
    {
        if(idx >= arr.size())
            return 0;

        if(dp[idx]!=-1)
            return dp[idx];

        int op1 = arr[idx] + recur(arr,idx+2,dp);
        int op2 = recur(arr,idx+1,dp);

        return dp[idx] = max(op1,op2);
    }
    int rob(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int>dp(n);
        for(int i=0; i<n; i++)
            dp[i] = -1;
        int ans = recur(arr,0,dp);
        return ans;
    }
};
