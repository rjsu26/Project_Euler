/* * @Title: Project Euler #35: Circular primes * @Author: raj sahu  * @Date: 2020-08-09 04:13:29   * @Last Modified time: 2020-08-09 04:13:29  */
#include<bits/stdc++.h>
using namespace std;

vector<int> prime;

// Find if all digits of a number is non-zero or not
bool nozero(int n){
    int k;
    while(n>0){
        k = n%10;
        if(k==0)
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
    for (int i=2;i<=n;i++)
        if(isprime[i] && nozero(i)){
            prime.push_back(i);
        }
}

int rotate(int n, int k){
    if(k==0) return n;
    int nod = log10(n);
    return rotate((n%(int)pow(10,nod))*10 + n/(int)pow(10,nod),k-1);
}

int main() {
    int n; cin>>n;
    sieve(n-1);
    int sum=0;
    for(int i=0;i<prime.size();i++){
        int num = prime[i];
        int nod = log10(num), c=0;
        int k=1;
        while(nod--){
            num = rotate(prime[i],k++);
            if(binary_search(begin(prime), end(prime), num)==true)
                    c++;
        }
        if(c==(int)log10(prime[i]))
            sum += 1; // sum += prime[i] for hackerrank
    }
    cout<<sum<<endl;
    return 0;
}