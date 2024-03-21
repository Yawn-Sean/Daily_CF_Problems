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
const LL INF = 1e9;
const double eps = 1e-8;

/*
通过打表，发现 1689 全排列之后，对 7 取余数可以把 0-6 都取到
所以如果其他数不都是 0，则可以无脑把其他的放前面，根据余数 1689 的某个排列放最后
如果全是 0，则把余数是 0 的放最后即可
*/

int T;
int a[5] = {0, 1, 6, 8, 9};
bool vis[5];
map<LL, LL> p;

void dfs(int u, int val) {
    if (u == 5) {
        p[val % 7] = val;
        return;
    }
    for (int i = 1; i <= 4; i++) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(u + 1, 10 * val + a[i]);
            vis[i] = false;
        }
    }
}

void solve1() {
    dfs(1, 0);
    string s;
    cin >> s;
    int cnt[11] = {0};
    for (int i = 0; i < s.size(); i++) {
        cnt[s[i] - '0']++;
    }
    cnt[1]--;
    cnt[6]--;
    cnt[8]--;
    cnt[9]--;
    bool only_zero = true;
    for (int i = 1; i < 10; i++) {
        if (cnt[i] > 0) {
            only_zero = false;
        }
    }
    if (only_zero) {
        cout << p[0];
        for (int i = 0; i < cnt[0]; i++) {
            cout << "0";
        }
    } else {
        int val = 0;
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < cnt[i]; j++) {
                val = 10 * val + i;
                val %= 7;
                cout << i;
            }
        }
        val *= 10000;
        val %= 7;
        cout << p[(7 - val) % 7];
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