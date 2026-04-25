class Solution {
public:
    unordered_map<string, multiset<string>>adj;
    vector<string>path;

    void heirholzerDFS(string node)
    {
        while(!adj[node].empty())
        {
            auto it = adj[node].begin();
            string next = *it;
            adj[node].erase(it);
            heirholzerDFS(next);
        }
        path.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        adj.clear();
        path.clear();

        for(auto&ticket: tickets)
        {
            string u = ticket[0], v = ticket[1];
            adj[u].insert(v);
        }

        heirholzerDFS("JFK");

        reverse(path.begin(),path.end());

        return path;
        
    }
};
