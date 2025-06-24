#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    for(auto&i:a)cin>>i;
    for(int i=0;i<(n+1)/2;i++)a[i]-=i;
    for(int i=0;i<n/2;i++)a[n-1-i]-=i;
    map<int,int>mp;
    for(auto i:a){
        mp[i]++;
    }
    int res=n;
    for(auto[_,x]:mp){
        if(_>0)
            res=min(res,n-x);
    }
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}
