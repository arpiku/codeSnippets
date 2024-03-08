class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx = 0;
        int n = needle.size();
        while(idx + n - 1 < haystack.size()) {
            if(needle == std::string(haystack.begin()+idx, haystack.begin()+idx+n))
                return idx;
            idx++;
        }
        return -1;  
    }
};

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length(), h = haystack.length();
        if (n > h) 
            return -1;
        for (int i = 0; i <= h - n; i++) {
            if (haystack.substr(i, n) == needle) return i;
        }
        return -1;
    }
};
