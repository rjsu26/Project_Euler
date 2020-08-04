/* * @Title: Project Euler #15: Lattice paths 
* @Author: raj sahu  
* @Date: 2020-08-04 22:52:11   
* @Last Modified time: 2020-08-04 22:52:11  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501]={0};

void calculate(){
    for(int i=0;i<=500;i++)
       { dp[i][0]=1;
         dp[0][i]=1;
       }
    
    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++)
            dp[i][j]= (dp[i-1][j] + dp[i][j-1]) % 1000000007;
    }
}

int main() {
    int t; cin>>t;
    calculate();
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<dp[m][n]<<endl;
    }
    return 0;
}
