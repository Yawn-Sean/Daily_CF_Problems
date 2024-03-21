#include <bits/stdc++.h>
    
#define x first
#define y second
#define ls (k << 1)
#define rs (k << 1 | 1)
#define mp make_pair
#define pb push_back
    
using namespace std; 

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, char> PIC;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<LL, LL> PLL;
typedef pair<PII, PII> PIIII;

const int N = 200010;
const int M = 15;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int MOD3 = 240011539;
const int P = 13331;
const LL INF = 9e18;
const double eps = 1e-8;

/*
感觉是贪心买
i 的体积是 2^(i - 1)，价格是 c[i]
i < j，如果 c[i] * 2^(j - i) <= c[j]，则用 i 更好
除了恰好的，我们还要算更多的
*/

int T;
LL n, L, c[N];

LL qpow(LL a, LL b) {
    LL res = 1, base = a;
    while (b) {
        if (b & 1) {
            res *= base;
        }
        base *= base;
        b >>= 1;
    }
    return res;
}

void solve1() {
    cin >> n >> L;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    
    LL res = INF, ans = 0;
    for (int i = 30; i >= 0; i--) {
        if ((L >> i) & 1) {
            for (int j = i + 2; j <= n; j++) {
                res = min(res, ans + c[j]);
            }
            
            vector<LL> a;
            for (int j = 1; j <= min((LL)(i + 1), n); j++) {
                a.push_back(c[j] * qpow(2, i - j + 1));
            }
            sort(a.begin(), a.end());
            ans += a[0];
        } else {
            for (int j = i + 1; j <= n; j++) {
                res = min(res, ans + c[j]);
            }
        }
    }
    res = min(res, ans);
    cout << res << "\n";
}

void solve2() {
    
}
    
void prepare() {
    
}

void init() {

}
    
void solve() {
    solve1();
}
    
int main() {
    #ifdef LOCAL_TEST
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    T = 1;
    // cin >> T;
    prepare();
    while (T--) {
        init();
        solve();
    }
    
    return 0;
}