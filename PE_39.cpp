/* * @Title: Project Euler #39: Integer right triangles * @Author: raj sahu  * @Date: 2020-08-10 01:22:03   * @Last Modified time: 2020-08-10 01:22:03  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> ans(5000001,0);

void find(){
    vector<int> freq(5000001,0);
    // int n=5000000;
    for(int m=2;m<=1600;m++){
        // cout<<"At m= "<<m<<endl;
        for(int n=1;n<m; n++){
            // cout<<"\tAt n="<<n<<endl;
            if((m+n)%2!=0 && __gcd(m,n)==1){
                int k=1, p= 2*m*(m+n);
                while(p*k<=5000000){
                    freq[p*k]++;
                    k++;
                }
            }
            
        }
    }
    for(int i=1;i<=5000000;i++){
        if(freq[i]>freq[i-1])
            {
                ans[i] = i;
            }
        else {
            ans[i] = ans[i-1];
            freq[i]=freq[i-1];
        }
    }
}


int main() {
    find();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}
