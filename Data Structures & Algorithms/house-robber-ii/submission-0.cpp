class Solution {
public:
    int recur(vector<int>&arr, int idx, vector<vector<int>>&dp, int flag)
    {
        if(flag && idx >= arr.size()-1)
            return 0;
        if(!flag && idx >= arr.size())
            return 0;

        if(dp[idx][flag]!=0)
            return dp[idx][flag];

        int op1=0,op2=0;
        if(idx==0)
        {
            op1 = arr[idx] + recur(arr,idx+2,dp,1);
            op2 = recur(arr,idx+1,dp,0);
        }else{
            op1 = arr[idx] + recur(arr,idx+2,dp,flag);
            op2 = recur(arr,idx+1,dp,flag);
        }

        return dp[idx][flag] = max(op1,op2);
    }
    int rob(vector<int>& arr) 
    {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(2,0));
        int ans = recur(arr,0,dp,0);
        return ans;
    }
};
