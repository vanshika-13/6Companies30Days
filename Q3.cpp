// Q3 -> Given an array of positive numbers,
// the task is to find the number of possible contiguous subarrays having product less than a given number k.

#include <bits/stdc++.h>
using namespace std;
// naive approach -> counting product of all subarrays and then increasing count accordingly
/*int productLessThanK(vector<int> a, int n, long long k)
{
    long long mul = 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < k)
        {
            count++;
        }
        mul = a[i];
        for (int j = i + 1; j < n; j++)
        {
            mul = mul * a[j];
            if (mul < k)
            {
                count++;
            }
            else
            {
                break;
            }
        }
    }
    return count;
}*/

/*We can optimized approach is based on sliding window technique (Note that we need to find contiguous parts)
Firstly, according to the description, all elements in the array are strictly positive. Also let’s assume that the product of all array elements always fits in 64-bit integer type. Taking these two points into consideration, we are able to multiply and divide array’s elements safety (no division by zero, no overflows).

Let’s see how to count the desired amount. Assume, we have a window between start and end, and the product of all elements of it is p < k. Now, let’s try to add a new element x. There are two possible cases.

Case 1. p*x < k
This means we can move the window’s right bound one step further. How many contiguous arrays does this step produce? It is: 1 + (end-start).
Indeed, the element itself comprises an array, and also we can add x to all contiguous arrays which have right border at end. There are as many such arrays as the length of the window.

Case 2. p*x >= k
This means we must first adjust the window’s left border so that the product is again less than k. After that, we can apply the formula from Case 1.*/

int productLessThanK(vector<int> a, int n, long long k)
{
    long long p = 1;
    int res = 0;
    for (int start = 0, end = 0; end < n; end++)
    {
        p *= a[end];
        while (start < end && p >= k)
            p /= a[start++];

        if (p < k)
        {
            int len = end - start + 1;
            res += len;
        }
    }

    return res;
}
int main()
{
    int n;
    cin >> n;
    long long k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << productLessThanK(a, n, k);
    return 0;
}