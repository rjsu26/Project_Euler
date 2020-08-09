/* * @Title: Project Euler #31: Coin sums * @Author: raj sahu  * @Date: 2020-08-08 23:42:31   * @Last Modified time: 2020-08-08 23:42:31  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[8] = {1,2,5,10,20,50,100,200};
vector<int> ans;

void find(int N){
    ans.resize(N+1, 0);
    ans[0]=1;
    for(int i=0;i<=7;i++){
        for(int j=arr[i];j<=N;j++){
            ans[j] = (ans[j]+ans[j-arr[i]])%1000000007;
        }
    }
}

int main() {
    int t,n,mx=1; cin>>t;
    vector<int> inp;
    while(t--){
        cin>>n;
        mx = max(mx, n);
        inp.push_back(n);
    }   
    find(mx);
    for(int t=0;t<inp.size();t++)
        cout<<ans[inp[t]]<<endl;
    return 0;
}
