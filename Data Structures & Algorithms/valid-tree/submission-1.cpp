class Solution {
public:
    bool cycle = false;
    void detectCycle(int node, int par, unordered_map<int,vector<int>>&adj, vector<int>&vis)
    {
        vis[node] = 1;
        for(auto &child: adj[node])
        {
            if(!vis[child])
                detectCycle(child,node,adj,vis);
            else
            {
                if(child!=par)
                {
                    cycle = true;
                    return;
                }
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {

        unordered_map<int,vector<int>>adj;
        for(auto &edge: edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        detectCycle(0,-1,adj,vis);
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
                return false;
        }
        if(cycle)
            return false;

        return true;

    }
};
