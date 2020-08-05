/* * @Title:  Project Euler #19: Counting Sundays
* @Author: raj sahu
* @Date: 2020-08-05 20:13:39
* @Last Modified time: 2020-08-05 20:13:39  */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int t[]={ 0, 3, 2, 5, 0, 3,
5, 1, 4, 6, 2, 4 }; // array to be used in Sakamoto's methods

// Find day of week using Sakamoto's methods
bool dayofweek(int d, int m, long y) {
    if (m<3) // reduce year value if jan and feb
        y -= 1;

    int x = (y+ y/4-y/100+y/400+t[m-1] + d)%7; // main formula
    
    return x==0; // sunday =0, monday = 1, ....
}

// Finding day of week using Zeller's algorithm
bool dayofweek2(int d, int m, long y) {
    if (m<=2){
        m += 12; // jan and feb becomes 13 and 14 respectively
        y--; // year is reduced by 1, like above method.
    }
    
    int x = (d +  13*(m+1)/5 + y + y/4 -y/100 + y/400 ) % 7; // main formula 
    
    x = (x+5)%7 + 1; // convert output to ISO week day system where, monday = 1, ...., sunday=7
    return x==7;
}

// Function to change date to 1st of next month. 
void increment(int *d, int *m, long *y) {
    *m += 1;
    *d=1;
    if (*m>12) {
        *y += 1;
        *m =1;
    }
    return;
}

int main() {
    int t; cin>>t;
    while (t--) {
        int d1, d2, m1, m2;
        long y1, y2;
        cin>>y1>>m1>>d1>>y2>>m2>>d2;

        // Swap input if second one is smaller than first one
        if(y1>y2 || (y1==y2 && m1>m2)){
            swap(y1,y2);
            swap(m1, m2);
        }

        if (d1>1)  // change start date to next 1st of month
            increment(&d1, &m1, &y1);
        
        int count=0;
        while (y1<y2 ||(y1==y2 && m1<=m2)) {
            if (dayofweek(d1, m1, y1)==true)
                count++;
            increment(&d1, &m1, &y1);
        }
        cout<<count<<endl;
    }
    return 0;
}
