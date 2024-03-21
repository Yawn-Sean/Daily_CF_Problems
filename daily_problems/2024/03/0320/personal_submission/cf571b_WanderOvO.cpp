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

const int N = 300010;
const int M = 5010;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const int MOD3 = 240011539;
const int P = 13331;
const LL INF = 1e9;
const double eps = 1e-8;

/*
k = 1，则显然是排序
k = 2，总体来看奇数位置和偶数位置分别应该是排序后的结果
其实就是把数组按照下标 i % k 分成 k 份，每份分别有序，关键是怎么分比较好
显然整体排序也是满足上面的要求的，但是不一定最优
把数组排序，然后按照顺序遍历考虑往哪个子数组里面塞

羊神的提示：因为每组是排过序的，所以每一组的和其实就是最大元素 - 最小元素

一共 n 个元素，分 k 组，其中有 n % k 组有 n / k + 1 个元素，有 k - n % k 组有 n / k 个元素
最后的答案是这 k 组的最大值的和 - k 组的最小值的和
所以我们尽可能最大化最小值的和，最小化最大值的和
整个数组的最小值一定是某组的最小值，整个数组的最大值一定是某组的最大值
需要配对最小最大值
假设 a[i] 是某组的最小值，a[j] 是某组的最大值，则至少 j - i + 1 >= n / k
感觉一个组内的元素在排过序的原数组中是连续的肯定不会变差
所以问题变成了把 n 个数排序后，分成 k 段，每段是连续的，其中有 n % k 段是 n / k + 1 个元素
k - n % k 段有 n / k 个元素，最小代价是多少
*/

int T;
LL n, a[N], dp[M][M], k;

void solve1() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int cnt = n % k;
    int len = n / k;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= min(i, cnt); j++) {
            int st = (i - 1) * len + 1;
            if (i - 1 >= j) {
                // 第 i 段长度为 len
                dp[i][j] = dp[i - 1][j] + a[st + len - 1 + j] - a[st + j];
            }
            if (j != 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[st + len + j - 1] - a[st + j - 1]);
            }
        }
    }
    cout << dp[k][cnt] << endl;
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