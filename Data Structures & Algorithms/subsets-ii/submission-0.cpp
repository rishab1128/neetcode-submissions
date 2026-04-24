class Solution {
public:
    vector<vector<int>>ans;
    void recur(vector<int>&arr, int idx, vector<int>subset, int subsetSize)
    {
        if(subset.size()==subsetSize)
        {
            ans.push_back(subset);
            return;
        }
        for(int i=idx; i<(int)arr.size(); i++)
        {
            if(i>idx && arr[i]==arr[i-1])
                continue;
            if(subset.size() < subsetSize)
            {
                subset.push_back(arr[i]);
                recur(arr,i+1,subset,subsetSize);
                subset.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        ans.clear();
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i=0; i<=n; i++)
        {
            recur(arr,0,{},i);
        }
        return ans;
    }
};
