class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) 
    {
        int n = arr.size();
        int totalSubsets = (1<<n);
        vector<vector<int>>ans;
        for(int num=0; num<totalSubsets; num++)
        {
            vector<int>subset;
            for(int i=0; i<n; i++)
            {
                if(num&(1<<i))
                    subset.push_back(arr[i]);
            }
            ans.push_back(subset);
        }
        return ans;
        
    }
};
