/* * @Title: Project Euler #46: Goldbach's other conjecture * @Author: raj sahu  * @Date: 2020-08-11 20:42:46   * @Last Modified time: 2020-08-11 20:42:46  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<int> prime;

void sieve(){
    bool isprime[500001];
    memset(isprime, true, sizeof(isprime));
    for(int p=2;p*p<500000; p++){
        if(isprime[p]){
            // cout<<"At "<<p<<endl;
            for(int k=p*p;k<500000; k+=p){
                isprime[k]=false;
                // cout<<" k = "<<k<<endl;
            }
        }
    }
    // cout<<"20\n"<<endl;
    for(int i=2;i<500000; i++)
        if(isprime[i])
            prime.push_back(i);
}

void calculate(int N){
    int n = sqrt(N);
    int count=0;
    for(; n>0; n--){
        int d = N - 2*(n)*(n);
        if(binary_search(prime.begin(), prime.end(), d)==true)
            count++;
    }
    cout<<count<<endl;
}

int main() {
    sieve();
    int t,n; cin>>t;
    while(t--){
        cin>>n;
        calculate(n);
    }
    return 0;
}
