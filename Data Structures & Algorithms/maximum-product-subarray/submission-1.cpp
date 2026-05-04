class Solution {
public:
    int maxProduct(vector<int>& arr) 
    {
        int n = arr.size();
        int dp[n][n];
        //dp[i][j] -> product starting at i and ending at j
        int ans = INT_MIN;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=i; j<n; j++){
                if(j==i){
                    dp[i][j] = arr[i];
                }else{
                    dp[i][j] = arr[i]*dp[i+1][j];
                }
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};
