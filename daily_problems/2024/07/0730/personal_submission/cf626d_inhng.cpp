#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n);
    for (int &ai: a) {
        cin >> ai;
    }
    vector<int> cnt(5000), cnt2(5000);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < i; ++j) {
            ++cnt[abs(a[i] - a[j])];
        }
    }
    for (int i = 0; i < 5000; ++i) {
        for (int j = 0; j < 5000 - i; ++j) {
            cnt2[i + j] += cnt[i] * cnt[j];
        }
    }
    for (int i = 1; i < 5000; ++i) {
        cnt2[i] += cnt2[i - 1];
        ans += cnt2[i - 1] * cnt[i];
    }
    cout<< (double)ans / pow((double)n * (n - 1) / 2, 3);
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
