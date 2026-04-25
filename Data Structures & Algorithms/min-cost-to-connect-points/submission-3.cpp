struct CustomPoint {
    int weight;
    pair<int, int> p1;
    pair<int, int> p2;
};
class Solution {
   public:
    map<pair<int, int>, pair<int, int>> par;
    pair<int, int> findPar(pair<int, int> u) {
        if (par[u] == u) return u;
        return findPar(par[u]);
    };
    int minCostConnectPoints(vector<vector<int>>& points) {
        // KRUSKAL'S ALGO
        /*

        1) SORT ALL EDGES ACC TO WEIGHT
        2) ADD EDGES USING DSU
        3) ADD AN EDGE (U,V) ONLY IF findPar(U)!=findPar(V)
        3.1) ADD THE WEIGHT OF THE (ADDED) EDGE TO THE ANSWER

        */
        int n = points.size();
        par.clear();
        vector<CustomPoint> edges;
        for (int i = 0; i < n; i++) {
            pair<int, int> u = make_pair(points[i][0], points[i][1]);
            par[u] = u;
            for (int j = i + 1; j < n; j++) {
                pair<int, int> v = make_pair(points[j][0], points[j][1]);
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, u, v});
            }
        }
        sort(edges.begin(), edges.end(),
             [](const CustomPoint& a, const CustomPoint& b) { return a.weight < b.weight; });

        int ans = 0,cnt=0;

        for (int i = 0; i < edges.size(); i++) {
            CustomPoint pt = edges[i];
            int wt = pt.weight;
            auto u = pt.p1;
            auto v = pt.p2;

            // cout<<wt<<" "<<"("<<u.first<<","<<u.second<<") "<<"("<<v.first<<","<<v.second<<")"<<endl; 

            auto parU = findPar(u);
            auto parV = findPar(v);

            if (parU!=parV && cnt<n-1) {
                par[parV] = parU;
                ans += wt;
                cnt++;
            }
        }
        return ans;
    }
};
