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

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    int n, k;
    cin >> n >> k;
    cout << (6 * n - 1) * k << endl;
    for (int i = 0, j = 1; i < n; ++i) {
        cout << (6 * i + 2) * k << " ";
        cout << k * j << " ";
        j += 2;
        cout << k * j << " ";
        j += 2;
        cout << k * j << endl;
        j += 2;
    }
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
