#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 3e5 + 5, mod = 998244353, inf = 1e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    int n;
    cin>>n;
    vector<ll>a(n);
    for(auto &i:a)cin>>i;
    stack<pair<ll,ll>>st;
    ll ans=0;

    for(int i=0;i<n;i++){
        ll day=0;
        while(!st.empty()&&a[i]>=st.top().first){
            day=max(day,st.top().second);
            st.pop();
        }
        if(st.empty()){
            day=0;
        }else{
            day++;
        }
        ans=max(ans,day);
        st.push({a[i],day});
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
