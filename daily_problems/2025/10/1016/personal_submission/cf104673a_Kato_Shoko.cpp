#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    map<ll,ll>mp;
    for(int i=1e5;i>=0;i--){
        ll val=1;
        for(int j=0;j<=i;j++){
            if(val>1e9)break;
            mp[val]=i+1;
            val=val*(i-j)/(j+1);
        }
    }
    int q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        auto it=mp.find(x);
        if(it!=mp.end())cout<<it->second<<"\n";
        else cout<<x+1<<'\n';
    }
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
