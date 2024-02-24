class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0)
            return true;
        if(t.size() == 0)
            return false;
        auto sItr = s.begin();
        auto tItr = t.begin();

        while(tItr != t.end()) {
            if(*sItr == *tItr) {
                sItr++;
                if(sItr == s.end())
                    return true;
            }
            tItr++;
        }
        return false;
    }
};
