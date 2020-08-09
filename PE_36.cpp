/* * @Title: Project Euler #36: Double-base palindromes * @Author: raj sahu  * @Date: 2020-08-09 05:02:10   * @Last Modified time: 2020-08-09 05:02:10  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string base(int n, int b){
    string ans="";
    while(n>0){
        ans += n%b +'0';
        n /= b;
    }
    return ans;
}

bool ispal(string n){
    return n==string(n.rbegin(), n.rend());
}

int main() {
    int n,k; cin>>n>>k;
    int sum=1;
    for(int i=2; i<n;i++)
        if(ispal(to_string(i)) && ispal(base(i,k)))
            sum += i;
    cout<<sum<<endl;
    return 0;
}
