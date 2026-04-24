class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrome(string s)
    {
        string t = s;
        reverse(s.begin(),s.end());
        return s==t;
    }
    void recur(string s, vector<string>soln)
    {
        if(s.size()==0)
        {
            ans.push_back(soln);
            return;
        }
        for(int len=1; len<=(int)s.size(); len++)
        {
            string sub = s.substr(0,len);
            if(isPalindrome(sub))
            {
                soln.push_back(sub);
                recur(s.substr(len),soln);
                soln.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ans.clear();
        recur(s,{});
        return ans;
    }
};
