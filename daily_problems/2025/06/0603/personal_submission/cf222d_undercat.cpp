#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,x;cin>>n>>x;
    vector<int>a(n),b(n);
    for(auto&i:a)cin>>i;
    for(auto&i:b)cin>>i;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int res=0;
    for(int i=0,r=n-1;i<n;i++){
        if((a[i]+b[r])>=x)res++,r--;
    }
    cout<<1<<' '<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}