/*
 * @Title:Project Euler #4: Largest palindrome product 
 * @Author: raj sahu  
 * @Date: 2020-08-02 06:19:35  
 *  @Last Modified time: 2020-08-02 06:19:35  */

#include <bits/stdc++.h>
using namespace std;

bool pal(int n)
{
    string s = to_string(n);
    reverse(begin(s), end(s));
    return to_string(n) == s;
}

bool factorize(int n)
{
    for (int j = sqrt(n); j > 100; j--)
        if (n % j == 0 && (int)log10(n / j) == 2)
        {
            return true;
        }
    return false;
}

long findsol(int n)
{
    for (int i = n; i >= 101101; i--)
    {
        if (i % 11 == 0 && pal(i) && factorize(i) == true)
            return i;
    }
    return 101101;
}

int main()
{
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++)
    {
        int n;
        cin >> n;
        cout << findsol(n - 1) << endl;
    }
    return 0;
}
