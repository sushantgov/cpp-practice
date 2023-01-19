/* Problem: Given a string, find the length of the longest 
substring having the same letters after replacement.*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int charReplace(const string str, int k)
{
    int max_length = INT_MIN;
    int win_start = 0;
    int maxrepeat = 0;
    unordered_map<char, int> freq_map;
    for (int win_end = 0; win_end < str.length(); win_end++)
    {
        char current_char = str[current_char];
        freq_map[current_char]++;
        maxrepeat = max(maxrepeat, freq_map[current_char]);
        if (win_end - win_start + 1 - maxrepeat > k)
        {
            char old_char = str[win_start];
            freq_map[old_char]--;
            win_start++;
        }
        max_length = max(max_length, win_end - win_start + 1);
    }
    return max_length;
}

int main()
{
    int longest = charReplace("aabccbb", 2);
    cout<<"longest: "<<longest<<endl;
    return 0;
}


