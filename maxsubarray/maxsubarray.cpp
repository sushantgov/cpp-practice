/*
Problem Statement: 
1.Given an integer array arr, find the contiguous subarray (containing at least one number) which
has the largest sum and return its sum and print the subarray.

2. Find the maximum sum of any contiguous subarray of size ‘k’.*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// int maxSubarrayK(int k, const vector<int> &arr) //bruteforce
// {
//     int max_sum = INT_MIN;
//     int current_sum = 0;
//     for (int i = 0; i < arr.size() - k; i++)
//     {
//         current_sum = 0;
//         for (int j = i; j < i + k; j++)
//         {
//             current_sum += arr[j];
//         }
//         max_sum = max(max_sum, current_sum);
//     }
//     return max_sum;
// }

int maxSubarrayK(int k, const vector<int> &arr) //optimal
{
    int max_sum = INT_MIN;
    int current_sum = 0;
    int window_start = 0; 
    for (int window_end = 0; window_end < arr.size(); window_end++)
    {   
        current_sum += arr[window_end]; //sum of first k elements
        if (window_end >= k - 1) // once k elements are over
        {
            max_sum = max(current_sum, max_sum); // compare
            current_sum -= arr[window_start]; //deleting first element in window
            window_start++; // window increases by 1 element stride = 1
        }
    }
    return max_sum;
}

int maxSubarray(vector<int> & arr, vector<int> & subarray)
{
    int max_sum = INT_MIN;
    int current_sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        current_sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            current_sum += arr[j]; // i + j window size
            if (current_sum > max_sum)
            {
                subarray.clear();
                max_sum = current_sum;
                subarray.push_back(i);
                subarray.push_back(j);
            }
        }
    }
    return max_sum;
}

int kadaneMaxSubarray(vector<int> & arr, pair<int, int> & subarray)
{
    int max_sum = INT_MIN;
    int start = 0;
    int current_sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        current_sum += arr[i];
        if (current_sum > max_sum)  // compare to get new max value or keep old max
        {
            max_sum = current_sum;
            subarray = {NULL, NULL};
            subarray = {start, i};
        }
        
        if (current_sum < 0) 
        {
            current_sum = 0; // making it 0 if negative
            start += 1; // incrementing to go to next index of window
        }
    }
    return max_sum;
}

// int smallestSubarray(int s, vector<int> arr)
// {
//     int min_length = INT_MAX; // if no subarray exists
//     int current_min_length = INT_MAX;
//     int current_sum = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {   
//         current_sum = 0;
//         for (int j = i; j < arr.size(); j++)
//         {
//             current_sum += arr[j];
//             current_min_length = (j - i) + 1;
//             if (current_sum >= s && current_min_length < min_length)
//             {
//                 min_length = current_min_length;                
//             }
//         }
//     }
//     return min_length;
// }
int smallestSubarray(int s, vector<int> arr)
{
    int min_length = INT_MAX; // if no subarray exists
    int current_min_length = INT_MAX;
    int current_sum = 0;
    int window_start = 0;
    for (int window_end = 0; window_end < arr.size(); window_end++)
    {   
        current_sum += arr[window_end];
        while(current_sum >= s)
        {   
            min_length = min(min_length, window_end - window_start + 1);
            current_sum -= arr[window_start];
            window_start++;
        }
    }
    return min_length;
}
int main()
{
    vector<int> arr{-2,1,-3,4,-1,2,1,-5,4};
    pair<int, int> subarray;
    // int largest = maxSubarrayK(3, vector<int>{2, 1, 5, 1, 3, 2}); 
    int smallest = smallestSubarray(7, vector<int>{2, 1, 5, 2, 3, 2});
    cout<<"The size of the smallest subarray is: "<<smallest;
    // int largest = maxSubarray(arr, subarray); // 0(n^2) soln
    // int largest = kadaneMaxSubarray(arr, subarray); // optimal soln
    // cout<< "The maximum sum is: "<<largest<<endl;
    // for (int i = subarray.first; i <= subarray.second; i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    return 0;
}