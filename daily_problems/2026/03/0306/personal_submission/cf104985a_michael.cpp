#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<ll> vs(n),ts(n);
    ll total_v = 0;
    for(int i = 0; i < n; ++i){
        cin >> vs[i];
        cin >> ts[i];
        total_v += vs[i];
    }

    vector<int> order(n);
    iota(order.begin(),order.end(),0);
    sort(order.begin(),order.end(),[&] (int a,int b){return ts[a] < ts[b];});

    ll cur_v = total_v,cur_t = 0;
    vector<long double> ans(n);
    long double res = 0;
    for(auto e : order){
        res += (long double)(ts[e] - cur_t) * cur_v / total_v;
        ans[e] = res;
        cur_t = ts[e];
        cur_v -= vs[e];
    }
    cout << fixed << setprecision(15);
    for(auto e : ans) cout << e << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}