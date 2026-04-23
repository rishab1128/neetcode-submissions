class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int>pq;
        for(auto &x: stones){
            pq.push(x);
        }
        int ans = 0;
        while(pq.size())
        {            
            int x1 = pq.top();
            pq.pop();
            if(pq.size())
            {
                int x2 = pq.top();
                pq.pop();
                if(x1 > x2)
                    pq.push(x1-x2);
            }else{
                ans = x1;
            }
        }
        return ans;
    }
};
