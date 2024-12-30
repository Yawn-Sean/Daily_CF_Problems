// 记T温度的水为温水，我们的目标就是尽可能获得多的温水，这可以通过综合冷热水得到，所以最后无法综合的时候必定只剩下一种水。
// 设这种水为冷水，那么我们的答案就是所有冷水的出水量 + 用来综合的热水量，为得到更多的热水量，应该优先考虑热水温度更小的。
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;
const int inf = 1e14;

void solve(int _) 
{
    int n, T;
    cin >> n >> T;
    vector<int> a(n), t(n);
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    for (int i = 0; i < n; i ++ ) cin >> t[i];

    vector<PII> cold, hot;
    double ans = 0;
    int cold_sum = 0, hot_sum = 0;
    for (int i = 0; i < n; i ++ ) {
        t[i] -= T;
        if (t[i] == 0) {
            ans += a[i];
            continue;
        } else if (t[i] < 0) {
            cold.emplace_back(-t[i], a[i]);
            cold_sum -= t[i] * a[i];
        } else {
            hot.emplace_back(t[i], a[i]);
            hot_sum += t[i] * a[i];
        }
    }

    if (cold_sum > hot_sum) {
        swap(cold_sum, hot_sum);
        swap(cold, hot);
    }

    sort(all(cold));
    sort(all(hot));

    for (auto [tt, aa]: cold) {
        ans += aa;
    }
    for (auto [tt, aa]: hot) {
        int cur = aa * tt;
        if (cold_sum >= cur) {
            ans += aa;
            cold_sum -= cur;
        } else {
            ans += 1.0 * cold_sum / tt;
            break;
        }
    }

    cout << fixed << setprecision(9) << ans << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}