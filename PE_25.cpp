/* * @Title: Project Euler #25: N-digit Fibonacci number 
* @Author: raj sahu  
* @Date: 2020-08-07 22:36:05   
* @Last Modified time: 2020-08-07 22:36:05  */

#include <bits/stdc++.h>
using namespace std;

void s_add(string &a, string &b){
    // Change b to a+b. b>=a
    int k=0, carry=0, temp;
    while(k<b.size()){
        temp =  b[k]-'0' + carry;
        if(k<a.size())
            temp += a[k]-'0';

        b[k] = temp%10 + '0';
        carry = temp/10;
        k++;
    }
    if(carry==1)
        b+= '1';
}

vector<int> mp;

void calculate(int N){
    int cpy=N;
    string a="1", b="1";
    long i=1, nod=0;
    string temp;
    while(nod!=N){
        if(a.size()>nod){
            nod++;
            mp[nod] = i;
        }
        temp = a;
        a = b;
        s_add(temp,b); // b = a+b
        i++;
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
 
    int t,n; cin>>t;
    int mx=1;
    vector<int> inp;
    while(t--){
        cin>>n;
        inp.push_back(n);
        mx = max(mx, n);
    }
    mp.resize(mx+1,0);
    calculate(mx);
    for(int i=0;i<inp.size();i++){
        cout<<mp[inp[i]]<<endl;
    }
    return 0;
}
