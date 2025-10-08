#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e7 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

vector<ll>per;

il auto euler(ll n,vector<bool>&vis){//欧拉筛
    vis[0]=vis[1]=false;
    vector<ll>prim;
    for(ll i=2;i<=n;i++){
        if(vis[i]){
            prim.push_back(i);
        }
        for(auto j:prim){
            if(j*i>n)break;
            vis[j*i]=false;
        }
    }
    vector<ll>per(n+5);
    for(int i=1;i<=n;i++){
        per[i]=per[i-1]+vis[i];
    }
    return per;
}


il void solve(){
    ll n;
    cin>>n;
    if(n<=3){
        cout<<n-2<<'\n';
        return ;
    }
    cout<<per[n]-per[n/2]<<'\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    cin >> t;

    vector<bool>vis(1e7+2,true);
    per=euler(1e7,vis);

    while (t--) {

        solve();

    }

    return 0;
}
