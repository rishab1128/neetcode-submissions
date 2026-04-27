class Solution {
public:
    string foreignDictionary(vector<string>& words) 
    {
        int n = words.size();
        unordered_set<char>allLetters;
        unordered_map<char,int>indeg;
        unordered_map<char,vector<char>>adj;
        for(int i=0; i<n-1; i++)
        {
            string w1 = words[i];
            string w2 = words[i+1];
            bool flag = false;
            for(int j=0; j<min((int)w1.size() , (int)w2.size()); j++)
            {
                if(!flag and w1[j]!=w2[j])
                {
                    adj[w1[j]].push_back(w2[j]);
                    indeg[w2[j]]+=1;
                    flag = true;
                }
                allLetters.insert(w1[j]);
            }
            if((int)w2.size() < (int)w1.size() and !flag)
                return "";
        }
        for(auto&ch: words[n-1])
            allLetters.insert(ch);

        queue<char>q;
        for(auto&ch: allLetters)
        {
            if(indeg[ch]==0)
            {
                q.push(ch);
            }
        }
        string ans = "";
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            ans += node;
            for(auto&neigh: adj[node])
            {
                indeg[neigh]--;
                if(indeg[neigh]==0)
                    q.push(neigh);
            }
        }
        return ans.size()==allLetters.size() ? ans : "";
        
    }
};
