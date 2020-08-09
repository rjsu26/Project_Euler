/* * @Title: Project Euler #34: Digit factorials * @Author: raj sahu  * @Date: 2020-08-09 02:40:12   * @Last Modified time: 2020-08-09 02:40:12  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int fac[10]={1,1,2,6,24,120,720, 5040, 40320, 362880}; // 0! to 9!

int main() {
    // int n; cin>>n; // disable comment for hackerrank
    long sum=0;
    for(int i=3;i<=2540160;i++){ // for(i=10;i<n;i++) : for hackerrank
        long temp=0;
        int k=i;
        while(k>0){
            temp += fac[k%10];
            k /= 10;
        }
        if(temp==i) // hackerrank: temp%i ==0
            sum += i;
    }
    cout<<sum<<endl;
    return 0;
}
