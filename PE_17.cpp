/* * @Title: Project Euler #17: Number to Words 
* @Author: raj sahu  
* @Date: 2020-08-05 00:50:04   
* @Last Modified time: 2020-08-05 00:50:04  */

#include <bits/stdc++.h>
using namespace std;

bool HACKERRANK = false; // make it true for project Euler solution
string space;

map<int, string> mp;

/* Define all words mapped to their values */
void insertmap()
{
    mp[1] = "One" + space;
    mp[2] = "Two" + space;
    mp[3] = "Three" + space;
    mp[4] = "Four" + space;
    mp[5] = "Five" + space;
    mp[6] = "Six" + space;
    mp[7] = "Seven" + space;
    mp[8] = "Eight" + space;
    mp[9] = "Nine" + space;
    mp[11] = "Eleven" + space;
    mp[12] = "Twelve" + space;
    mp[13] = "Thirteen" + space;
    mp[14] = "Fourteen" + space;
    mp[15] = "Fifteen" + space;
    mp[16] = "Sixteen" + space;
    mp[17] = "Seventeen" + space;
    mp[18] = "Eighteen" + space;
    mp[19] = "Nineteen" + space;
    mp[10] = "Ten" + space;
    mp[20] = "Twenty" + space;
    mp[30] = "Thirty" + space;
    mp[40] = "Forty" + space;
    mp[50] = "Fifty" + space;
    mp[60] = "Sixty" + space;
    mp[70] = "Seventy" + space;
    mp[80] = "Eighty" + space;
    mp[90] = "Ninety" + space;
}

/* Function to read a group of 3 digits and output it in words: 301 as Three Hundred One, etc/ */
void triplet(int n, string &ans)
{
    bool flag = false;
    if (n / 100 != 0)
    {
        flag = true;
        ans += mp[n / 100] + "Hundred" + space;
        n = n % 100;
    }
    if (n == 0)
        return;

    // There is gonna be some word ahead too. Hence append "and" before going further. Final output will be of the form: "Three Hundred and One (for Hackerrank, change the global variable to true)"
    if (HACKERRANK == false && flag == true)
        ans += "and" + space;
    if ((n / 10 == 0 && n % 10 != 0) || (n / 10 != 0 && n % 10 == 0) || (n / 10 == 1))
    {
        ans += mp[n];
    }
    else
    {
        int temp = 10 * (n / 10);
        int carry = n % 10;
        ans += mp[temp] + mp[carry];
    }
    return;
}

/* Convert a number n into words */
string inwords(long n)
{
    if (n == 0)
    {
        // cout << "Zero" << endl;
        return "Zero";
    }

    string ans;
    int k = 0, ln = floor(log10(n)); // number of digits in 'n' -1

    // start rading digits from left side (MSB)
    if (n / (long)1e12 != 0)
    { // read for trillion unit
        ans += "One" + space + "Trillion" + space;
        n = n % (long)1e12;
    }
    if (n / (int)1e9 != 0)
    { // for Billion
        triplet(n / (int)1e9, ans);
        ans += "Billion" + space;
        n = n % (int)1e9;
    }
    if (n / (int)1e6 != 0)
    { // for Million
        triplet(n / (int)1e6, ans);
        ans += "Million" + space;
        n = n % (int)1e6;
    }
    if (n / (int)1e3 != 0)
    { // for thousand
        triplet(n / (int)1e3, ans);
        ans += "Thousand" + space;
        n = n % (int)1e3;
    }

    triplet(n, ans); // for hundreds, tens and unit place
    // cout << ans << endl;
    return ans;
}

int main()
{
    if (HACKERRANK)
        space = " ";
    else
        space = ""; // no space in project euler

    insertmap();
    if (HACKERRANK)
    {
        int t;
        cin >> t;
        while (t--)
        {
            long n;
            cin >> n;
            cout << inwords(n) << endl;
        }
    }
    else{
        long sum=0;
        for(int i=1;i<=1000;i++){
            string temp = inwords(i);
            // cout<<temp<<" "<<temp.size()<<endl;
            sum += temp.size();
        }
        cout<<sum<<endl;
    }
    return 0;
}
