/* * @Title: Project Euler #6: Sum square difference 
* @Author: raj sahu  
* @Date: 2020-08-02 19:58:08   
* @Last Modified time: 2020-08-02 19:58:08  */

#include <bits/stdc++.h>
using namespace std;

long long sum_sq_diff(int n){
    long sum = (n * (n+1))>>1; // sum of first n numbers = n * (n+1)/2
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans += i*(sum-i); // // (a+b+c+...)^2 - (a^2+ b^2 + c^2 +...) = 2ab + 2ac + 2bc + .... = a(sum -a) + b(sum-b) + c(sum-c) + .....
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout<<sum_sq_diff(n)<<endl;
    }
    return 0;
}
