using namespace std;
using Pii = pair<int, int>;
const int N = 50050, mod = 998244353;
int g[N][25];
int n, m;

int powers(ll a, ll b, ll p){
    ll res = 1;
    while (b){
        if (b&1) res = res*a%p;
        a = a%p*a%p;
        b >>= 1;
    }
    return res;
} 
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j){
            int x;
            cin >> x;
            ++ g[j][x];
        }

    ll deno = 1;
    for (int i = 1; i <= n; ++ i) deno = deno*i;
    deno = powers(deno, mod-2, mod);
    int res = 0;
    for (int i = 1; i <= m; ++ i){
        int cnt = 0, sum = 1;
        for (int j = n; j >= 1; -- j) cnt += g[i][j+1], sum = 1ll*sum*cnt%mod, -- cnt;
        res = (res+1-1ll*deno*sum%mod + mod) % mod;
    }
    cout << res << "\n";
}
