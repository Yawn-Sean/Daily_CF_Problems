#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n,c;
    cin >> n >> c;
    vector<int> a(n+1,0);
    for(int i = 1;i <= n;i++) cin >> a[i];
    int t = 0;
    ll ans = 0;
    int id = n;
    int maxx = id * 2;
    while(id >= 1){
        if(t == 0){
            while(id >= 1 && a[id] == 0) id --;
            maxx = id * 2;
        }
        if(t + a[id] > c){
            t += a[id];
            t -= c;
            ans += maxx;
            maxx = id * 2;
            if(t >= c){
                ans += 1ll*(t/c)*maxx;
                t = t % c;
            }
        }else{
            t += a[id];
        }
        id --;
    }
    if(t) ans += maxx;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
