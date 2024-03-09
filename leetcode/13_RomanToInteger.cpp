class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        stack<char> stack;
        unordered_map<char,int> rti = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        for(auto& ch:s) {
            if(!stack.empty() &&rti[stack.top()] < rti[ch] ) {
                res += (rti[ch] - rti[stack.top()]);
                stack.pop();
                continue;
            }
            stack.push(ch);
        } 

        while(!stack.empty()) {
            res += rti[stack.top()];
            stack.pop();
        }
        return res;
    }
};
