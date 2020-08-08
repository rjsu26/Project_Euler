/* * @Title: Project Euler #28: Number spiral diagonals * @Author: raj sahu  * @Date: 2020-08-08 03:34:17   * @Last Modified time: 2020-08-08 03:34:17  */

#include<bits/stdc++.h>
using namespace std;

unsigned long inv(unsigned long long a, unsigned long long p){
    // inverse = a^(p-2) % p
    int n = p-2;
    unsigned long long ans=1;
    while(n>0){
        if((n&1)==1){
            ans = (ans*a)%p;
            n--;
        }
        else{
            a = (a*a)%p;
            n /=2;
        }
        // cout<<"ans = "<<ans<<" n= "<<n<<endl;
    }
    return ans;
}

unsigned int mod = 1000000007;

int main(){
    // cout<<inv(3,107)<<endl;
    // return 0;
    int t; cin>>t;
    while(t--){
        unsigned long long n;
        cin>>n;
        n = n>>1; // get ring number 
        n = n%mod;
        // total diagonal sum = 8n(n+1)(2n+1)/3 + 2n(n+1) + 4n+1
        unsigned long long common = (2*n*(n+1))%mod;
        unsigned long  inv3 = inv(3,mod);
        // cout<<"Inv = "<<inv3<<endl; 
        unsigned long long first_term = ((common*4*(2*n+1)) % mod * inv3)%mod;
        unsigned long long last_term = (4*n+1) % mod;
        unsigned long long sum = (first_term + common + last_term)%mod; 
        cout<<sum<<endl;
    }
}