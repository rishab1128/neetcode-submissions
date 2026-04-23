class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto cmp = [](const vector<int>& a, const vector<int>& b){

            int distA = a[0]*a[0] + a[1]*a[1];
            int distB = b[0]*b[0] + b[1]*b[1];

            return distA < distB;
        };

        auto findDist = [](const vector<int>& point){
            int dist = point[0]*point[0] + point[1]*point[1];
            return dist;
        };

        priority_queue<vector<int> , vector<vector<int>>, decltype(cmp)>pq(cmp);

        for(auto &vec: points){
            if(pq.size() < k)
                pq.push(vec);
            else{
                int dist1 = findDist(vec);
                int dist2 = findDist(pq.top());
                if(dist1 < dist2)
                {
                    pq.pop();
                    pq.push(vec);
                }
            }
        }

        vector<vector<int>>ans;
        while(pq.size()){
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
        
    }
};
