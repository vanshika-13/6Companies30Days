// Find total number of Squares in a N*N chessboard
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << ((n) * (n + 1) * (2 * n + 1)) / 6;
    return 0;
}