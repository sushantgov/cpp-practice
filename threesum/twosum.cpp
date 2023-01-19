#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<climits>
#include<algorithm>

using namespace std;

vector<int> twosum(vector<int>& vec, int& target)
{
    vector<int> ans;
    int to_find;
    unordered_map<int, int> mp;
    for (int i = 0; i < vec.size(); i++)
    {
        to_find = target - vec[i];
        if(mp.find(to_find) != mp.end())
        {
            ans.push_back(i);
            ans.push_back(mp[to_find]);
        }
        mp[vec[i]] = i;
    }
    return ans;
}

int maxProfit(vector<int>& vec2)
{
    int maxpro = 0;
    int minprice = INT_MAX;
    for (int i = 0; i < vec2.size(); i++)
    {
        minprice = min(minprice, vec2[i]);
        maxpro = max(maxpro, vec2[i] - minprice);
    }
    
    return maxpro;
}

int maxProduct(vector<int>& vec3)
{
    int curr_prod = 1;
    int temp = vec3[0];
    int prod1 = vec3[0];
    int prod2 = vec3[0];
    int maxprod = INT_MIN;
    for (int i = 1; i < vec3.size(); i++)
    {   
        maxprod = max(prod1 * vec3[i], prod2 * vec3[i], )
    }
    return maxprod;
}

int main()
{
    vector<int> vec{2,7,11,15}; 
    int target = 9;
    vector<int> vec2{7,1,5,3,6,4};
    vector<int> vec3{1,2,-3,0,-4,-5};

    // vector<int> ans = twosum(vec, target);
    int ans = maxProduct(vec3);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout<<ans[i]<<" ";
    // }
    cout<<ans;
    return 0;
}