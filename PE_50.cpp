#include <bits/stdc++.h>
using namespace std;

vector<int> prime;
long limit=(long)1e6;

void sieve(){
    bool isprime[limit];
    memset(isprime, true, sizeof(isprime));
    for(int p=2;p*p<limit; p++){
        if(isprime[p]){
            for(int k=p*p;k<limit; k+=p){
                isprime[k]=false;
            }
        }
    }
    for(int i=2;i<limit; i++)
        if(isprime[i])
            prime.push_back(i);
}

int max_ans=41, max_val=6, start=0;

void calculate_max(){
    int n = prime.size(); 
    for(int k=7;k<n;k++){
        // cout<<"For k= "<<k<<endl;
        long sum=0;
        int i=0;
        while(i<k)
            sum+= prime[i++];
        if(binary_search(prime.begin(), prime.end(), sum)){
            max_ans = sum;
            max_val=k;
            start=0;
            continue;
        }
        for(;i<=min(25,n-k);i++){
            // cout<<"\tAt i="<<i<<endl;
            sum += prime[i]-prime[i-k];
            if(sum>=1000000)
                break;
            if(binary_search(prime.begin(), prime.end(), sum)){
                max_ans = sum;
                max_val=k;
                start=i-k+1;
                // cout<<max_ans<<" "<<max_val<<" "<<start<<endl;
                break;
            }   
        }
    }
}

int main(){
    sieve();
    // cout<<prime.size()<<endl;
    calculate_max();
    cout<<max_ans<<" "<<max_val<<" "<<start<<endl;
    return 0;
}