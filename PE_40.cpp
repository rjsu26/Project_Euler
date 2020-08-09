/* * @Title: Champernowne's constant * @Author: raj sahu  * @Date: 2020-08-10 04:38:00   * @Last Modified time: 2020-08-10 04:38:00  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long> power;
void findpow(){
    for(int i=0;i<=18;i++)
        power.push_back(pow(10,i));
}

int find(unsigned long long p){
    if(log10(p)<1)
        return p;
    int n;
    for(n=1;n<=18;n++){
       if((9*n-1)*power[n] >= (9*p-1))
            break; 
    }
    n--;
    // cout<<"n= "<<n<<endl;
    unsigned long long sm=(1+power[n]*(9*n-1))/9, dif;
    // n++;
    // cout<<"sum = "<<sm<<" actual = "<<p<<endl;
    dif = p-sm;
    // cout<<"difference = "<<dif<<endl;
    int minus = dif/(n+1);
    unsigned long long num = power[n]-1;
    // cout<<"num = "<<num<<" "<<minus<<endl;
    num += minus;
    // cout<<"came to = "<<num<<endl;

    minus = dif%(n+1);
    if(minus==0)
        return num%10;
    minus--;
    auto cpy = num;
    // cout<<"mod = "<<minus<<endl;
    num = num/power[log10(num)-minus];
    cout<<cpy<<" "<<num<<" "<<minus<<" "<<num%10<<endl;
    // cout<<"returning "<<num<<endl;
    return num%10;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    findpow();
    int t; cin>>t;
    while(t--){
        unsigned long long d[7], mx=1;
        int i=0;
        while(i<7){
            cin>>d[i];
            i++;
            mx *= find(d[i-1]);
            // mx = max(mx, d[i-1]);
        }
        cout<<mx<<endl;
    }
    return 0;
}
