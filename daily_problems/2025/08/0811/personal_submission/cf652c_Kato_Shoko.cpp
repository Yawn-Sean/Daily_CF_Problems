#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 3e5 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n+1),pos(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }

    map<ll,set<ll>>mp;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        mp[x].insert(pos[y]);
        mp[y].insert(pos[x]);
    }

    ll ans=0;
    vector<ll>per_min(n+1,0);
    for(int i=1;i<=n;i++){
        auto &st=mp[a[i]];
        auto it=st.lower_bound(i);
        if(it==st.begin()){
            per_min[i]=max(1ll,per_min[i-1]);
        }else{
            it--;
            per_min[i]=max(*it+1,per_min[i-1]);
        }
        ans+=i-per_min[i]+1;
    }
    cout<<ans;
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
