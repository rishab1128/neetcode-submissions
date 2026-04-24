class Solution {
public:
    vector<vector<int>>ans;
    void recur(vector<int>&arr, int idx, vector<int>subset)
    {
        ans.push_back(subset);
        for(int i=idx; i<(int)arr.size(); i++)
        {
            if(i>idx && arr[i]==arr[i-1])
                continue;
            subset.push_back(arr[i]);
            recur(arr,i+1,subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        ans.clear();
        sort(arr.begin(),arr.end());
        recur(arr,0,{});
        return ans;
    }
};
