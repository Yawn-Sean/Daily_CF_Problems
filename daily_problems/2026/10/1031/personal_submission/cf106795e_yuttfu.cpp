#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct E{
    int t,c;
    bool operator<(const struct E & w) const {
        return t < w.t;
    }
};

void solve(){
    int n,r;
    cin >> n >> r;
    vector<E> a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i].t >> a[i].c;
    sort(a.begin()+1,a.end());
    int maxx = a[1].c;
    ll t = -1;
    for(int i = 2;i <= n;i++){
        ll l = 1ll*(a[i].t - a[i-1].t)*r + a[i-1].c;
        if(l < a[i].c){
            cout << -1 << '\n';
            return;
        }else if(l == a[i].c){
            maxx = max(maxx,a[i].c);
        }else{
            if(t == -1){
                t = l - a[i].c;
            }else{
                t = __gcd((ll)t,l-a[i].c);
            }
            maxx = max(maxx,a[i].c);
            if(t <= maxx){
                cout << -1 << '\n';
                return;
            }
        }
    }

    if(t == -1){
        cout << maxx + 1 << '\n';
    }else if(t > maxx){
        ll ans = t;
        for(int i = 1;i <= t/i;i++){
            if(t % i == 0){
                if(i > maxx) ans = min(ans,(ll)i);
                if(t/i > maxx) ans = min(ans,t/i);
            }
        }
        cout << ans << '\n';
    }else{
        cout << -1 << '\n';
    }
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