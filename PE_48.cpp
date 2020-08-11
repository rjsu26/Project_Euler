/* * @Title: Project Euler #48: Self powers * @Author: raj sahu  * @Date: 2020-08-12 00:21:02   * @Last Modified time: 2020-08-12 00:21:02  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

long mult(ull x, ull y){
    x = x%(ull)1e10;
    y = y%(ull)1e10;

    ull a,b,c,d;
    a = (x/(ull)1e9)*(ull)1e9;
    b= x%(ull)1e9;
    c=(y/(ull)1e9)*(ull)1e9;
    d = y%(ull)1e9;

    ull ad,bc,bd;
    bd = (b*d)%(ull)1e10;
    bc = (b*c)%(ull)1e10;
    ad = (a*d)%(ull)1e10;
    return (bd+bc+ad)%(ull)1e10;
}

long expo(int N){
    unsigned long long a=N, res=1;
    int e=N;
    while(e>0){
        if(e&1)
            res = mult(res,a);
        
        a = mult(a,a); 
        e = (e>>1);
    }
    return (long)res;
}

void find(int N){
    long sum=0;
    for(int i=1;i<=N;i++){
        sum = (sum+expo(i))%10000000000;
    }
    cout<<sum<<endl;
}

int main() {
    int n; 
    while(cin>>n)
        find(n);
    return 0;
}
