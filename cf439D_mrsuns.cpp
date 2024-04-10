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

    int n, m;cin >> n >> m;
    vi a(n + 1);for (int i = 1;i <= n;i++) cin >> a[i];
    vi b(m + 1);for (int i = 1;i <= m;i++) cin >> b[i];
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    vi pb(m + 1);for (int i = 1;i <= m;i++) pb[i] = pb[i - 1] + b[i];
    vi pa(n + 1);for (int i = 1;i <= n;i++) pa[i] = pa[i - 1] + a[i];
    auto sum = [&](const vi& pre, int l, int r) {
        if (l > r) return 0ll;
        return pre[r] - pre[l - 1];
        };
    int res = inf;
    for (int i = 1;i <= n;i++) {
        auto p = upper_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
        if (p == m + 1) res = min(res, i * a[i] - sum(pa, 1, i));
        else res = min(res, i * a[i] - sum(pa, 1, i) + sum(pb, p, m) - (m - p + 1) * a[i]);
        debug(res);debug(p);
    }

    for (int i = 1;i <= m;i++) {
        auto p = lower_bound(a.begin() + 1, a.end(), b[i]) - a.begin() - 1;
        res = min(res, sum(pb, i, m) - (m - i + 1) * b[i] + p * b[i] - sum(pa, 1, p));
    }
    cout << res << endl;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);

    PreWork();

    int T = 1;
    //cin >> T;

    int TIME = 0;
    while (T--) {
        Solve(++TIME);
    }

    return 0;
}
