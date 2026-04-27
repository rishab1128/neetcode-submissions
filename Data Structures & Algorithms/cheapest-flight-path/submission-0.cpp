class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst, int k) {

        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto&flight: arr)
        {
            int u = flight[0] ,  v = flight[1], wt = flight[2];
            adj[u].push_back({v,wt});
        }
        const int INF = 1e9;
        vector<vector<int>>dist(n,vector<int>(k+1));
        for(int i=0; i<n; i++){
            for(int j=0; j<k+1; j++){
                dist[i][j] = INF;
            }
        }
            

        priority_queue<vector<int> , vector<vector<int>>, greater<>>pq;
        pq.push({0,src,0}); //{wt,node,stops}
        dist[src][0] = 0;
        int ans = INF;
        while(!pq.empty())
        {
            auto vec = pq.top();
            pq.pop();
            int wt = vec[0], node = vec[1], stops = vec[2];
            if(stops<=k+1 and node==dst)
            {
                ans = min(ans,wt);
            }
            for(auto&[neighNode, neighDist]: adj[node])
            {
                if(stops<=k and dist[neighNode][stops] > wt + neighDist)
                {
                    dist[neighNode][stops] = wt + neighDist;
                    pq.push({dist[neighNode][stops], neighNode, stops+1});
                }
            }
        }
        return ans==INF ? -1 : ans;
    }
};
