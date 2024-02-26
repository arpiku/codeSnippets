class Solution {
public:
    int cs(std::unordered_map<int,int>& m, int n ){
        if(m.find(n) == m.end())   
            m[n] = cs(m,n-1) + cs(m,n-2);
        return m[n];
    }
    int climbStairs(int n) {
        if(n <=1)
            return 1;
        return cs(m,n);
    }
};

