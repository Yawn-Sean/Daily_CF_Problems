#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

void solve() { 
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    ll l = 0, pre = 0, cnt = 0, ans = 0, num = 0;
    for (int r = 0; r < n; r++) {
        cnt += (ll)(r - l) * (arr[r] - pre);
        while (cnt > k) {
            cnt -= arr[r] - arr[l];
            l++;
        }
        pre = arr[r];
        if (r - l + 1 > ans) {
            ans = r - l + 1;
            num = arr[r];
        }
    }
    cout << ans << " " << num;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
