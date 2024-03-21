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
const int INF = 2e9 + 10;
const double eps = 1e-8;

/*
对于某个 h[i]，需要求 max(abs(h[i].x - c[j].x) + abs(h[i].y - c[j].y))
- 对于 h[i] 左上角的点，是 (h[i].x + h[i].y) - (c[j].x + c[j].y)
- 对于 h[i] 右上角的点，是 (h[i].x - h[i].y) - (c[j].x - c[j].y) 
- 对于 h[i] 左下角的点，是 -(h[i].x - h[i].y) + (c[j].x - c[j].y)
- 对于 h[i] 右下角的点，是 -(h[i].x + h[i].y) + (c[j].x + c[j].y)
求哪个 h[i] 的最大值最小

把 c 按照横纵坐标双关键字排序
从某个下标开始，从上半区变成了下半区
但是左右半区是来回跳的

羊的提示：到一个点的曼哈顿距离为 k 的所有点应该组成一个正方形，四条边是斜率为 1 或者 -1 的直线
羊的提示：两个点的曼哈顿距离，可以强行去绝对值号，不做任何分类讨论，直接求四种情况的最大值

问题就变成了对于每个 h[i]，求 max(max(那四个东西))，然后再把所有的 max 取 min
我们注意到在求 max(max(那四个东西)) 时，里面有两个不变量，可以提出来
这样我们单独计算这这四个东西中其中一个的所有的 max
*/

int T;
int n, m, cntc, cnth;
int cmax_plus = -INF, cmax_minus = -INF, cmin_plus = INF, cmin_minus = INF;
PII c[N], h[N];

void solve1() {
    cin >> n >> m;
    cin >> cntc;
    for (int i = 1; i <= cntc; i++) {
        cin >> c[i].x >> c[i].y;
        cmax_plus = max(cmax_plus, c[i].x + c[i].y);
        cmin_plus = min(cmin_plus, c[i].x + c[i].y);
        cmax_minus = max(cmax_minus, c[i].x - c[i].y);
        cmin_minus = min(cmin_minus, c[i].x - c[i].y);
    }
    cin >> cnth;
    int min_d = INF, min_pos = 0;
    for (int i = 1; i <= cnth; i++) {
        cin >> h[i].x >> h[i].y;
        int plus = h[i].x + h[i].y, minus = h[i].x - h[i].y;
        int d = max({plus - cmin_plus, minus - cmin_minus, -minus + cmax_minus, -plus + cmax_plus});
        if (d < min_d) {
            min_d = d;
            min_pos = i;
        }
    }
    
    cout << min_d << "\n" << min_pos << "\n";
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