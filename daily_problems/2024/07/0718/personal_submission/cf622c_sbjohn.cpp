#include <bits/stdc++.h>

//#define DEBUG
#ifndef  DEBUG
#pragma GCC optimize("O3")
#endif
using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
constexpr int inf = INT32_MAX >> 1;
//constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()

void solve() {
    int n,m;cin>>n>>m;
    vi a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    vi nxt(n+1);
    nxt[n] = inf;
    for(int i=n-1;i>0;--i){
        if(a[i]==a[i+1]) nxt[i]=nxt[i+1];
        else nxt[i]=i+1;
    }
    while(m--){
        int l,r,x;cin>>l>>r>>x;
        if(a[l] == x) {
            if(nxt[l]>r) cout<<-1<<endl;
            else cout<<nxt[l]<<endl;
        }else cout<<l<<endl;
    }
}


int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
//    cin >> t;
    t = 1;
    while (t--) {
        solve();
    }

}






