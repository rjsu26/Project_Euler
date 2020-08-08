/* * @Title: Project Euler #24: Lexicographic permutations 
* @Author: raj sahu  
* @Date: 2020-08-07 06:51:26   
* @Last Modified time: 2020-08-07 06:51:26  */

#include <bits/stdc++.h>
using namespace std;

void find_perm(long N){
    N--;
    long k = 2*3*4*5*6*7*8*9;
    int n=9;
    string s = "abcdefghij", ans;
    while(N!=0){
        long temp=N/k; 
        ans += s[temp];
        N = N%k;
        k /= n;
        n--;
        s = s.substr(0,temp) + s.substr(temp+1);
    }
    ans+= s;
    cout<<ans<<endl;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int t; cin>>t;
    while(t--){
        long N; cin>>N;
        find_perm(N);
    }
    return 0;
}
