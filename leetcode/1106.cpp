class Solution {
public:
    char solveoperator(vector<char>& valus, char op) {
        if (op == '!') {
            return valus[0] == 't' ? 'f' : 't';
        }
        if (op == '&') {
            for (char& ch : valus) {
                if (ch == 'f') {
                    return 'f';
                }
            }
            return 't';
        }
        if (op == '|') {
            for (char& ch : valus) {
                if (ch == 't') {
                    return 't';
                }
            }
            return 'f';
        }
        return 't';
    }
    bool parseBoolExpr(string expression) {
        int n = expression.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (expression[i] == ',') {
                continue;
            }
            if (expression[i] == ')') {
                vector<char> value;
                while (st.top() != '(') {
                    value.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                st.push(solveoperator(value, op));
            } else {
                st.push(expression[i]);
            }
        }
        return st.top() == 't' ;
    }
};