class Solution {
public:
    bool isNum(const std::string& s) {
    std::istringstream ss(s);
    double num;
    return (ss >> num) && ss.eof();
    }

    int calc(std::stack<int>& s, std::string op) {
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();
        if(op == "*")
            return b*a;
        if(op == "/")
            return b/a;
        if(op == "-")
            return b-a;
        if(op == "+")
            return b+a;
        return 0;
    }


    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;

        for(auto& s:tokens) {
            if(isNum(s)) {
                stk.push(atoi(s.c_str()));
            }
            else {
                stk.push(calc(stk, s));
            }

        }
        return stk.top();
        
    }
};
