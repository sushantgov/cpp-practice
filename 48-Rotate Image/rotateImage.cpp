#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> rotateImage(vector<vector<int>>& image)
{
    vector<vector<int>> rotated_img;
    int height = image.size(); // rows
    int width = image[0].size(); //columns
    vector<int> current_row;
    for(int row = height - 1; row <= 0; row++)
    {
        rotated_img.push_back(row);
        c_r.push_back(row);
        for (c_r = 0)
            rotate_img[i]
        for (int col = 0; col < width; col++)
        {
            
        }
    }
    return 0;
}

int main()
{   
    vector<vector<int>> img = {{1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {9, 10, 11, 12}};
    
    cout<<"size: "<<img[0].size();

    return 0;
}