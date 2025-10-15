#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,x;cin>>n>>x;x--;
    vector<int>a(n);
    for(auto&i:a)cin>>i;
    int mi=1e9;
    for(auto i:a)mi=min(mi,i);
    for(auto&i:a)i-=mi;
    int v=mi*n;
    while(a[x]){
        a[x]--;
        v++;
        x--;
        if(x==-1)x=n-1;
    }
    a[x]=v;
    for(auto&i:a)cout<<i<< ' ';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}