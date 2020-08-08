/* * @Title: Project Euler #26: Reciprocal cycles * @Author: raj sahu  * @Date: 2020-08-08 00:55:00   * @Last Modified time: 2020-08-08 00:55:00  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<int,int> cache;

int cycle_length(int x){
    while(x%2==0) x /= 2;
    while(x%5==0) x /= 5;
    if(x==1) return 0;

    if(cache.count(x)!=0)
        return cache[x];

    int cnt=0, rem = 10;
    do{
        cnt++;
        rem = (rem%x)*10;
    }while(rem!=10);

    return cache[x]=cnt;
}

vector<int> ans(10000,0);

// Find all recurring number length upto N
void calculate(int N){
    int mx=0, val=2, temp;
    for(int i=3;i<=N;i++)
    {
        temp = cycle_length(i);
        if (temp>mx){
            mx = temp;
            val = i;
        }
        ans[i] = val;
    }
}

int main() {
    int t, n; cin>>t;
    calculate(10000);
    while(t--){
        cin>>n;
        cout<<ans[n-1]<<endl;
    }
    return 0;
}
