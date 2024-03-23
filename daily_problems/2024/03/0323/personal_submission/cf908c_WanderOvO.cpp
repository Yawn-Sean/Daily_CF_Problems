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

const int N = 1010;
const int M = 5010;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int MOD3 = 240011539;
const int P = 13331;
const LL INF = 1e9;
const double eps = 1e-8;

/*

*/

int T;

int n, r;
int x[N];
double y[N];

void solve1() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        double my = r;
        // (x[j] - x[i])^2 + (y[j] - y[i])^2 = 4 * r * r
        for (int j = 1; j < i; j++) {
            int dx = x[j] - x[i];
            if (dx * dx > 4 * r * r) {
                continue;
            }
            double dy = sqrt(4 * r * r - dx * dx);
            my = max(my, y[j] + dy);
        }
        y[i] = my;
        printf("%.10lf ", y[i]);
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
    // cin >> T;
    prepare();
    while (T--) {
        init();
        solve();
    }
    
    return 0;
}