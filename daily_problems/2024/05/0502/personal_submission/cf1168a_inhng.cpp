#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    
    function<bool(int)> check = [&](int mid) -> bool {
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] < mx) {
                if (a[i] + mid < mx) {
                    return false;
                }
            } else if (a[i] + mid < mx + m) {
                mx = a[i];
            }
        }
        return true;
    };
    
    int left = -1, right = m + 2;
    while (left + 1 < right) {
        int mid = (left + right) >> 1;
        (check(mid) ? right : left) = mid;
    }
    cout << left + 1 << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    solve();
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
