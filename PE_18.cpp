/* * @Title:  Project Euler #18: Maximum path sum I and Project Eluer #67: Maximum path sum II
* @Author: raj sahu  
* @Date: 2020-08-05 02:33:45   
* @Last Modified time: 2020-08-05 02:33:45  */

#include <bits/stdc++.h>
using namespace std;

int findsum(vector<vector<int>> &mat){
    if(mat.size()==0) return 0;
    if(mat.size()==1) return mat[0][0];
    
    int i;

    // Start from top and sum max of above two elements. The last row will have the maximum value. Iterate over the last row to find maximum sum. Can be solved conversely by going bottom-up.
    for(i=1;i<mat.size();i++){
        for(int j=0;j<=i;j++){
            mat[i][j] += max(mat[i-1][max(0,j-1)], mat[i-1][min((int)mat[i-1].size()-1,j)]);
        }
    }
    return *max_element(begin(mat[i-1]), end(mat[i-1]));
}

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>> mat;
        for(int i=1;i<=n;i++){
            vector<int> temp(i);
            for(int j=0;j<i;j++)
                cin>>temp[j];
            mat.push_back(temp);
        }
        cout<<findsum(mat)<<endl;
    }
    return 0;
}
