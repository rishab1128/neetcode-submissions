class Solution {
public:
    void dfs(int node, vector<int>&vis, unordered_map<int,vector<int>>&adj)
    {
        vis[node] = 1;
        for(auto &neigh: adj[node])
        {
            if(!vis[neigh])
                dfs(neigh,vis,adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {

        unordered_map<int,vector<int>>adj;
        for(auto &edge: edges)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);
        int cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,adj);
                cnt++;
            }
        }
        return cnt;
    }
};
