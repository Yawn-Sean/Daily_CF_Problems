#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e5+10;
const int mod = 1e9 + 7;
long long C(long long n, int k, int N) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n / 2) {
        k = n - k;
    }

    long long res = 1;
    for (int i = 1; i <= k; ++i) {
        // 在乘法前检查是否会溢出 long long
        if (__builtin_mul_overflow(res, (n - i + 1), &res)) {
            return N + 1; // 返回一个比 N 大的值表示溢出/过大
        }
        res /= i;
        // 如果中间结果已经大于 N，提前返回
        if (res > N) {
            return N + 1;
        }
    }
    return res;
}
void solve() {
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        if(n == 1){
            cout << 1 << '\n';
            continue;
        }
        int ans = n;
        for(int k = 1; k < 17;k  ++){
            int l = 2 * k, r = ans;
            if(l > r)break;
            while(l < r){
                int mid = (l+r)/2;
                if(C(mid, k, n) < n)l = mid+1;
                else r = mid;
            }
            if(C(l, k, n) == n)ans = l;
        }
        cout << ans +1<< '\n';
    }    
}

signed cute_prov0nce() {
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
