/* * @Title: Project Euler #11: Largest product in a grid 
* @Author: raj sahu  
* @Date: 2020-08-03 02:03:16   
* @Last Modified time: 2020-08-03 02:03:16  */

#include <bits/stdc++.h>
using namespace std;

int largest(vector<vector<int>> &grid)
{
    int p=1, temp =1;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
                if (i+3<20 && j-3>=0){ // check for left diagonal
                    temp = grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3];
                    p = max(p, temp);
                } 
                if (i+3<20){ // check for down
                    temp = grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j];
                    p = max(p, temp);
                } 
                if (i+3<20 && j+3<20){ // check for right diagonal
                    temp = grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
                    p = max(p, temp);
                } 
                if (j<20){ // check for right
                    temp = grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
                    p = max(p, temp);
                }    
        }
    }
    return p;
}

int main()
{
    vector<vector<int>> grid(20, vector<int>(20));
    for (int grid_i = 0; grid_i < 20; grid_i++)
    {
        for (int grid_j = 0; grid_j < 20; grid_j++)
        {
            cin >> grid[grid_i][grid_j];
        }
    }
    cout << largest(grid);
    return 0;
}