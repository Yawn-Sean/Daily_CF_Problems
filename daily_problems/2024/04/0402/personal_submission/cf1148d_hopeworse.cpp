// link : https://codeforces.com/contest/1148/submission/254649106
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr1,arr2;
    for(int i = 1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        if(x>y) arr1.emplace_back(y,i);
        if(x<y) arr2.emplace_back(y,i);
    }
    if(arr1.size()>arr2.size()){
        cout<<arr1.size()<<endl;
        sort(arr1.begin(),arr1.end(),less<>());
        for(auto [i,j]: arr1){
            cout<<j<<" ";
        }
        cout<<endl;
    }else{
        cout<<arr2.size()<<endl;
        sort(arr2.begin(),arr2.end(),greater<>());
        for(auto [i,j]: arr2){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
