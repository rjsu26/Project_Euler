/* * @Title: Project Euler #23: Non-abundant sums
* @Author: raj sahu  
* @Date: 2020-08-06 02:39:53   
* @Last Modified time: 2020-08-06 02:39:53  */

#include<bits/stdc++.h>
using namespace std;

// Function to find if given number is greater than sum of its proper divisors or not.
bool is_abundant(int N){
    int n=N;
    long ans=1;
    for(int i=2;i*i<=N;i++){
        int sum=1, term=1;
        while(N%i==0){
            N /= i;
            term *= i;
            sum += term;
        }
        ans *= sum;
    }

    if(N>=2)
        ans *= (1+N);

    return (ans-n) >n;
}

vector<bool> abundent;
vector<int> nums;

// Calculate for all numbers between 12 and N whther they can be expressed as sum of two abundant numbers or not.
void calculate(int N){
    abundent.resize(N+1,false);
    int i;
    for( i=12;i<=(N-12); i++){
        abundent[i] = is_abundant(i);
        if(abundent[i])
            nums.push_back(i);
    }
}

bool isSum(int n){
    for(int i=0;i<nums.size() && nums[i]<=n; i++){
        if (abundent[n-nums[i]])
            {   cout<<"YES\n";
                return true;}
    }
    cout<<"NO\n";
    return false;
}

// Faster approach would be to generate all sums using abundant numbers only into a boolean array. This array can be used as a lookup table to give output.

int main(){
    int t,n; cin>>t;
    int mx=1;
    vector<int> inp; 
    while(t--){
        cin>>n;
        if(n<=28123)
            mx = max(mx, n);
        inp.push_back(n);
    }
    calculate(mx);
    for(int i=0;i<inp.size();i++){
        if(inp[i]<24 )
            cout<<"NO\n";
        else if(inp[i]>28123)
            cout<<"YES\n";
        else 
            isSum(inp[i]);
    }
    return 0;
}