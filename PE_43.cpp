/* * @Title: Project Euler #43: Sub-string divisibility * @Author: raj sahu  * @Date: 2020-08-10 21:30:50   * @Last Modified time: 2020-08-10 21:30:50  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int arr[8]={2,3,5,7,11,13,17};

bool check(vector<int> &v){
    // cout<<"Standing at "<<v[0]<<v[1]<<endl;
    for(int i=1, k=0;i+2<v.size();i++, k++){
        int num=0, j=i;
        while(j<i+3){
            num *= 10;
            num += v[j];
            j++;
        }
        if(num%arr[k] !=0)
            return false;
    }
    return true;
}


void find(int n){
    unsigned long long sum=0;
        vector<int> inp;
        for(int i=0;i<=n; i++) inp.push_back(i);
        do{
            if(check(inp)){
                long num=0, j=0;
                while(j<inp.size()){
                    num *= 10;
                    num += inp[j];
                    j++;
                }
                sum += num;
            }
        }while(next_permutation(begin(inp), end(inp)));

    cout<<sum<<endl;
}

int main() {
    int n; cin>>n;
    find(n);
    return 0;
}
