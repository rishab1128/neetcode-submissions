class Solution {
public:
    vector<string>ans;
    void recur(int n, string soln, int op, int cl)
    {
        if(op==n&&cl==n)
        {
            ans.push_back(soln);
            return;
        }
        if(op < n)
        {
            soln.push_back('(');
            recur(n,soln,op+1,cl);
            soln.pop_back();
        }
        if(op>cl)
        {
            soln.push_back(')');
            recur(n,soln,op,cl+1);
            soln.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        recur(n,"",0,0);
        return ans;
    }
};
