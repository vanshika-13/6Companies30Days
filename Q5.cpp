/*Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers.
By convention, 1 is included. Write a program to find Nth Ugly Number.
*/

// C++ program to find nth ugly number by brute force
/*#include <iostream>
using namespace std;

// This function divides a by greatest
// divisible power of b
int maxDivide(int a, int b)
{
    while (a % b == 0)
        a = a / b;

    return a;
}

// Function to check if a number is ugly or not
int isUgly(int no)
{
    no = maxDivide(no, 2);
    no = maxDivide(no, 3);
    no = maxDivide(no, 5);

    return (no == 1) ? 1 : 0;
}

// Function to get the nth ugly number
int getNthUglyNo(int n)
{
    int i = 1;

    // Ugly number count
    int count = 1;

    // Check for all integers until ugly
    // count becomes n
    while (n > count)
    {
        i++;
        if (isUgly(i))
            count++;
    }
    return i;
}

// Driver Code
int main()
{

    // Function call
    unsigned no = getNthUglyNo(150);
    cout << "150th ugly no. is " << no;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int UglyNo(int n)
{
    int c2 = 0, c3 = 0, c5 = 0;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 0; i <= n; i++)
    {
        dp[i] = min({2 * dp[c2], 3 * dp[c3], 5 * dp[c5]});
        if (dp[i] == 2 * dp[c2])
        {
            c2++;
        }
        if (dp[i] == 3 * dp[c3])
        {
            c3++;
        }
        if (dp[i] == 5 * dp[c5])
        {
            c5++;
        }
    }
    return dp[n - 1];
}
int main()
{
    int n;
    cin >> n;
    cout << UglyNo(n);
    return 0;
}