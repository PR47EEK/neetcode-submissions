class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto x : s) {
            if(stk.empty()) stk.push(x);
            else if((stk.top() == '(' && x == ')') || (stk.top() == '{' && x == '}') || 
            (stk.top() == '[' && x == ']')) stk.pop();
            else stk.push(x);
        }
        return stk.empty();
    }
};
