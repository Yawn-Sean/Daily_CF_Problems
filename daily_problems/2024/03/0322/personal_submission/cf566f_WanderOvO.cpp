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

const int N = 1e6 + 10;
const int M = 15;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int MOD3 = 240011539;
const int P = 13331;
const int INF = 2e9 + 10;
const double eps = 1e-8;

/*
如果 a[i] | a[j], a[j] | a[k]，则 a[i] | a[k]
团内任意两个数都有整除关系，所以一个团内部的最大公约数就是最小的那个数
排序
以 a[i] 结尾的最长的前一个数能整除后一个数的序列长度
枚举 a[i] 的约数，DP 更新一下答案，O(nsqrt(n))肯定过不了
枚举当前最大值，然后枚举倍数，使用刷表法更新，复杂度是 O(nlogn)
*/

int T;
int n, cnt[N], dp[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        cnt[val]++;
    }
    int res = 0;
    for (int i = 1; i < N; i++) {
        dp[i] = max(dp[i], cnt[i]);
        for (int j = 2; j * i < N; j++) {
            if (cnt[i * j] > 0) {
                dp[i * j] = max(dp[i * j], dp[i] + cnt[i * j]);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
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