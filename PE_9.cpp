/* * @Title: Project Euler #9: Special Pythagorean triplet 
* @Author: raj sahu  
* @Date: 2020-08-03 00:29:15   
* @Last Modified time: 2020-08-03 00:29:15  */

#include <bits/stdc++.h>
using namespace std;

long findgreatest(int N){
    int a=1,b,c;
    int temp = -1;
    for(; a<=N/3; a++){
        b = (N*N- 2*a*N)/(2*N-2*a);
        c = N - a- b;
        if(a*a + b*b == c*c)
            temp = max(temp, a*b*c);
    }
    return temp;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        cout<<findgreatest(n)<<endl;        
    }
    return 0;
}