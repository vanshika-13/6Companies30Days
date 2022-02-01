/*
Array Pair Sum Divisibility Problem
Easy Accuracy: 45.91% Submissions: 16106 Points: 2
Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.


Example 1 :

Input : arr = [9, 5, 7, 3], k = 6
Output: True
Explanation: {(9, 3), (5, 7)} is a
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.

Example 2:

Input : arr = [2, 4, 1, 3], k = 4
Output: False
Explanation: There is no possible solution.*/
#include <bits/stdc++.h>
using namespace std;
bool solve(vector<int> nums, int k)
{
    unordered_map<int, vector<int>> mp;
    for (auto it : nums)
    {
        mp[it % k].push_back(it);
    }
    for (auto it : mp)
    {
        if (it.first == 0)
        {
            if (it.second.size() % 2 != 0)
            {
                return false;
            }
        }
        else
        {
            if (mp.find(k - it.first) == mp.end())
            {
                return false;
            }
            if (it.second.size() != mp[k - it.first].size())
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    cout << solve(arr, k);
    return 0;
}