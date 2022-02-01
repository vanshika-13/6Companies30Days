/*Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given
string. eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.You are required to
complete the function encode that takes only one argument the string which is to be encoded and returns the encoded string.
*/
#include <bits/stdc++.h>
using namespace std;
void striNum(string s)
{
    int n = s.length();
    int ansIndex = 0;
    int i = 0;
    while (i < n)
    {
        int j = i + 1;
        while (j < n && s[j] == s[i])
        {
            j++;
        }
        s[ansIndex++] = s[i];
        int count = j - i;
        string cnt = to_string(count);
        for (auto i : cnt)
        {
            s[ansIndex++] = i;
        }
        i = j;
    }
    // vector<char> ans;
    for (int k = 0; k < ansIndex; k++)
    {
        cout << s[k];
    }
}
int main()
{
    string s;
    getline(cin, s);
    striNum(s);
    return 0;
}
