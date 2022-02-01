/*Distributing M items in a circle of size N starting from K-th position
Difficulty Level : Easy
Last Updated : 01 Apr, 2021
M items are to be delivered in a circle of size N. Find the position where the M-th item will be delivered if we start from a given position K. Note that items are distributed at adjacent positions starting from K.
Examples :


Input : N = 5 // Size of circle
        M = 2 // Number of items
        K = 1 // Starting position
Output : 2
The first item will be given to 1st
position. Second (or last) item will
be delivered to 2nd position

Input : N = 5
        M = 8
        K = 2
Output : 4
The last item will be delivered to
4th position*/
#include <bits/stdc++.h>
using namespace std;
int solve(int n, int m, int k)
{
    return (m + k - 1) % n;
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    cout << solve(n, m, k);
    return 0;
}