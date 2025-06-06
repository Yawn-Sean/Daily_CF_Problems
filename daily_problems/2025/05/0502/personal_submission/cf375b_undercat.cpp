#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    vector<string>s(n);
    for(auto&i:s)cin>>i;
    vector<int>cnt(n);
    int res=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(s[j][i]=='1')cnt[j]++;
            else cnt[j]=0;
        }
        auto t=cnt;
        sort(t.begin(),t.end());
        for(int j=0;j<n;j++){
            res=max(res,(n-j)*t[j]);
        }
    }
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}