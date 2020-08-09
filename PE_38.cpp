/* * @Title:  Project Euler #38: Pandigital multiples* @Author: raj sahu  * @Date: 2020-08-10 00:23:26   * @Last Modified time: 2020-08-10 00:23:26  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void find(int n, int k){
    int bitset=0;
    for(int i=1;i<=k;i++)
        bitset |= (1<<i);

    for(int i= 2; i<n;i++){
        int cnt=2, temp;
        string p= to_string(i);

        // form the pandigital number
        while(p.size()<k){
            p += to_string(i*cnt++);
        }
        if(p.size()>k)
            continue;

        // check if all digits exist or not
        int digit=0,count=0, ig=0;
        while(p.size()> ig){
            temp = digit;
            if(p[ig]=='0') break;
            digit = digit | (1<<(p[ig++]-'0'));
            if (temp==digit)
                break;
            count++;
        }
        if(count==k && digit==bitset)
            cout<<i<<endl;
    }
}

int main() {
    int n,k; cin>>n>>k;
    find(n,k);
    return 0;
}
