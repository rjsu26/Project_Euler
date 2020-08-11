/* * @Title: Project Euler #52: Permuted multiples * @Author: raj sahu  * @Date: 2020-08-12 02:33:56   * @Last Modified time: 2020-08-12 02:33:56  */

#include<bits/stdc++.h>
using namespace std;

long myhash(int N) {
    // create a hash value of number N;
    long ans=0; int temp, pos=1;
    while (N>0) {
        temp=N%10;
        pos=1;
        for (int i=0;i<temp;i++) pos *= 10;
        ans += pos;
        N /= 10;
    }
    return ans;
}

int main() {
    int n, k; cin>>n>>k;
    bool flag;
    for (int i=1;i<=n;i++) {
        long id = myhash(i);
        flag = true;
        for (int j=2;j<=k;j++)
            if (id!=myhash(j*i)) {
                flag= false;
                break;
            }
        if (flag==true)
        {
            for (int j=1;j<=k;j++)
                cout<<j*i<<" ";
            cout<<endl;
        }
    }
    return 0;
}