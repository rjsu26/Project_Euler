/* * @Title: Project Euler #37: Truncatable primes * @Author: raj sahu  * @Date: 2020-08-09 06:11:47   * @Last Modified time: 2020-08-09 06:11:47  */
#include<bits/stdc++.h>
using namespace std;

vector<int> prime;

// Find if all digits of a number is non-zero or not
bool nozero(int n) {
    int k;
    while (n>0) {
        k = n%10;
        if (k==0)
            return false;
        n /= 10;
    }
    return true;
}

// find all primes having non-zero digits
void sieve(int n) {
    bool isprime[n+1];
    memset(isprime, true, sizeof(isprime));
    for (int p=2;p*p<=n;p++) {
        if (isprime[p]) {
            for (int k=p*p;k<=n;k+=p)
                isprime[k]=false;
        }
    }
    for (int i=11;i<=n;i++)
        if (isprime[i] && nozero(i)) {
            prime.push_back(i);
        }
}

int cut(int n, int k, int dir) { // dir == 1: right, else left
    if (k==0) {
        // cout<<"returning "<<n<<endl;
        return n;
    }
    int nod = log10(n);
    if (dir==-1)
        return cut(n%(int)pow(10, nod), k-1, dir);
    else
        return cut(n/10, k-1, dir);
}

int main() {
    int n; cin>>n;
    sieve(n-1);
    // cout<<"sieve done\n";
    long sum=0;
    for (int i=0;i<prime.size();i++) {
        int num = prime[i];
        // cout<<"At "<<num<<endl;
        int nod = log10(num), c=0;
        int k=1;
        while (nod--) {
            num = cut(prime[i], k, 1);
            if (num==2|| num==3||num==5|| num==7||binary_search(begin(prime), end(prime), num)==true)
                c++;
            num = cut(prime[i], k, -1);
            if (num==2||num==3|| num==5|| num==7|| binary_search(begin(prime), end(prime), num)==true)
                c++;
            k++;
        }
        if (c==2*(int)log10(prime[i]))
        {
            cout<<"Found "<<prime[i]<<endl;
            sum += prime[i]; //for hackerrank
        }
    }
    cout<<sum<<endl;
    return 0;
}