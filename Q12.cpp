An encoded string (s) is given, the task is to decode it. The pattern in which the strings are encoded is as follows. 

<count>[sub_str] ==> The substring 'sub_str' 
                      appears count times.
Examples:  

Input : str[] = "1[b]"
Output : b

Input : str[] = "2[ab]"
Output : abab

Input : str[] = "2[a2[b]]"
Output : abbabb

Input : str[] = "3[b2[ca]]"
Output : bcacabcacabcaca
Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
The idea is to use two stacks, one for integers and another for characters. 
Now, traverse the string, 

Whenever we encounter any number, push it into the integer stack and in case of any alphabet (a to z) or open bracket (‘[‘), push it onto the character stack.
Whenever any close bracket (‘]’) is encounter pop the character from the character stack until open bracket (‘[‘) is not found in the character stack. Also, pop the top element from the integer stack, say n. Now make a string repeating the popped character n number of time. Now, push all character of the string in the stack.


Below is the implementation of this approach:  


// C++ program to decode a string recursively
// encoded as count followed substring
#include<bits/stdc++.h>
using namespace std;
 
// Returns decoded string for 'str'
string decode(string str)
{
    stack<int> integerstack;
    stack<char> stringstack;
    string temp = "", result = "";
 
    // Traversing the string
    for (int i = 0; i < str.length(); i++)
    {
        int count = 0;
 
        // If number, convert it into number
        // and push it into integerstack.
        if (str[i] >= '0' && str[i] <='9')
        {
            while (str[i] >= '0' && str[i] <= '9')
            {
                count = count * 10 + str[i] - '0';
                i++;
            }
 
            i--;
            integerstack.push(count);
        }
 
        // If closing bracket ']', pop element until
        // '[' opening bracket is not found in the
        // character stack.
        else if (str[i] == ']')
        {
            temp = "";
            count = 0;
 
            if (! integerstack.empty())
            {
                count = integerstack.top();
                integerstack.pop();
            }
 
            while (! stringstack.empty() && stringstack.top()!='[' )
            {
                temp = stringstack.top() + temp;
                stringstack.pop();
            }
 
            if (! stringstack.empty() && stringstack.top() == '[')
                stringstack.pop();
 
            // Repeating the popped string 'temp' count
            // number of times.
            for (int j = 0; j < count; j++)
                result = result + temp;
 
            // Push it in the character stack.
            for (int j = 0; j < result.length(); j++)
                stringstack.push(result[j]);
 
            result = "";
        }
 
        // If '[' opening bracket, push it into character stack.
        else if (str[i] == '[')
        {
            if (str[i-1] >= '0' && str[i-1] <= '9')
                stringstack.push(str[i]);
 
            else
            {
                stringstack.push(str[i]);
                integerstack.push(1);
            }
        }
 
        else
            stringstack.push(str[i]);
    }
 
    // Pop all the element, make a string and return.
    while (! stringstack.empty())
    {
        result = stringstack.top() + result;
        stringstack.pop();
    }
 
    return result;
}
 
// Driven Program
int main()
{
    string str = "3[b2[ca]]";
    cout << decode(str) << endl;
    return 0;
}
Output
bcacabcacabcaca
<!—-Illustration of above code for “3[b2[ca]]”> 



Method 2(Using 1 stack)
Algorithm:

Loop through the characters of the string

If the character is not ‘]’, add it to the stack

If the character is ‘]’:

   While top of the stack doesn’t contain ‘[‘, pop the characters from the stack and store it in a string temp(Make sure the string isn’t in reverse order)

   Pop ‘[‘ from the stack

   While the top of the stack contains a digit, pop it and store it in dig

   Concatenate the string temp for dig number of times and store it in a string repeat

   Add the string repeat to the stack

Pop all the characters from the stack(also make the string isn’t in reverse order) 

Below is the implementation of this approach: 


#include <iostream>
#include <stack>
using namespace std;
 
string decodeString(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        // When ']' is encountered, we need to start
        // decoding
        if (s[i] == ']') {
            string temp;
            while (!st.empty() && st.top() != '[') {
                // st.top() + temp makes sure that the
                // string won't be in reverse order eg, if
                // the stack contains 12[abc temp = c + "" =>
                // temp = b + "c" => temp = a + "bc"
                temp = st.top() + temp;
                st.pop();
            }
            // remove the '[' from the stack
            st.pop();
            string num;
            // remove the digits from the stack
            while (!st.empty() && isdigit(st.top())) {
                num = st.top() + num;
                st.pop();
            }
            int number = stoi(num);
            string repeat;
            for (int j = 0; j < number; j++)
                repeat += temp;
            for (char c : repeat)
                st.push(c);
        }
        // if s[i] is not ']', simply push s[i] to the stack
        else
            st.push(s[i]);
    }
    string res;
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    return res;
}
// driver code
int main()
{
    string str = "3[b2[ca]]";
    cout << decodeString(str);
    return 0;
}
Output
bcacabcacabcaca