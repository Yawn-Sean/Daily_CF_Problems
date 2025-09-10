#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e6 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

ll n,l;

il void dfs(ll now,vector<bool>&vis,auto &st){
    for(int i=2;i<=16;i++){
        if(vis[i]){
            ll new_now=now*(i+1);
            if(new_now<=l&&st.insert(new_now).second){
                dfs(new_now,vis,st);
            }
        }
    }
}

il void solve(){
    cin>>n>>l;
    l++;
    vector<bool>a(16);
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        a[x]=1;
    }
    set<ll>st={1};
    dfs(1,a,st);
    cout<<st.size()-1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
