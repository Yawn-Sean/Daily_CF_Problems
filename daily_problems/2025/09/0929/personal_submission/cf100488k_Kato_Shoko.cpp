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
    int n;
    cin>>n;
    ll x=0,sum=0;

    priority_queue<ll,vector<ll>,greater<ll>>pq;
    for(int i=1;i<=n;i++){
        ll a;cin>>a;
        sum+=a;
        ll cnt=(i+1)/2;
        if(cnt>pq.size()){
            x+=a;
            pq.push(a);
        }else if(pq.top()<a){
            x-=pq.top();
            pq.pop();
            x+=a;
            pq.push(a);
        }
    }

    cout<<x<<" "<<sum-x<<'\n';
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
