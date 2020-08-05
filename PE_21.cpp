/** @Title: Project Euler #21: Amicable numbers
* @Author: raj sahu  
* @Date: 2020-08-06 00:00:21   
* @Last Modified time: 2020-08-06 00:00:21  */

#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;
set<int> ans;

// Function to find sum of all proper factors of a number N. E.g: 10 has factors = 1, 2, 5, 10. Hence, 18-10 = 8 would be returned
int sum_factor(int N){
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
    return ans-n;
}

// Function to check for all numbers till N for amicable numbers 
void calculate_sum(int N){
    for(int i=2;i<=N;i++){
        int sum = sum_factor(i);
        if((i < sum) && i == sum_factor(sum) && i!=sum){
            ans.insert(sum);
            ans.insert(i);
        }
    }
}

/* Function to find sum of all amicable numbers under 'n' */
long findamicable(int n){
    long sum=0;
    for(auto &item: ans){
        if(item>n)
            break;
        sum += item;
    }
    return sum;
}

int main(){
    int t,n; cin>>t;
    vector<int> inp; 
    int mx;
    while(t--){
        cin>>n;
        inp.push_back(n);
        mx = max(mx, n);
    }
    calculate_sum(mx);
    for(int i=0;i<inp.size();i++)
        cout<<findamicable(inp[i])<<endl;
    return 0;
}