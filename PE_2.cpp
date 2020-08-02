/* * @Title:  Project Euler #2: Even Fibonacci numbers
* @Author: raj sahu  
* @Date: 2020-08-02 06:22:57   
* @Last Modified time: 2020-08-02 06:22:57  */

#include <iostream>
using namespace std;

unsigned long long findsol(long n){
    long a =0, b=2, temp;
    unsigned long long sum=0;
    while(b<= n){
        sum += b;
        temp = b;
        b = 4*b+a;
        a = temp;
    }
    return sum;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        cout<<findsol(n)<<endl;
    }
    return 0;
}
