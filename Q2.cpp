/* Q2 -> Given two rectangles, find if the given two rectangles overlap or not.
A rectangle is denoted by providing the x and y coordinates of two points: the left top corner and the right bottom corner of the rectangle.
Two rectangles sharing a side are considered overlapping.
(L1 and R1 are the extreme points of the first rectangle and L2 and R2 are the extreme points of the second rectangle).
Note: It may be assumed that the rectangles are parallel to the coordinate axis.
*/

#include <bits/stdc++.h>
using namespace std;
bool overlap(vector<int> b1, vector<int> d1, vector<int> b2, vector<int> d2)
{
    // rectangles will not overlap if one rectange is above another
    if (d1[1] < b2[1] || d2[1] < b1[1])
    {
        return false;
    }

    // rectangles will not overlap if one rectange is left to the left edge of another
    if (d1[0] > b2[0] || d2[0] > b1[0])
    {
        return false;
    }
    return true;
}
int main()
{
    vector<int> b1, d1, b2, d2;
    d1.push_back(0);
    d1.push_back(10);
    b1.push_back(10);
    b1.push_back(0);
    d2.push_back(5);
    d2.push_back(5);
    b2.push_back(15);
    b2.push_back(0);
    cout << overlap(b1, d1, b2, d2);
    return 0;
}