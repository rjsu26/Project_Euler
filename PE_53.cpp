#include<bits/stdc++.h>
using namespace std;

long fac(int N, int R){
    int ans=1;
    for(int r=0;r<R;r++)
        ans = (ans*(N-r))/(r+1);
    return ans;
}

int main(){
    int n,r;
    while(cin>>n){
        int ans=0, sr=1;
        for(int i=1;i<=n;i++){
            for(sr=0; sr<=i;sr++ ){
                long fact = fac(i,sr);
                if(fact>1000000){
                    cout<<"At i,j,fact "<<i<<" "<<sr<<" "<<fact<<endl;
                    cout<<"Adding "<<i-2*sr+1<<endl;
                    ans += i-2*(sr)+1;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0; 
}