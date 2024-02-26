class Solution {
public:
    bool canConstruct(const string& ransomNote,const  string& magazine) {
        auto stringHasher = [](string s) {
            unordered_map<char,int> m;
            for(auto& ch:m)
                m[ch]++;
            return m;
        }
        auto mag = stringHaster(magazine);
        for(auto& ch:ransomNote) {
            if(mag.find(ch) == mag.end() || mag[ch] == 0)
                return false;
            mag[ch]--;         
        }
        return true;
        
    }
};
