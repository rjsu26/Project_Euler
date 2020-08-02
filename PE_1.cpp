/* * @Title:  Project Euler #1: Multiples of 3 and 5
* @Author: raj sahu  
* @Date: 2020-08-02 06:22:57   
* @Last Modified time: 2020-08-02 06:22:57  */

#include <iostream>

using namespace std;

bool divide3(long x){
    int n=0;
    while(x){
        n += x%10;
        x/=10;
    }
    return n%3==0;
}

long long solve(long N){
    long long sum=0;
    for(int i=3;i<N; i++){
        int x = i%10;
        if(x==0 || x==5 || divide3(i)==true)
            sum+= i;
    }
    return sum;
}

long long findsum(long n){
    return ((n+1)*n)/2;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        n--;
        long long a= 3*findsum(n/3);
        long long b = 5*findsum(n/5); 
        long long c = 15*findsum(n/15);
        cout<<a+b-c<<endl;
    }
    return 0;
}
