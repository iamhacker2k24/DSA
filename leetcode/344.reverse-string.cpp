/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start

// reverse string by stack
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        //using  stack
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            st.push(s[i]);
        }
        int i=0;
        while (!st.empty())
        {
            s[i] = st.top();
            i++;
            st.pop();
        }
    }
};
// @lc code=end
