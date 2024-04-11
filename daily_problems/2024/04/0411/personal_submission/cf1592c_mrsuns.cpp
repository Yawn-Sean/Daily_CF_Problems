//#pragma GCC optimize(2,"Ofast")
//#pragma GCC optimize(3,"inline")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse4,popcnt,abm,mmx")
#include<bits/stdc++.h>
using namespace std;
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//--------------------------Abbreviations--------------------------//

#define x1 __________________
#define y1 ___________________
#define x2 ____________________
#define y2 _____________________
#define endl '\n'
#define uint unsigned int
#define int long long
using ll = long long;
using ld = long double;
using ull = unsigned long long;
//using lll = __int128;
using vi = vector<int>;
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
using ai2 = array<int, 2>;using ai3 = array<int, 3>;
using ai4 = array<int, 4>;using ai5 = array<int, 5>;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template<class Key> using uset = unordered_set<Key, custom_hash>;
template<class Key, class Value> using umap = unordered_map<Key, Value, custom_hash>;

//--------------------------Function--------------------------//

#define sqrt(x) sqrtl(x)
#define log2(x) (63 - __builtin_clzll(x))
#define Ones(x) __builtin_popcountll(x)
//#define max(a, b) ((a) > (b) ? (a) : (b))
//#define min(a, b) ((a) < (b) ? (a) : (b))
ld getld() { string x;cin >> x;return stold(x); }
template<typename T> inline bool chkmax(T& a, T b) { if (a >= b) return 0;a = b;return 1; }
template<typename T> inline bool chkmin(T& a, T b) { if (a <= b) return 0;a = b;return 1; }

//--------------------------Debug--------------------------//

#ifdef LOCAL
#define debug_(x) cerr << #x << " = " << (x) << ' '
#define debug(x) cerr << #x << " = " << (x) << '\n'
#define debugsq(x) cerr << #x << ": ["; for (auto i : x) cerr << i << ' '; cerr << "]\n";
#define debugmp(x) cerr << #x << ": [ "; for (auto [i, j] : x) cerr << '[' << i << "," << j << "] "; cerr << "]\n";
#define debugs(x...) do{cerr << #x << " : "; ERR(x);} while (0)
void ERR() { cerr << endl; } template <class T, class... Ts> void ERR(T arg, Ts ...args) { cerr << arg << ", ";ERR(args...); }
#else
#define debug(...) 'm'
#define debug_(...) 'r'
#define debugsq(...) 's'
#define debugmp(...) 'u'
#define debugs(...) 'n'
#define ERR() 's'
#endif

//--------------------------Constant--------------------------//

const ll inf = 1e18;
const int N = 2e5 + 10;
const int MOD = 1e9 + 7;//998244353
//const __int128 ONE = 1;

//--------------------------Other--------------------------//

int mx[]{ 0,-1,0,1 };
int my[]{ 1,0,-1,0 };
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define quit cout << "quit" << '\n'; return
template <class... Args> void myin(Args&... args) { ((cin >> args), ...); }
template <class... Args> void myout(const Args&... args) { ((cout << args), ...); }
//ofstream mcout("C:/Users/Mrsuns/Desktop/out.txt");
//ofstream mcout("C:/Users/Mrsuns/Desktop/out.txt");

//--------------------------END--------------------------//


void PreWork() {

}


void Solve(int TIME) {

    int n, k;cin >> n >> k;
    vi a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    int xsum = 0;for (int i = 1;i <= n;i++) xsum ^= a[i];
    debug(xsum);

    vvc<int> g(n + 1);
    for (int i = 1;i < n;i++) {
        int u, v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (xsum == 0) return YES, void();
    int cnt = 0;
    vi val(n + 1);
    auto dfs = [&](auto&& dfs, int u, int p)->void {
        val[u] = a[u];
        for (auto v : g[u]) {
            if (v == p) continue;
            dfs(dfs, v, u);
            if (val[v] == xsum) cnt++;
            else val[u] ^= val[v];
        }
        };
    dfs(dfs, 1, 1);

    if (cnt >= 2 && k >= 3) YES;else NO;


}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);

    PreWork();

    int T = 1;
    cin >> T;

    int TIME = 0;
    while (T--) {
        Solve(++TIME);
    }

    return 0;
}
