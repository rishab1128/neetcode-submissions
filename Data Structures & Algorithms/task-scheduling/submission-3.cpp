class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int>freq(26,0);
        for(auto &ele: tasks)
        {
            freq[ele-'A']++;
        }
        sort(freq.begin(), freq.end());
        int maxf = freq[25];
        int idle = (maxf - 1) * n;

        for (int i = 24; i >= 0; i--) {
            idle -= min(maxf - 1, freq[i]);
        }
        return max(0, idle) + tasks.size();
        
    }
};
