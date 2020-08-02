/* * @Title: Project Euler #10: Summation of primes
* @Author: raj sahu  
* @Date: 2020-08-03 01:40:26   
* @Last Modified time: 2020-08-03 01:40:26  */

#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 1000005
vector<long> Prime(MAX_SIZE, 0); // vector to contain sum of primes not greater than i, where i is index

void findPrimes()
{
    bool isPrime[MAX_SIZE];
    memset(isPrime, true, sizeof(isPrime));

    for (int p = 2; p * p <= MAX_SIZE; p++)
    {
        if (isPrime[p])
        {
            for (int i = p * p; i < MAX_SIZE; i += p)
                isPrime[i] = false;
        }
    }
    for (int p = 2; p < MAX_SIZE; p++)
    {
        Prime[p] = Prime[p - 1];
        if (isPrime[p])
            Prime[p] += p;
    }
}

int main()
{
    int t;
    cin >> t;
    findPrimes();
    for (int a0 = 0; a0 < t; a0++)
    {
        int n;
        cin >> n;
        cout << Prime[n] << endl;
    }
    return 0;
}