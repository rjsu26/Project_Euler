/* * @Title: Project Euler #13: Large sum 
* @Author: raj sahu  
* @Date: 2020-08-04 16:33:49   
* @Last Modified time: 2020-08-04 16:33:49  */

#include <bits/stdc++.h>
using namespace std;


string findsum(vector<string> &vec){
    string ans; 
    long carry = 0;
    long temp=0;
    for(int i=0;i<50;i++){
        temp = 0;
        for(int j=0;j<vec.size();j++){
            temp += vec[j][i]-'0';
        }
        temp += carry;
        carry = temp/10;
        temp = temp%10;
        ans += to_string(temp);
    }
    if(carry!=0)
        while(carry!=0){
            temp = carry%10;
            carry = carry/10;
            ans += to_string(temp);
        }

    reverse(begin(ans), end(ans));
    return ans.substr(0,10);
}

int main(){
    int n; cin>>n;
    vector<string>vec(n);
    string num;
    for(int i=0;i<n;i++){
        cin>>num;
        reverse(num.begin(), num.end());
        vec[i] = num;
    }
    cout<<findsum(vec);
    return 0;
}
