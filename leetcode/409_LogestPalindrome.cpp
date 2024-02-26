
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        int odd = 0;
        for(auto& ch:s) {
            map[ch]++;
            if(map[ch]%2 == 1) 
                odd++;
            else
                odd--;
        }
        if(odd>1)
            return s.size()-odd+1;
        return s.size();
        
    }
};
