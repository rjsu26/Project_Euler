/* * @Title:Project Euler #3: Largest prime factor  
* @Author: raj sahu  
* @Date: 2020-08-02 06:21:36   
* @Last Modified time: 2020-08-02 06:21:36  */
#include <bits/stdc++.h>
using namespace std;

long long findfactor(long long N){
    long long maxp = -1;
    while(N%2==0){
        maxp=2;
        N = N>>1;
    }
    for(long i=3;i*i<=N;i+=2) {
        while(N%i==0){
            maxp = i;
            N /= i;
        }
    }
    if (N>2) maxp = N;
    return maxp==-1?N:maxp;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long long n;
        cin >> n;
        long long ans = findfactor(n);
        cout<<ans<<endl;
    }
    return 0;
}
