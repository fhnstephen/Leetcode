class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto& token : tokens) {
            if (token.length() == 1 && !isdigit(token[0])) {
                auto op = token[0];
                auto oper1 = s.top();
                s.pop();
                auto oper2 = s.top();
                s.pop();
                switch (op) {
                    case '+': oper2 += oper1; break;
                    case '-': oper2 -= oper1; break;
                    case '*': oper2 *= oper1; break;
                    case '/': oper2 /= oper1; break;
                }
                s.push(oper2);
            } else {
                s.push(stoi(token));
            }

        }
        return s.top();
    }
};
