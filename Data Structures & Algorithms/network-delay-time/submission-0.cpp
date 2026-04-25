class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &vec: times)
        {
            int u = vec[0]-1, v = vec[1]-1, dist = vec[2];
            adj[u].push_back({v,dist});
        }

        vector<int>dist(n);
        for(int i=0; i<n; i++)
            dist[i] = 1e9;

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<>>pq;

        pq.push({0,k-1}); //{dist,source node}
        dist[k-1] = 0;

        while(!pq.empty())
        {
            int d = pq.top().first , node = pq.top().second;
            pq.pop();
            // cout<<"Node = "<<node<<" Dist =  "<<d<<endl;
            for(auto &neigh: adj[node])
            {
                int neighNode = neigh.first , neighDist = neigh.second;
                if(d+neighDist < dist[neighNode]){
                    dist[neighNode] = d+neighDist;
                    pq.push({dist[neighNode], neighNode});
                }
            }
        }

        int ans = -1;
        for(int i=0; i<n; i++)
        {
            if(dist[i]==1e9)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
        
    }
};
