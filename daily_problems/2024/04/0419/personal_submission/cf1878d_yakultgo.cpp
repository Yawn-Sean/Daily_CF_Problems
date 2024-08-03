#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> l(k, 0), r(k, 0);
    for (int i = 0; i < k; i++) cin >> l[i], l[i]--;
    for (int i = 0; i < k; i++) cin >> r[i], r[i]--;
    vector<int> cnt(n);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        x--;
        cnt[x]++;
    }
    for (int i = 0; i < k; i++) {
        int sum = 0;
        for (int j = l[i]; j <= (l[i] + r[i]) / 2; j++) {
            sum += cnt[j] + cnt[r[i] - j + l[i]];
            if (sum % 2) {
                swap(s[j], s[r[i] - j + l[i]]);
            }
        }
    }
    cout << s << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}