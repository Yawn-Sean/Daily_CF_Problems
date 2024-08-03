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
    vector<PII> op;
    for (int &ai : a) {
        cin >> ai;
    }
    for (int i = 0; i < m; ++i) {
        int t, r;
        cin >> t >> r;
        while (op.size() and op.back().ss < r) {
            op.pop_back();
        }
        op.emplace_back(t - 1, r - 1);
    }
    op.emplace_back(0, -1);
    vector<int> num(a.begin(), a.begin() + op[0].ss + 1);
    ranges::sort(num);
    int left = 0, right = op[0].ss;
    for (int i = 0; i < op.size() - 1; ++i) {
        for (int j = op[i].ss; j > op[i + 1].ss; --j) {
            if (op[i].ff) {
                a[j] = num[left];
                left++;
            } else {
                a[j] = num[right];
                right--;
            }
        }
    }
    for (int ai : a) {
        cout << ai << " ";
    }
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
