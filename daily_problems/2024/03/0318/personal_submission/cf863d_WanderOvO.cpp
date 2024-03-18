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
const int M = 55;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int MOD3 = 240011539;
const int P = 13331;
const LL INF = 1e9 + 10;
const double eps = 1e-8;

/*
一共只询问 100 个位置
不妨直接看这些位置，然后每次操作只看这些位置发生了什么变化？
如果正着想的话，要考虑的下标还是太多，于是我们考虑倒着想，逆向推导出其对应原数组的哪个位置
*/

int T;
int op[N], l[N], r[N], a[N], b[N], n, q, m;

void solve1() {
    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> op[i] >> l[i] >> r[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        for (int j = q; j > 0; j--) {
            if (b[i] < l[j] || b[i] > r[j]) {
                continue;
            }
            if (op[j] == 1) {
                if (b[i] == l[j]) {
                    b[i] = r[j];
                } else {
                    b[i]--;
                }
            } else {
                b[i] = l[j] + r[j] - b[i];
            }
        }
        cout << a[b[i]] << " ";
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