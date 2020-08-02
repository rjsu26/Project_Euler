/* * @Title: Project Euler #7: 10001st prime
* @Author: raj sahu  
* @Date: 2020-08-02 19:58:08   
* @Last Modified time: 2020-08-02 19:58:08     */

#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000005 
vector<int> Prime;

void findPrimes(){
    bool isPrime[MAX_SIZE];
    memset(isPrime, true, sizeof(isPrime));

    for(int p=2;p*p<=MAX_SIZE; p++){
        if(isPrime[p]){
            for(int i = p*p; i<MAX_SIZE; i+= p)
                isPrime[i]= false;
        }
    }
    for(int p=2;p<MAX_SIZE; p++)
        if(isPrime[p])
            Prime.push_back(p);
}

int main()
{
    long long t;
    cin >> t;
    findPrimes();
    for (int a0 = 0; a0 < t; a0++)
    {
        int n;
        cin >> n;
        cout<<Prime[n]<<endl;
    }
    return 0;
}