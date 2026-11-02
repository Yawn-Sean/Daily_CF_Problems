#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using Key = array<int,2>;
constexpr Key MOD = {1000000007,1000000009};
const Key BASE = []{
    mt19937_64 rng(
        chrono::steady_clock::now().time_since_epoch().count()
    );

    return Key{
        uniform_int_distribution<int>(257,MOD[0] - 2)(rng),
        uniform_int_distribution<int>(257,MOD[1] - 2)(rng)
    };
}();

struct Hash{
    int n;
    vector<Key> h,p;

    void build(const vector<int>& s){
        n = (int)s.size();
        h.assign(n + 1, Key{0,0});
        p.assign(n + 1, Key{1,1});

        for(int i = 0;i < n;i++){
            for(int j = 0;j < 2;j++){
                p[i+1][j] = 1ll * p[i][j] * BASE[j] % MOD[j];
                h[i+1][j] = (1ll * h[i][j] * BASE[j] + s[i]) % MOD[j];
;            }
        }
    }
    explicit Hash(const vector<int>& s){
        build(s);
    }
    explicit Hash(const string& s){
        vector<int> a;
        a.reserve(s.size());
        for(unsigned char c : s){
            a.push_back(int(c) + 1);
        }
        build(a);
    }
    Key get(int l,int r)const{
        Key ans;
        for(int j = 0;j < 2;j++){
            ans[j] = (h[r][j] * p[r-1][j] % MOD[j] + MOD[j]) % MOD[j];
        }
        return ans;
    }
};


void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> a(k+1,0);
    for(int i = 1;i <= k;i++) a[i] = i;
    Hash ha(a);
    Key cur = ha.h[k+1];
    map<Key,int> cnt;
    cnt[cur] ++;
    int u,v;
    for(int i = 1;i <= n;i++){
        cin >> u >> v;
        ll x = a[u],y = a[v];
        for(int j = 0;j < 2;j++){
            ll t = cur[j];
            t = (t + (y - x) * ha.p[k-u][j]) % MOD[j];
            t = (t + (x - y) * ha.p[k-v][j]) % MOD[j];
            if(t < 0) t += MOD[j];
            cur[j] = int(t);
        }
        cnt[cur] ++;
        swap(a[u],a[v]);
    }
    ll ans = 0;
    for(auto [u,v] : cnt){
        ans += 1ll * v * (v-1) / 2;
    }
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
