class Solution {
   public:
    vector<string> recur(string digits, map<char, vector<string>>& mp) {
        if(digits.size()==1)
        {
            return mp[digits[0]];
        }
        char ch = digits[0];
        vector<string> futureAns = recur(digits.substr(1),mp);
        vector<string>ans;
        for(auto&ele: mp[ch])
        {
            for(auto&str: futureAns){
                string newStr = ele+str;
                ans.push_back(newStr);
            }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {

        if(digits.size()==0)
            return {};
        
        map<char, vector<string>> mp;
        mp['2'] = {"a", "b", "c"};
        mp['3'] = {"d", "e", "f"};
        mp['4'] = {"g", "h", "i"};
        mp['5'] = {"j", "k", "l"};
        mp['6'] = {"m", "n", "o"};
        mp['7'] = {"p", "q", "r", "s"};
        mp['8'] = {"t", "u", "v"};
        mp['9'] = {"w", "x", "y", "z"};

        return recur(digits, mp);
    }
};
