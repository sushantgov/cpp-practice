#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

// vector<vector<int>> threesum(vector<int> vec)
// {
//     vector<vector<int>> ans;
//     for (int i = 0; i < vec.size() - 2; i++)
//     {
//         // target_sum = -vec[i];
//         for (int j = i + 1; j < vec.size() - 1; j++)
//         {
//             for (int k = j + 1; k < vec.size(); k++)
//             {
//                 if (vec[i] + vec[j] + vec[k] == 0)
//                 {
//                     ans.push_back({vec[i], vec[j], vec[k]});
//                 }
//             }
//         }
//     }
//     return ans;
// }

vector<vector<int>> threesum(vector<int>& vec)
{
    vector<vector<int>> ans;
    int target_sum = 0;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (i != 0 && vec[i] == vec[i-1]) continue;
        unordered_set<int> seen;
        for (int j = i + 1; j < vec.size(); j++)
        {
            target_sum = -vec[i] - vec[j];
            if (seen.count(target_sum))
            {
                ans.push_back({vec[i], vec[j], target_sum});
                while(j != i+1 && vec[j] == vec[j - 1]) j++;
            }
        seen.insert(vec[j]);
        }
    }
    return ans;
}

int main()
{
    vector<int> vec{-1,0,1,2,-1,-4};
    vector<vector<int>> output = threesum(vec);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
}