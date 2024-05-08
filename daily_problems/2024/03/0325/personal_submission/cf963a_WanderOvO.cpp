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
const int M = 35;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int MOD3 = 240011539;
const int P = 13331;
const LL INF = 2e9;
const double eps = 1e-8;

/*
s[i] * a^(n - i) * b^i
s[i] * a^(n - i - k) * b^(i + k)
s[i] * a^(n - i) * b^i * sum(a^(-jk) * b^(jk)), j = 0, ... (n + 1) / k - 1

一共有 (n + 1) / k 个周期(题目保证了是整周期)
使用等比数列求和计算 sum 即可
*/

int T;
const int MOD = 1e9 + 9;
LL n, a, b, k;
string s;

LL qpow(LL a, LL b, LL MOD) {
    LL res = 1, base = a;
    while (b) {
        if (b & 1) {
            res *= base;
            res %= MOD;
        }
        base *= base;
        base %= MOD;
        b >>= 1;
    }
    return res % MOD;
}

void solve1() {
    cin >> n >> a >> b >> k >> s;
    LL res = 0;
    for (int i = 0; i < k; i++) {
        LL val = (s[i] == '+' ? 1 : -1);
        LL ap = qpow(a, n - i, MOD), bp = qpow(b, i, MOD);
        val *= ap;
        val %= MOD;
        val *= bp;
        val %= MOD;
        
        LL cnt = (n + 1) / k;
        LL inva = qpow(a, MOD - 2, MOD);
        LL invak = qpow(inva, k, MOD), bk = qpow(b, k, MOD);
        LL q = invak * bk % MOD;
        if (q == 1) {
            val *= cnt;
            val %= MOD;
        } else {
            LL sum = (qpow(q, cnt, MOD) - 1) * qpow(q - 1, MOD - 2, MOD) % MOD;
            val *= sum;
            val %= MOD;
        }
        res += val;
        res = (res % MOD + MOD) % MOD;
    }
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
