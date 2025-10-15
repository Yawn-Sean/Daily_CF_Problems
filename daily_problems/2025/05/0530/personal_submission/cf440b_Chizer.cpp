/**
 * Problem: B. Balancer
 * Contest: Testing Round 10
 * OnlineJudge: Codeforces
 * @Author: Chizer
 * DateTime: 2025-05-30 22:17
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
#define maxn 100005
using namespace std;

int T;

void solve() {
    int n;
    cin >> n;
    ll box[n + 1];
    ll sum = 0;
    rep(i, 1, n) {
        cin >> box[i];
        sum += box[i];
    }
    sum /= n;
    ll ans = 0;
    ll cur = 0;
    rep(i, 1, n) {
        cur += box[i] - sum;
        ans += abs(cur);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T = 1;
    //    cin >> T;
    while(T--) solve();
}
