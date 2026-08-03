/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }

            else {
                if (st.empty()) {
                    return 0;
                } else if (s[i] == ')') {
                    if (st.top() != '(') {
                        return 0;
                    } else {
                        st.pop();
                    }
                } else if (s[i] == '}') {
                    if (st.top() != '{') {
                        return 0;
                    } else {
                        st.pop();
                    }
                } else {
                    if (st.top() != '[') {
                        return 0;
                    } else {
                        st.pop();
                    }
                }
            }
        }
        return st.empty();
    }
};
// @lc code=end

