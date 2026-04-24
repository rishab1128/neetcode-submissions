class Solution {
public:
    vector<vector<int>>ans;
    void recur(vector<int>&arr, vector<int>soln, vector<bool>vis)
    {
        if(soln.size()==arr.size())
        {
            ans.push_back(soln);
            return;
        }
        for(int i=0; i<(int)arr.size(); i++)
        {
            if(!vis[i])
            {
                soln.push_back(arr[i]);
                vis[i] = true;
                recur(arr,soln,vis);
                vis[i] = false;
                soln.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& arr) 
    {
        ans.clear();
        int n = arr.size();
        vector<bool>vis(n,false);
        recur(arr,{},vis);
        return ans;
    }
};
