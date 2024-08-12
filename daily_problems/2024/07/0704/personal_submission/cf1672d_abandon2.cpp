#include<bits/stdc++.h>
using namespace std;
const int N =2e5+10;
int a[N],b[N];

void solve(){
    int n;cin>>n;
    std::vector<int> v(n+1,0);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];

    int p=1;
    for(int i=1;i<=n;i++){
        while(b[i]!=a[p]&&p<=n){
            v[a[p++]]++;
        }
        if(p>n){
            cout<<"NO\n";return;
        }
        if(v[a[p]])v[a[p]]--;
        else p++;
    }
    
    cout<<"YES\n";return;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;while(tt--)
    solve();
    return 0;
}
