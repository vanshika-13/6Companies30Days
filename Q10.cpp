/*Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and
smallest positive missing number is 1.*/
Method 1 (Use Sorting)
Approach::
Sort the input array.
Traverse the array and check for missing and repeating.
Time Complexity: O(nLogn)

Thanks to LoneShadow for suggesting this method.

Method 2 (Use count array)
Approach: 

Create a temp array temp[] of size n with all initial values as 0.
Traverse the input array arr[], and do following for each arr[i] 
if(temp[arr[i]] == 0) temp[arr[i]] = 1;
if (temp[arr[i]] == 1) output “arr[i]” //repeating
Traverse temp[] and output the array element having value as 0 (This is the missing element)
Time Complexity: O(n)

Auxiliary Space: O(n)

Method 3 (Use elements as Index and mark the visited places)
Approach: 
Traverse the array. While traversing, use the absolute value of every element as an index and make the value at this index as negative to mark it visited. If something is already marked negative then this is the repeating element. To find missing, traverse the array again and look for a positive value.

    // C++ program to Find the repeating
    // and missing elements

#include <bits/stdc++.h>
using namespace std;

void printTwoElements(int arr[], int size)
{
    int i;
    cout << " The repeating element is ";

    for (i = 0; i < size; i++)
    {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << abs(arr[i]) << "\n";
    }

    cout << "and the missing element is ";
    for (i = 0; i < size; i++)
    {
        if (arr[i] > 0)
            cout << (i + 1);
    }
}

/* Driver code */
int main()
{
    int arr[] = {7, 3, 4, 5, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    printTwoElements(arr, n);
}

// This code is contributed by Shivi_Aggarwal
Output
 The repeating element is 5
and the missing element is 1
Time Complexity: O(n)
Thanks to Manish Mishra for suggesting this method. 

Method 4 (Make two equations)
Approach:

Let x be the missing and y be the repeating element.
Get the sum of all numbers using formula S = n(n+1)/2 – x + y
Get product of all numbers using formula P = 1*2*3*…*n * y / x
The above two steps give us two equations, we can solve the equations and get the values of x and y.
Time Complexity: O(n)
Thanks to disappearedng for suggesting this solution. 

Note: This method can cause arithmetic overflow as we calculate product and sum of all array elements.

Method 5 (Use XOR)

Approach:

Let x and y be the desired output elements.
Calculate XOR of all the array elements.
xor1 = arr[0]^arr[1]^arr[2]…..arr[n-1]

XOR the result with all numbers from 1 to n
xor1 = xor1^1^2^…..^n

In the result xor1, all elements would nullify each other except x and y. All the bits that are set in xor1 will be set in either x or y. So if we take any set bit (We have chosen the rightmost set bit in code) of xor1 and divide the elements of the array in two sets – one set of elements with same bit set and other set with same bit not set. By doing so, we will get x in one set and y in another set. Now if we do XOR of all the elements in first set, we will get x, and by doing same in other set we will get y. 
 
Below is the implementation of the above approach:

// C++ program to Find the repeating
// and missing elements

#include <bits/stdc++.h>
using namespace std;

/* The output of this function is stored at
 *x and *y */
void getTwoElements(int arr[], int n,
                    int *x, int *y)
{
    /* Will hold xor of all elements
    and numbers from 1 to n */
    int xor1;

    /* Will have only single set bit of xor1 */
    int set_bit_no;

    int i;
    *x = 0;
    *y = 0;

    xor1 = arr[0];

    /* Get the xor of all array elements */
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];

    /* XOR the previous result with numbers
    from 1 to n*/
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;

    /* Get the rightmost set bit in set_bit_no */
    set_bit_no = xor1 & ~(xor1 - 1);

    /* Now divide elements into two
    sets by comparing a rightmost set
    bit of xor1 with the bit at the same
    position in each element. Also,
    get XORs of two sets. The two
    XORs are the output elements.
    The following two for loops
    serve the purpose */
    for (i = 0; i < n; i++)
    {
        if (arr[i] & set_bit_no)
            /* arr[i] belongs to first set */
            *x = *x ^ arr[i];

        else
            /* arr[i] belongs to second set*/
            *y = *y ^ arr[i];
    }
    for (i = 1; i <= n; i++)
    {
        if (i & set_bit_no)
            /* i belongs to first set */
            *x = *x ^ i;

        else
            /* i belongs to second set*/
            *y = *y ^ i;
    }

    /* *x and *y hold the desired
        output elements */
}

/* Driver code */
int main()
{
    int arr[] = {1, 3, 4, 5, 5, 6, 2};
    int *x = (int *)malloc(sizeof(int));
    int *y = (int *)malloc(sizeof(int));
    int n = sizeof(arr) / sizeof(arr[0]);

    getTwoElements(arr, n, x, y);
    cout << " The missing element is " << *x << " and the repeating"
         << " number is " << *y;
    getchar();
}

// This code is contributed by Code_Mech
Output
        The missing element is 7 and
    the repeating number is 5 Time Complexity : O(n)
                                                    This method doesn’t cause overflow,
    but it doesn’t tell which one occurs twice and which one is missing.We can add one more step that checks which one is missing and which one is repeating.This can be easily done in O(n) time.

    Method 6(Use a Map)
        Approach : This method involves creating a Hashtable with the help of Map.In this,
    the elements are mapped to their natural index.In this process, if an element is mapped twice, then it is the repeating element.And if an element’s mapping is not there, then it is the missing element.

                                                                                                                                                                              Below is the implementation of the above approach :

// C++ program to find the repeating
// and missing elements using Maps
#include <iostream>
#include <unordered_map>
    using namespace std;

int main()
{
    int arr[] = {4, 3, 6, 2, 1, 1};
    int n = 6;

    unordered_map<int, bool> numberMap;

    for (int i : arr)
    {
        if (numberMap.find(i) ==
            numberMap.end())
        {
            numberMap[i] = true;
        }
        else
        {
            cout << "Repeating = " << i;
        }
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        if (numberMap.find(i) ==
            numberMap.end())
        {
            cout << "Missing = " << i;
        }
    }
    return 0;
}

// This code is contributed by RohitOberoi
Output
    Repeating = 1 Missing = 5 Method 7(Make two equations using sum and sum of squares)
                                Approach :

    Let x be the missing and y be the repeating element.Let N is the size of array.Get the sum of all numbers using formula S = N(N + 1) / 2 Get the sum of square of all numbers using formula Sum_Sq = N(N + 1)(2N + 1) / 6 Iterate through a loop from i = 1….N
                                                                                                                                                                                                                                                                  S -= A[i] Sum_Sq -= (A[i] * A[i])
                                                                                                                                                                                                                                                                                          It will give two equations
                                                                                                                                                                                                                                                                                              x -
                                                                                                                                                                                                                                                                                      y = S – (1)
                                                                                                                                                                                                                                                                                              x ^
                                                                                                                                                                                                                                                                                          2 – y ^ 2 = Sum_sq
                                                                                                                                                                                                                                                                                                          x +
                                                                                                                                                                                                                                                                                                      y = (Sum_sq / S) – (2)

                                                                                                                                                                                                                                                                                                          Time Complexity : O(n)

#include <bits/stdc++.h>

                                                                                                                                                                                                                                                                                                                                using namespace std;

vector<int> repeatedNumber(const vector<int> &A)
{
    long long int len = A.size();
    long long int Sum_N = (len * (len + 1)) / 2, Sum_NSq = (len * (len + 1) * (2 * len + 1)) / 6;
    long long int missingNumber = 0, repeating = 0;

    for (int i = 0; i < A.size(); i++)
    {
        Sum_N -= (long long int)A[i];
        Sum_NSq -= (long long int)A[i] * (long long int)A[i];
    }

    missingNumber = (Sum_N + Sum_NSq / Sum_N) / 2;
    repeating = missingNumber - Sum_N;
    vector<int> ans;
    ans.push_back(repeating);
    ans.push_back(missingNumber);
    return ans;
}

int main(void)
{
    std::vector<int> v = {4, 3, 6, 2, 1, 6, 7};
    vector<int> res = repeatedNumber(v);
    for (int x : res)
    {
        cout << x << "  ";
    }
    cout << endl;
}
Output
6  5  
Please write comments if you find the above codes/algorithms incorrect, or find other ways to solve the same problem.

Method 8 (Using OR Operator):

Thanks to Anish Shaha for suggesting this method.

Approach:

Given an input array 

Performing OR operation on input array.
At the same time checking if that number has occurred before, by determining if the position is already set or not. We will get the repeating number in this step.
To find missing value we have to check the bit containing 0 using OR again.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Input:
    vector<int> arr = {4, 3, 6, 2, 1, 1};
    int n = arr.size();

    // Declaring output variables
    // Note : arr[i]-1 is used instead of arr[i] as we want to use all 64 bits
    int bitOr = (1 << (arr[0] - 1));
    int repeating, missing;

    // Performing XOR as well as Checking repeating number
    for (int i = 1; i < n; i++)
    {
        // If OR operation with 1 gives same output that means, we already have 1 at that position
        if ((bitOr | (1 << (arr[i] - 1))) == bitOr)
        {
            repeating = arr[i];
            continue;
        }
        bitOr = (bitOr | (1 << (arr[i] - 1)));
    }

    // Checking missing number
    for (int i = 0; i < n; i++)
    {
        // property: OR with 0 yield 1 hence value of bitOr changes
        if ((bitOr | (1 << i)) != bitOr)
        {
            missing = i + 1;
            break;
        }
    }

    cout << "Repeating : " << repeating << "\nMissing : " << missing;
    return 0;
}
Output
        Repeating : 1 Missing : 5 Time Complexity : O(n)
                                                        Auxiliary Complexity : O(1)

                                                                                   Limitations of the approach : it only works on size of array
                                                                                                                 <= 64 if we use long and size of array
                                                                                                                 <= 32