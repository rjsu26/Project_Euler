/* * @Title: Project Euler #27: Quadratic primes * @Author: raj sahu  * @Date: 2020-08-08 00:55:20   * @Last Modified time: 2020-08-08 00:55:20  */

#include<bits/stdc++.h>
using namespace std;


void seive(int N, set<long> &ans) {
    bool isPrime[N];
    memset(isPrime, true, sizeof(isPrime));
    for (int p=2; p*p<=N;p++) {
        if (isPrime[p]) {
            for (int k = p*p; k<=N; k+=p)
                isPrime[k]=false;
        }
    }
    for (int i=2;i<=N;i++)
        if (isPrime[i])
            ans.insert(i);
}
void seive(int N, vector<long> &ans) {
    bool isPrime[N];
    memset(isPrime, true, sizeof(isPrime));
    for (int p=2; p*p<=N;p++) {
        if (isPrime[p]) {
            for (int k = p*p; k<=N; k+=p)
                isPrime[k]=false;
        }
    }
    for (int i=2;i<=N;i++)
        if (isPrime[i]) {
            ans.push_back(i);
            ans.push_back(-i);
        }
}


void find(int N, vector<long> &first, set<long> &prime) {
    // generate a and b
    int b;
    int maxa, maxb, max_ans=1;
    for (int a=-N;a<=N; a++) {
        for (int i =0; i<first.size();i++) {
            b = first[i];
            int mx=0;
            for (int n=0;n<=2000;n++) {
                int sum = n*n + a*n + b;
                if (sum >1 && prime.count(sum)!=0)
                    mx++;
                else {
                    if (mx>max_ans) {
                        maxa = a, maxb = b;
                        max_ans = mx;
                    }
                    break;
                }
            }
        }
    }
    cout<<maxa<<" "<<maxb<<endl;
}

int main() {
    int n; cin>>n;
    vector<long> first_n;
    seive(n, first_n); // find first n primes. These will be used for 'b' which has to be prime. 
    set<long> primes;
    seive(10000, primes); // n*n + a*n + b can be max about 10k. Just assumption. 
    find(n, first_n, primes);
    return 0;
}
