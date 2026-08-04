/*
 * @lc app=leetcode id=946 lang=cpp
 *
 * [946] Validate Stack Sequences
 */

// @lc code=start
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        int i = 0, j = 0, m = pushed.size();
        while (i < m && j < m)
        {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[j]){
                st.pop();
                j++;
            }
            i++;
        }
        return st.empty();
    }
};
// @lc code=end
