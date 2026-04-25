class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();
        map<pair<int,int> , vector<vector<int>>>adj;
        for(int i=0; i<n; i++)
        {
            pair<int,int> u = make_pair(points[i][0], points[i][1]);
            for(int j=i+1; j<n; j++)
            {
                pair<int,int> v = make_pair(points[j][0], points[j][1]);
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[u].push_back({points[j][0], points[j][1], dist});
                adj[v].push_back({points[i][0], points[i][1], dist});
            }
        }

        //PRIM'S ALGO
        priority_queue<vector<int> , vector<vector<int>>, greater<>>minHeap; //{wt,nodeX,nodeY}
        minHeap.push({0,points[0][0],points[0][1]});
        map<pair<int,int>,int>vis;
        int sum = 0;
        while(!minHeap.empty())
        {
            vector<int> top = minHeap.top();
            minHeap.pop();
            int wt = top[0] , nodeX = top[1], nodeY = top[2];
            pair<int,int> node = {nodeX,nodeY};
            if(vis[node])
                continue;
            vis[node] = 1;
            sum += wt;
            for(auto &neigh: adj[node])
            {
                int neighX = neigh[0] , neighY = neigh[1], dist = neigh[2];
                pair<int,int> neighNode = {neighX, neighY};
                if(!vis[neighNode])
                {
                    minHeap.push({dist, neighX, neighY});
                }
            }
        }

        return sum;
        
    }
};
