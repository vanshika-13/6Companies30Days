/*Given an array of positive integers nums and a positive integer target,
return the minimal length of a contiguous subarray [numsl, numsl+1, ...,
numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> nums, int n, int target, int s, int end)
{
    int sum = 0, minlen = n - 1;
    while (end < n)
    {
        while ((sum < target) && (end < n))
        {
            sum += nums[end++];
        }
        while ((sum >= target) && (s < n))
        {
            if ((end - s) < minlen)
            {
                minlen = end - s;
            }
            sum -= nums[s++];
        }
    }
    return minlen;
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    cout << solve(nums, n, target, 0, 0);
    return 0;
}