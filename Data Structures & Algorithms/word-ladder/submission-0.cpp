class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string>st;
        for(auto&word: wordList)
            st.insert(word);

        queue<pair<string,int>>q;
        unordered_map<string,int>vis;
        q.push({beginWord,1});
        vis[beginWord] = 1;

        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                string node = q.front().first;
                int dist = q.front().second;
                q.pop();

                if(node==endWord)
                    return dist;

                for(int i=0; i<(int)node.size(); i++)
                {
                    string tmp = node;
                    for(char ch='a'; ch<='z'; ch++)
                    {
                        if(ch!=tmp[i])
                        {
                            tmp[i] = ch;
                            if(st.count(tmp) and !vis.count(tmp)){
                                q.push({tmp,dist+1});
                                vis[tmp] = 1;
                            }
                        }
                    }
                }
            }
        }
        return 0;
        
    }
};
