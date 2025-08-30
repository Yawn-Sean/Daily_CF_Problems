#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e5 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll n,k;
    cin>>n>>k;
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    for(int i=0;i<k;i++)pq.push(i);
    while(n--){
        ll s,m;
        cin>>s>>m;
        ll top=pq.top();
        pq.pop();
        top=max(top,s)+m;
        cout<<top<<'\n';
        pq.push(top);
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
