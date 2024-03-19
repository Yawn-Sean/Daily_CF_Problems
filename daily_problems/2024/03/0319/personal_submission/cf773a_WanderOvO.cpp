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

const int N = 10010;
const int M = 15;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int MOD3 = 240011539;
const int P = 13331;
const LL INF = 1e9;
const double eps = 1e-8;

/*
预期正确率 p / q，目前正确率是 x / y
枚举倍数 t，然后让 y 变成 q * t，看 x 有没有可能变成 p * t
如果 p * t >= x 且 q * t >= y 且 p * t <= x + q * t - y，则有可能
p * t >= x 且 q * t >= y 且 (p - q) * t <= x - y，即 t >= (x - y) / (p - q)
假如某个 t 可行，能够让 x / y = (t * p) / (t * q)，则 t + 1 肯定也可行
所以有单调性，可以二分
*/

int T;
LL x, y, p, q;

bool check(LL t) {
    LL tp = t * p, tq = t * q;
    LL cnt = tq - y, cnt_ac = tp - x;
    return cnt_ac <= cnt;
}

void solve1() {
    cin >> x >> y >> p >> q;
    if (p == q) {
        if (x == y) {
            cout << "0\n";
        } else {
            cout << "-1\n";
        }
        return;
    }
    
    if (p == 0) {
        if (x == 0) {
            cout << "0\n";
        } else {
            cout << "-1\n";
        }
        return;
    }
    
    // 二分倍数
    LL l = max({(x + p - 1) / p, (y + q - 1) / q, (y - x) / (q - p)});
    LL r = INF, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(l)) {
        cout << q * l - y << "\n";
    } else if (check(r)) {
        cout << q * r - y << "\n";
    } else {
        cout << "-1\n";
    }
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
    cin >> T;
    prepare();
    while (T--) {
        init();
        solve();
    }
    
    return 0;
}