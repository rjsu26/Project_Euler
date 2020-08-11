/* * @Title:  Project Euler #44: Pentagon numbers
 * @Author: raj sahu  * @Date: 2020-08-11 06:28:02   * @Last Modified time: 2020-08-11 06:28:02  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


vector<long> pent(1001001);

void find(int n, int k) {
    #define hackerrank
    #ifdef hackerrank
    for (int num=k+1;num<=n;num++) {
        if (binary_search(pent.begin(), pent.begin()+num+1, pent[num]-pent[num-k])==true || binary_search(pent.begin()+num, pent.end(), pent[num]+pent[num-k])==true) {
            cout<<pent[num]<<endl;
        }
    }
    
#else
    int res=0;
    bool found=false;
    long i=1;
    while (!found) {
        i++;
        long p = (i*(3*i-1))>>1;
        for (long j=i-1;j>0;j--) {
            // cout<<i<<" "<<j<<endl;
            int q = (j*(3*j-1))>>1;
            if (binary_search(pent.begin(), pent.end(), p-q)==true && binary_search(pent.begin(), pent.end(), p+q)==true) {
                res = p-q;
                cout<<i<<" "<<j<<endl;
                found = true;
                break;
            }
        }
    }
    cout<<"Min is "<<res<<endl;

#endif
}

int main() {
    int n, k; cin>>n>>k;
    long s=0, temp;
    for (long i=1;i<1001001; i++)
        pent[i] = (i*(3*i-1))>>1;

    find(n, k);
}
