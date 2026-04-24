class Solution {
public:
    vector<vector<int>>ans;
    void recur(vector<int>&arr, int target, int idx, vector<int>soln)
    {
        if(target==0)
        {
            ans.push_back(soln);
            return;
        }
        for(int i=idx; i<(int)arr.size(); i++)
        {
            if(i>idx && arr[i]==arr[i-1])
                continue;
            if(arr[i]<=target)
            {
                soln.push_back(arr[i]);
                recur(arr,target-arr[i],i+1,soln);
                soln.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        ans.clear();
        sort(arr.begin(),arr.end());
        recur(arr,target,0,{});
        return ans;
    }
};
