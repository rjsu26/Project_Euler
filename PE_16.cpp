/* * @Title: Project Euler #16: Power digit sum 
* @Author: raj sahu  
* @Date: 2020-08-05 00:27:00   
* @Last Modified time: 2020-08-05 00:27:00  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> ans; // saves answer in reverse order as string form 

void calculate(int mx){
    for(int i=2; i<=mx;i++){
        int temp=1, carry=0;
        for(int j=0;j<ans[i-1].size();j++){
            temp = (ans[i-1][j]-'0') * 2;
            ans[i] += to_string(temp%10 + carry);
            carry = temp/10;
        }
        if (carry!=0)
            ans[i] += "1";
    }
}

int main() {
    int t; cin>>t;
    vector<int> inp;
    int mx=0;
    int n;
    while(t--){
        cin>>n;
        inp.push_back(n);
        mx = max(mx, n);
    }
    ans.resize(mx+1,"");
    ans[0]="1";
    ans[1]="2";
    calculate(mx);
    for(int i=0;i<inp.size();i++){
        long long sum=0;
        int k=0;
        while(k<ans[inp[i]].size())
            sum += ans[inp[i]][k++] - '0';
        cout<<sum<<endl;
    }
    return 0;
}
