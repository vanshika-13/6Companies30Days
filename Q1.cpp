// Given an array of strings, return all groups of strings that are anagrams.
// The groups must be created in order of their appearance in the original array.
/*
Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output:
god dog
act cat tac
Explanation:
There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.*/

#include <bits/stdc++.h>
using namespace std;
// vector<string> ans;
bool isAnagram(string s1, string s2)
{
    int i;
    int count[26] = {0};
    for (i = 0; s1[i] && s2[i]; i++)
    {
        count[s1[i] - 'a']++;
        count[s2[i] - 'a']--;
    }
    if (s1[i] || s2[i])
    {
        return false;
    }
    for (int j = 0; j < 26; j++)
    {
        if (count[j])
        {
            return false;
        }
    }
    return true;
}
void returnAnagram(vector<string> words)
{
    int n = words.size();
    for (int i = 0; i < n; i++)
    {
        cout << words[i];
        for (int j = i + 1; j < n; j++)
        {
            if (isAnagram(words[i], words[j]))
            {
                cout << " " << words[j];
                words.erase(words.begin() + j);
            }
            else
            {
                continue;
            }
        }
        // words.erase(words.begin() + i);
        cout << endl;
        n = words.size();
    }
}

/*
     vector<vector<string> > Anagrams(vector<string>& string_list) 
     {
        map<string, vector<string>>m;
    
        for(int i=0;i<string_list.size();i++)
        {
            string s=string_list[i];
            sort(s.begin(), s.end());
    
            m[s].push_back(string_list[i]);
        }
    
        vector<vector<string> > v;
    
        for(auto i:m)
        {
            v.push_back(i.second);
        }
    
        return v;
    }
*/

int main()
{
    vector<string> words = {"act", "god", "cat", "dog", "tac"};
    returnAnagram(words);
    return 0;
}