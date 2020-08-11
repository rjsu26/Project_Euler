/* * @Title: Project Euler #45: Triangular, pentagonal, and hexagonal * @Author: raj sahu  * @Date: 2020-08-11 17:24:08   * @Last Modified time: 2020-08-11 17:24:08  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isP(long P){
    double n;
    n = (1+sqrt(1+24*P))/6;
    return n==(long)n;
}

bool isH(long H){
    double n;
    n = (1+sqrt(1+8*H))/4;
    return n==(long)n;
}

int main() {
    long long n, a, b; cin>>n>>a>>b;
    auto func=isH; 
    vector<long> vec;
    if(b==5)
        func = isP;
    for(long i=1;;i++){
        unsigned long long ans=0;
        if(a==3)
            ans = (i*(i+1))>>1;
        else 
            ans = (i*(3*i-1))>>1;
        if(ans>=n)
            break;
        // if(isP(ans) && isH(ans)) // project euler
        //     cout<<ans<<endl;    
        if(func(ans)==1){
            vec.push_back(ans);
        }
    }
    for(auto &e: vec)
        cout<<e<<endl;
    return 0;
}
