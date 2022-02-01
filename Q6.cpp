/*For two strings s and t,
we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"*/
#include <bits/stdc++.h>
using namespace std;
string gcdOfStrings(string s, string t)
{
    int n1 = s.size();
    int n2 = t.size();
    if (s + t == t + s)
    {
        return s.substr(0, __gcd(n1, n2));
    }
    return "";
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << gcdOfStrings(str1, str2);
    return 0;
}