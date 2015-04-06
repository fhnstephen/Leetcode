class Solution {
public:
    bool isValid(string s) {
        for (auto& x : s) {
            if (x == '(' || x == '[' || x == '{')
                stack_.push(x);
            if (x == ')' || x == ']' || x == '}') {
                if (stack_.empty()) return false;
                char top = stack_.top();
                if (top == x-1 || top == x - 2)
                    stack_.pop();
                else
                    break;
            }
        }
        return stack_.empty();
    }
private:
    stack<char> stack_;
};
