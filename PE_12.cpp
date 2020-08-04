/* * @Title: Project Euler #12: Highly divisible triangular number 
* @Author: raj sahu  
* @Date: 2020-08-03 02:56:37  
* @Last Modified time: 2020-08-03 02:56:37  */

#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 75000
vector<long> Prime; // vector to contain primes

/* To find all primes from 1 to MAX_SIZE */
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
        if (isPrime[p])
            Prime.push_back(p);
    }
}

/* Return number of factors of input number n. Uses formula No. of Factors = (a+1)(b+1)(c+1).. where a,b,c,.. are powers of prime numbers in prime factorisation of the given number. */
int findfactors(long n, vector<long> &prime)
{
    int nod = 1, temp, exp;
    for (int i = 0; i < prime.size(); i++)
    {
        exp = 1;
        while (n % prime[i] == 0)
        {
            exp++;
            n /= prime[i];
        }
        nod *= exp;
        if (n == 1)
            return nod;
    }
    return nod;
}

long arr[1001] = {0};
/* Find all numbers which had number of factors more than i(i is index of array), and the number was the minimum to satisfy this property.*/
void calculate()
{
    long sum = 1, adder = 2;
    for (int i = 1; i <= 1000; i++)
    {
        while (findfactors(sum, Prime) <= i)
        {
            sum += adder;
            adder += 1;
        }
        arr[i] = sum;
    }
}

int main()
{
    int t, n;
    findPrimes();
    calculate();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << n << endl;
        cout << arr[n] << endl;
    }
    return 0;
}
