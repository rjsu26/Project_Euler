/* * @Title: Project Euler #32: Pandigital products * @Author: raj sahu  * @Date: 2020-08-09 01:33:40   * @Last Modified time: 2020-08-09 01:33:40  */

#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
set<int> ans;

void find(int n) {
    arr.resize(n, 0);
    for (int i=0;i<n;i++) {
        arr[i]=i+1;
    }

    do {
        int i;
        for (int l1 = 1; l1<n; l1++) {
            for (int l2=1; l2<n-l1; l2++) {
                int n1=0, n2=0, m=0;
                int l3 = n - l1-l2;
                if (l3<l1 || l3<l2)
                    break;

                int k=0;
                for (int i=1;i<=l1;i++) {
                    n1 *=10;
                    n1 += arr[k++];
                }
                for (int i=1;i<=l2;i++) {
                    n2 *= 10;
                    n2 += arr[k++];
                }
                for (int i=1;i<=l3; i++) {
                    m *= 10;
                    m += arr[k++];
                }
                if (n1*n2 == m) {
                    ans.insert(m);
                }
            }
        }

    } while (next_permutation(arr.begin(), arr.end()));

    long sum = 0;
    for (auto &e: ans)
        sum += e;
    cout<<sum<<endl;
}

int main() {
    int n; cin>>n;
    find(n);
    return 0;
}
