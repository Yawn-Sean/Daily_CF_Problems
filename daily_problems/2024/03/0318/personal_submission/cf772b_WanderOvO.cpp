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
typedef pair<double, double> PDD;

const int N = 200010;
const int M = 55;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int MOD3 = 240011539;
const int P = 13331;
const LL INF = 1e9 + 10;
const double eps = 1e-8;

/*
不要用余弦定理去解角度，误差太大！
*/

int T;
int n;
double x[N], y[N];

double getLen(PDD vec) {
    return sqrt(vec.x * vec.x + vec.y * vec.y);
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    x[0] = x[n];
    y[0] = y[n];
    x[n + 1] = x[1];
    y[n + 1] = y[1];
    
    double res = 2e9;
    for (int i = 1; i <= n; i++) {
        PDD v1 = {x[i] - x[i - 1], y[i] - y[i - 1]};
        PDD v2 = {x[i + 1] - x[i], y[i + 1] - y[i]};
        PDD v3 = {x[i + 1] - x[i - 1], y[i + 1] - y[i - 1]};
        double len3 = getLen(v3);
        // fabs(v1.x * v2.y - v1.y * v2.x) / 2 = S
        // S = len3 * h / 2
        // len3 * h = fabs(v1.x * v2.y - v1.y * v2.x)
        // h / 2 = fabs(v1.x * v2.y - v1.y * v2.x) / len3 / 2
        res = min(res, fabs(v1.x * v2.y - v1.y * v2.x) / len3 / 2);
    }
    printf("%.10lf\n", res);
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