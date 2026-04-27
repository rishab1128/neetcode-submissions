class Solution {
public:
    string foreignDictionary(vector<string>& words) 
    {
        int n = words.size();
        unordered_map<char,int>indeg;
        unordered_map<char, unordered_set<char>> adj;

        for (string w : words) {
            for (char c : w) {
                adj[c] = unordered_set<char>();
                indeg[c] = 0;
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());
            if (w1.size() > w2.size() &&
                w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        indeg[w2[j]]++;
                    }
                    break;
                }
            }
        }

        queue<char>q;
        for (auto &[c, deg] : indeg) {
            if (deg == 0) {
                q.push(c);
            }
        }
        
        string ans = "";
        while(!q.empty())
        {
            char node = q.front();
            q.pop();
            ans += node;
            for(char neigh: adj[node])
            {
                indeg[neigh]--;
                if(indeg[neigh]==0)
                    q.push(neigh);
            }
        }
        return ans.size() == indeg.size() ? ans : "";
        
    }
};
