#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int mx = a.back();
    vector<ll> f1(mx + 1), f2(mx + 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            f1[a[i] - a[j]]++;
    for (int i = 1; i <= mx; i++)
        for (int j = 1; i + j <= mx; j++)
            f2[i + j] += f1[i] * f1[j];
    ll ans = 0;
    for (int i = 1; i <= mx; i++)
        for (int j = 1; j < i; j++)
            ans += f2[j] * f1[i];
    ll sum = n * (n - 1) / 2;
    sum = sum * sum * sum;
    double ret = 1.0 * ans / sum;
    cout << fixed << setprecision(15) << ret << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}