/* * @Title:  Project Euler #41: Pandigital prime* @Author: raj sahu  * @Date: 2020-08-10 05:17:40   * @Last Modified time: 2020-08-10 05:17:40  */// #include <cmath>
#include <bits/stdc++.h>
using namespace std;

bool checkpan(int n){
    int nod = log10(n)+1;
    int bitset = 0;
    for(int i=1;i<=nod;i++)
        bitset |= (1<<i);
    int digit=0, count=0, temp;
    while(n>0){
        temp = digit;
        digit |= (1<<(n%10));
        if(digit==temp)
            return false;
        n /= 10;
    }
    return digit==bitset;
}

vector<int> prime;
int limit=7654321 + 1;

void sieve() {
    bool isprime[limit];
    memset(isprime, true, sizeof(isprime));
    for (int p=2;p*p<=limit;p++) {
        if (isprime[p]) {
            for (int k=p*p;k<limit;k+=p)
                isprime[k]=false;
        }
    }
    for (int i=11;i<limit;i++)
        if (isprime[i]&&checkpan(i)) {
            prime.push_back(i);
            // cout<<i<<" ";
        }
    // cout<<endl;
}


vector<int> ans(limit,0);

void compute(){
    for(int i=prime[0], k=0;i<=prime.back()&&k<prime.size();i++)
        {
            if(i==prime[k+1])
                k++;
            ans[i]= prime[k];
        }
}

int main() {
    sieve();
    compute();
    int t,n; cin>>t;
    while(t--){
        cin>>n;
        if(n<prime[0] )
            cout<<-1<<endl;
        else if( n>prime.back())
            cout<<prime.back()<<endl;
        else {
            cout<<ans[n]<<endl;
        }
    }
    return 0;
}
