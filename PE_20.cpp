/* * @Title: Project Euler #20: Factorial digit sum 
* @Author: raj sahu  
* @Date: 2020-08-05 03:15:58   
* @Last Modified time: 2020-08-05 03:15:58  */

#include<bits/stdc++.h>
using namespace std;

vector<string> ans; // saves answer in reverse order as string form 

void calculate(int mx){
    for(int i=2; i<=mx;i++){
        int temp=1, carry=0;
        for(int j=0;j<ans[i-1].size();j++){
            temp = (ans[i-1][j]-'0') * i;
            ans[i] += to_string((temp+carry)%10);
            carry = (temp+carry)/10;
        }
        if (carry!=0){
            while(carry!=0){
                temp = carry%10;
                ans[i] += to_string(temp);
                carry /= 10;
            }
        }
        // cout<<i<<"! = "<<string(ans[i].rbegin(), ans[i].rend())<<endl;
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
    ans[1]="1";
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
