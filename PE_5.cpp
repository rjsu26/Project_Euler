/* * @Title: Project Euler #5: Smallest multiple 
* @Author: raj sahu  
* @Date: 2020-08-02 19:30:13   
* @Last Modified time: 2020-08-02 19:30:13  */

#include <bits/stdc++.h>
using namespace std;

long findsmallest(int n){
    int arr[n+1];
    for(int i=1;i<=n;i++)
        arr[i] = i;

    long ans = 1;
    for(int i=2;i<n;i++){
        ans *= arr[i];
        for(int j=i+1;j<=n;j++)
            if(arr[j]%arr[i]==0){
                arr[j] /= arr[i];
            }
    }
    ans *= arr[n];
    return ans;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout<<findsmallest(n)<<endl;
    }
    return 0;
}
