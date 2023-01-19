/* Problem: Given a string, find the length of the longest substring 
in it with no more than K distinct characters.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int longestSubstring(const string &s, int& k)
{
    int max_length = INT_MIN;
    int win_start = 0;
    unordered_map<char, int> freq_map;
    for (int win_end = 0; win_end < s.length(); win_end++)
    {
        char current_char = s[win_end];
        freq_map[current_char]++;
        while(freq_map.size() > k) // check if unique letters have been reached
        {
            char old_char = s[win_start];
            freq_map[old_char]--; //delete the occurence of first element
            if (freq_map[old_char] == 0) freq_map.erase(old_char); 
            win_start++; //shrink sliding window
        }
        max_length = max(max_length, win_end - win_start + 1); // compare lengths   
    }
    return max_length;
}

int main()
{
    int k = 2;
    const string s = "araaci";
    int length = longestSubstring(s, k);
    cout<<"The length: "<<length;
    return 0;
}