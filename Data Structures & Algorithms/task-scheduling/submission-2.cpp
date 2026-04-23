class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        if(n==0){
            int sz = tasks.size();
            return sz;
        }

        unordered_map<char,int>mp;
        for(auto &task: tasks){
            mp[task]++;
        }
        auto cmp = [&](const char &task1, const char &task2){
            return mp[task1] < mp[task2];
        };
        priority_queue<char, vector<char>, decltype(cmp)>pq(cmp);
        for(auto &[ele, freq]:mp){
            pq.push(ele);
        }
        int time = 0;
        queue<pair<char,int>>q;
        while(pq.size() || q.size())
        {
            time++;

            if(pq.empty()){
                time = q.front().second;
            }else{
                char task = pq.top();
                pq.pop();
                mp[task]--;
                if(mp[task] > 0){
                    q.push({task,time+n});
                }
            }
            
            if(q.size() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
        
    }
};
