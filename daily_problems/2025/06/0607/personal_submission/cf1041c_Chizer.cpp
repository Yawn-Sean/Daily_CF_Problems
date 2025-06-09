/**
 * Problem: C. Coffee Break
 * Contest: Codeforces Round 509 (Div. 2)
 * OnlineJudge: Codeforces
 * @Author: Chizer
 * DateTime: 2025-06-07 20:05
 * 适度编程益脑，沉迷编程伤身，合理安排时间，享受快乐生活。
 */
#include "bits/stdc++.h"
#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define dep(i, j, k) for(int i = (j); i >= (k); --i)
using i64 = int64_t;
using f64 = double_t;
#define pb push_back
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define ull unsigned long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define maxn 200005
using namespace std;

int T;
int a[maxn];
int id[maxn];
int ans[maxn];

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    rep(i, 1, n) {
        cin >> a[i];
        id[i] = i;
    }
    sort(id + 1, id + n + 1, [&](int i, int j) {return a[i] < a[j];});
    int l = 1, r = n;
    while(l < r) {
        int f = 1;
        int mid = (l + r) >> 1;
        rep(i, mid + 1, n) {
            if(a[id[i]] - a[id[i - mid]] <= d) {
                f = 0;
                break;
            }
        }
        if(f) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    rep(i, 1, n) {
        ans[id[i]] = i % l + 1;
    }
    rep(i, 1, n) cout << ans[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    //    cin >> T;
    while(T--) solve();
}
