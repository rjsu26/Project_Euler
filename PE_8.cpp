/* * @Title: Project Euler #8: Largest product in a series
 * @Author: raj sahu 
 * @Date: 2020-08-02 21:31:19   
 * @Last Modified time: 2020-08-02 21:31:19  */

#include <bits/stdc++.h>
using namespace std;

int findlargest(string num, int k){
    int maxans=1, temp=1,r,l;
    r=l=0;
    while(r-l<k){
        temp *= (num[r]-'0');
        r++;
    }
    r--;
    maxans = temp;

    for(;r<num.size()-1;){
        if(num[l]=='0'){
            l++; r=l; temp=1;
            while(r-l<k){
                temp *= (num[r]-'0');
                r++;
            }
            r--;
        }
        else{
            temp *= (num[++r]-'0');
            temp /= (num[l++] - '0');
        }
        maxans = max(temp, maxans);
    }
    return maxans;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int k;
        cin >> n >> k;
        string num;
        cin >> num;
        cout<<findlargest(num, k)<<endl;
    }
    return 0;
}