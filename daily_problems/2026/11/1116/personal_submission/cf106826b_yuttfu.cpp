#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 998244353;

ll qmi(ll a,int b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vector<int> in(n+1,0);
    for(int i = 1;i < n;i++){
        int u,v;
        cin >> u >> v;
        in[u] ++;
        in[v] ++;
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(in[i] == 1) cnt ++;
    }
    ll ans = qmi(2,n-cnt);
    ans = 1ll * ans * (n+2) % mod;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}