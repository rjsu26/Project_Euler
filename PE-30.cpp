/* * @Title: Project Euler #30: Digit Nth powers * @Author: raj sahu  * @Date: 2020-08-08 22:03:30   * @Last Modified time: 2020-08-08 22:03:30  */
#include<bits/stdc++.h>
using namespace std;

bool digit_sum(int n, int p){
    int ans=0, cpy=n;
    int temp;
    while(n!=0){
        ans += pow((n%10),p);
        n = n/10;
    }
    // cout<<"Sum "<<cpy<<" = "<<ans<<endl;
    return ans==cpy;
}

void calculate(int n){
    int ans=0;
    int limit = (n+1)*pow(9,n);
    for(int i=10;i<limit;i++)
        if(digit_sum(i, n)){
            ans += i;
            // cout<<i<<endl;
        }
        // cout<<"Sum  = "<<ans<<endl;
        cout<<ans<<endl;
}

int main(){
    int n; cin>>n;
    calculate(n);
    return 0;    
}