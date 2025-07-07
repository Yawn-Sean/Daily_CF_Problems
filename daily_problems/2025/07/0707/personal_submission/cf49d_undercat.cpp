#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    auto get=[&](int x,int res=0)->int{
        for(int i=0;i<n;i++)res+=((s[i]=='1')!=(i+x)%2);
        return res;
    };
    cout<<min(get(1),get(0));
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}