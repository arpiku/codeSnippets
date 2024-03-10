class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty())
            return {};
        unordered_map<std::string,std::vector<std::string>> m;
        std::vector<std::vector<std::string>> res;
        for(auto& s:strs) {
            std::string s2 = s;
            std::sort(s2.begin(),s2.end());
            m[s2].push_back(s);
        }
        for(auto& i:m) {
            res.push_back(i.second);
        }
        return res;
    }
};
