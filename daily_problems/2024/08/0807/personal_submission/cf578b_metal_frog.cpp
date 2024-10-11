#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, k;
    ull x;
    cin >> n >> k >> x;
    vector<ull> a(n);
    vector<int> cnt(64);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        bitset<64> bits(a[i]);
        for (int bit = 0; bit < 64; bit++) {
            cnt[bit] += bits[bit];
        }
    }
    ull ans = 0;
    for (int i = 0; i < n; i++) {
        bitset<64> tmp(a[i]);
        for (int bit = 0; bit < 64; bit++) {
            cnt[bit] -= tmp[bit];
        }
        ull newVal = a[i];
        for (int t = 0; t < k; t++) {
            newVal *= x;
        }
        bitset<64> bitsNewVal(newVal);
        bitset<64> localRes;
        for (int bit = 0; bit < 64; bit++) {
            if (cnt[bit] > 0 || bitsNewVal[bit] > 0) {
                localRes.set(bit);
            }
        }
        for (int bit = 0; bit < 64; bit++) {
            cnt[bit] += tmp[bit];
        }
        ans = max(ans, localRes.to_ullong());
    }
    cout << ans << endl;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
