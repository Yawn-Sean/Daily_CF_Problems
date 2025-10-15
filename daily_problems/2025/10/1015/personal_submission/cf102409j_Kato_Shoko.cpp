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
    ll n,l;
    cin>>n>>l;
    vector<ll>a;
    a.push_back(0);
    for(int i=1;i<n;i++){
        ll x;
        cin>>x;
        a.push_back(x);
    }
    a.push_back(l);

    ll ans=inf;

    for(int i=2;i<=n-2;i++){
        ll p2=a[i];
        ll needL = p2 / 2;
        auto itL = lower_bound(a.begin()+1, a.begin()+i, needL);
        vector<int> candL;
        if(itL != a.begin()+i) candL.push_back((int)(itL - a.begin()));
        if(itL != a.begin()+1) candL.push_back((int)(itL - a.begin() - 1));

        ll needR = (p2 + l) / 2;
        auto itR = lower_bound(a.begin()+i+1, a.begin()+n, needR);
        vector<int> candR;
        if(itR != a.begin()+n) candR.push_back((int)(itR - a.begin()));
        if(itR != a.begin()+i+1) candR.push_back((int)(itR - a.begin() - 1));

        for(int j : candL){
            ll len1 = a[j] - 0;
            ll len2 = p2 - a[j];
            for(int k : candR){
                ll len3 = a[k] - p2;
                ll len4 = l - a[k];
                ll maxx = max( max(len1,len2), max(len3,len4) );
                ll minn = min( min(len1,len2), min(len3,len4) );
                ans = min(ans, maxx - minn);
            }
        }
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
