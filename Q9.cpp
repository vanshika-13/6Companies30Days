/*Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat.

Example 1:
Input:
D
Output:
21

Explanation:
D is meant for decreasing,
So we choose the minimum number
among 21,31,54,87,etc.*/

#include <bits/stdc++.h>
using namespace std;
string solve(string s)
{
    string ans;
    int n = s.length();
    stack<int> st;
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'D')
        {
            st.push(num);
            num++;
        }
        else
        {
            st.push(num);
            num++;
            while (st.size() > 0)
            {
                int k = st.top();
                st.pop();
                char ch = k + '0';
                ans.push_back(ch);
            }
        }
    }
    st.push(num);
    while (st.size() > 0)
    {
        int k = st.top();
        st.pop();
        char ch = k + '0';
        ans.push_back(ch);
    }
    return ans;
}
int main()
{
    string s;
    cin >> s;
    string ans = solve(s);
    cout << ans;
    return 0;
}