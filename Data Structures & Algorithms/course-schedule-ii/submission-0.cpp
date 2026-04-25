class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {

        unordered_map<int,vector<int>>adj;
        vector<int>indeg(n,0);
        for(auto&vec: pre)
        {
            int v = vec[0], u = vec[1];
            adj[u].push_back(v);
            indeg[v]++; 
        }
        queue<int>q;
        for(int i=0; i<n; i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        vector<int>ans;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for(auto& neigh: adj[node])
                {
                    indeg[neigh]--;
                    if(indeg[neigh]==0)
                        q.push(neigh);
                }
            }
        }
        if((int)ans.size()!=n)
            return {};
        return ans;
    }
};
