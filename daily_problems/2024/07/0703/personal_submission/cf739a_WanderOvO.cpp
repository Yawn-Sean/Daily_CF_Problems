// LUOGU_RID: 163688081
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
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<PII, PII> PIIII;
typedef pair<double, double> PDD;

const int N = 330010;
const int M = 20;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int MOD3 = 240011539;
const int P = 13331;
const int INF = 0x3f3f3f3f;
const LL INFLL = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-8;

/*
数组是否开够了大小？是否需要用 long long？是否需要更大的数据类型？
数据范围比较小，或者对某个量有不寻常的范围约束，是否仔细想了与其有关的较为暴力的做法？
数据范围比较大，是否数据范围是“真实”的？能否在常规做法的基础上通过一些性质大幅缩小有效范围？
发现的性质是否完全？是否不仅在某些情况下成立（尤其图论题）？
是否把题给条件翻译成数学表达了？是否在数学表达的基础上做了进一步推导和变形？
是否从特殊到一般入手思考问题？
想到做法了，是否写代码前用样例初步验证了做法的正确性与边界条件？
*/

/*
理论上的 mex 的最小值的最大值为最短的区间的长度（包括左右端点），这个上界是显然的
能否/如何达到这个上界？
假设最短区间是 len，我们考虑让每个为 len 的区间都充满这些数
1 3
2 5
4 5
0 1 2 0 0 1
*/

int T;
int n, m, l[N], r[N];

void solve1() {
    cin >> n >> m;
    int minlen = n;
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
        minlen = min(minlen, r[i] - l[i] + 1);
    }
    cout << minlen << "\n";
    int val = 0;
    for (int i = 1; i <= n; i++, val++) {
        val %= minlen;
        cout << val << " ";
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
    // solve2();
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