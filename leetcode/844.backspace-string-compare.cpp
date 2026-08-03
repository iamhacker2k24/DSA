/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        for (int i = 0; i < s.size(); i++) {
            if (s1.empty()) {
                if (s[i] == '#') {
//leave this empty 
                } else {
                    s1.push(s[i]);
                }
            } else if (s[i] == '#') {
                s1.pop();

            } else {
                s1.push(s[i]);
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (s2.empty()) {
                if (t[i] == '#') {

                } else {
                    s2.push(t[i]);
                }

            } else if (t[i] == '#') {
                s2.pop();

            } else {
                s2.push(t[i]);
            }
        }
        if (s1.size() != s2.size()) {
            return 0;
        }
        while (!s1.empty()) {
            if (s1.top() != s2.top()) {
                return 0;
            }
            s1.pop();
            s2.pop();
        }
        return 1;
    }
};
// @lc code=end

