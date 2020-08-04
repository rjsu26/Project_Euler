/* * @Title: Project Euler #14: Longest Collatz sequence
* @Author: raj sahu  
* @Date: 2020-08-04 19:36:38   
* @Last Modified time: 2020-08-04 19:36:38  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

vector<long> chain;
vector<long> mp;

int chainlength(long n){
    int steps=0;
    long val=n;
    while(val>1 && val>=n){
        steps++;
        if((val&1)==0)
            val /= 2;
        else 
            val = 3*val + 1;
    }
    mp[n] = steps + mp[val];
    return mp[n];
}

void findchain(int n){
    for(long i=2;i<=n;i++)
        chain[i] = chainlength(i);

    long mx_i=1, mx_v = chain[1];
    for(int i=2;i<=n;i++)
    {
        if (chain[i]>=mx_v){
            mx_v = chain[i];
            mx_i = i; 
        }
        chain[i] = mx_i;
    }
}

int main() {
    int t; cin>>t;
    vector<int> inp;
    int mx=0;
    while(t--){
        int n; cin>>n;
        inp.push_back(n);
        mx = max(mx, n);
    }
    chain.resize(mx+1);
    mp.resize(mx+1,0);
    mp[1]=1;
    findchain(mx);
    for(int i=0;i<inp.size();i++)
        cout<<chain[inp[i]]<<endl;
    return 0;
}
