/* #include<bits/allocator.h> */
/* #pragma GCC target("avx2") */
/* #pragma GCC optimize("O3") */
/* #pragma GCC optimize("unroll-loops") */

#include<bits/stdc++.h>
using namespace std;


#define int ll

using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;


#define fi first 
#define se second
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) int((x).size())


#ifdef LOCAL
namespace dbg {

template<class T, class = void>
struct is_iterable : std::false_type {};

template<class T>
struct is_iterable<T, std::void_t<
    decltype(std::begin(std::declval<T&>())),
    decltype(std::end  (std::declval<T&>()))
>> : std::true_type {};

inline void print(char c)                { std::cerr << '\'' << c << '\''; }
inline void print(const std::string& s)  { std::cerr << '\"' << s << '\"'; }
inline void print(bool b)                { std::cerr << (b ? "true" : "false"); }

template<class T>
std::enable_if_t<!is_iterable<T>::value> print(const T& x) { std::cerr << x; }

template<class A, class B>
void print(const std::pair<A,B>& p) {
    std::cerr << '{'; print(p.first); std::cerr << ','; print(p.second); std::cerr << '}';
}

template<class T>
std::enable_if_t<is_iterable<T>::value>
print(const T& a) {
    std::cerr << '{';
    bool first = true;
    for (const auto& x : a) {
        if (!first) std::cerr << ',';
        first = false;
        print(x);
    }
    std::cerr << '}';
}

inline void out() {}
template<class T, class... Ts>
inline void out(const T& x, const Ts&... xs) {
    print(x);
    if constexpr (sizeof...(xs)) { std::cerr << ", "; out(xs...); }
}

} // namespace dbg

#define deb(...) do { \
    std::cerr << "[ " << #__VA_ARGS__ << " ]" << " = [ "; \
    dbg::out(__VA_ARGS__); \
    std::cerr << " ]" << endl; \
} while(0)

#else
#define deb(...) ((void)0)
#endif


template<class T> bool ckmin(T& a, const T& b){ if(b < a){ a = b; return true; } return false; }
template<class T> bool ckmax(T& a, const T& b){ if(b > a){ a = b; return true; } return false; }

int max_bit(ll n){
    assert(n > 0);
    return 63 - __builtin_clzll(n);
}

bool bit(int mask, int i){
    return mask & (1 << i);
}



/* mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); */

constexpr int INF = 1e9;
constexpr ll INFL = 1e18;
constexpr ld EPS = 1e-10L;

/* constexpr int MOD = 1e9 + 7; */
constexpr int MAXN = 3e4;
constexpr int MAXK = 201;


void solve() {
    int n, k;
    cin >> n >> k;

    int l = 0, r = n;
    while(l + 1 < r) {
        int m = l + (r - l) / 2;

        int cur = n;
        for(int i = k; i >= 1; --i) {
            int can = min(m, cur / i);
            cur -= can * i;
        }
        /* deb(m, cur); */
        if(cur > 0) l = m;
        else r = m;
    }

    int cur = n;
    vi ans(k+1);
    for(int i = k; i >= 1; --i) {
        int can = min(r, cur / i);
        ans[i] = can;
        cur -= can * i;
    }
    for(int i = 1; i <= k; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}


int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    /* cout << fixed << setprecision(10); */


    int t = 1;
    /* cin >> t; */
    for(int i = 0; i < t; ++i) {
        solve();
    }

    return 0;
}
