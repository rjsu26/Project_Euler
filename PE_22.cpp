/* * @Title: Project Euler #22: Names scores 
* @Author: raj sahu  
* @Date: 2020-08-06 02:27:25   
* @Last Modified time: 2020-08-06 02:27:25  */
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool HACKERRANK = false;

int main() {
    int n, q, temp,i;
    string name;
    cin>>n;
    vector<string> names;
    map<string, int> mp;
    while(n--){    
        cin>>name;
        temp=i=0;
        while(i<name.size())
            temp+= name[i++]-'A' + 1;
        names.push_back(name);
        // cout<<name<<endl;
        mp[name]=temp;
    }
    sort(begin(names), end(names));
    unsigned long sum=0;
    for(int rank=1;rank<=names.size();rank++){
        mp[names[rank-1]] *= rank; 
        sum += mp[names[rank-1]];
    }
    if(HACKERRANK==false){
        cout<<sum<<endl;
    }
    else{
        cin>>q;
        while(q--){
            cin>>name;
            cout<<mp[name]<<endl;
        }
    }
    return 0;
}
