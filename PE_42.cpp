/* * @Title: Project Euler #42: Coded triangle numbers * @Author: raj sahu  * @Date: 2020-08-10 16:10:03   * @Last Modified time: 2020-08-10 16:10:03  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
int ans=0;


void find(ull k){
    ull lo=1, hi=pow(10,9), n;
    while(lo<=hi){
        n = (lo+hi)>>1;
        if(n==k/(n+1))
            break;
        else if(n>k/(n+1))
            hi = n-1;
        else 
            lo = n+1;
    }
    if((n*(n+1)) == k)
        ans++;
        // cout<<n<<endl;
    // else
    //     ans++;
        // cout<<"-1"<<endl;
}

int val(string s){
    int ans=0;
    for(int i=0;i<s.size();i++)
        ans += s[i]-'A'+1;
    return ans;
}
int main() {
    // int t; 
    // ull n;
    string s;
    int i=1;
    while(cin>>s){
        // cin>>n;
        // find(2*n);
        find(2*val(s));
        // cin>>s;
    }
    cout<<ans<<endl;
    return 0;
}
