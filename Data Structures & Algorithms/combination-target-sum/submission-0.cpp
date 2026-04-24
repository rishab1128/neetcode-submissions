class Solution {
public:
    vector<vector<int>>ans;
    void recur(vector<int>&arr, int target, int idx, vector<int>soln)
    {
        if(target==0 && soln.size())
        {
            ans.push_back(soln);
            return;
        }
        if(idx==(int)arr.size())
            return;
        if(arr[idx]<=target)
        {
            soln.push_back(arr[idx]);
            recur(arr,target-arr[idx],idx,soln);
            soln.pop_back();
        }
        recur(arr,target,idx+1,soln);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) 
    {
        ans.clear();
        recur(arr,target,0,{});
        return ans;
    }
};
