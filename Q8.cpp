/*A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded, as the answer can be large return the answer modulo 109 + 7.
Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and If there are leading 0’s, extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.

Example 1:

Input: str = "123"
Output: 3
Explanation: "123" can be decoded as "ABC"(123),
"LC"(12 3) and "AW"(1 23).
Example 2:

Input: str = "27"
Output: 1
Explanation: "27" can be decoded as "BG".*/

#include <bits/stdc++.h>
#include <string.h>
using namespace std;

void printAllPossibleCodes(string input, string output)
{
    // Base Case
    if (input.empty())
    {
        cout << output << endl;
        return;
    }

    char c1 = input[0] - '0' + 'A' - 1;
    int b = stoi(input.substr(0, 2));
    char c2 = b - 1 + 'A';
    printAllPossibleCodes(input.substr(1), output + c1);
    if (b >= 10 && b <= 26)
    {
        printAllPossibleCodes(input.substr(2), output + c2);
    }
}

void printAllPossibleCodes(string input)
{
    string output = "";
    printAllPossibleCodes(input, output);
}

int main()
{
    string s;
    cin >> s;
    printAllPossibleCodes(s);
    return 0;
}