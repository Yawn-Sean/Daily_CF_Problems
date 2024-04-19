#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> l(k), r(k);
        for (int i = 0; i < k; i++) {
            cin >> l[i];
            l[i]--;
        }
        for (int i = 0; i < k; i++) {
            cin >> r[i];
            r[i]--;
        }
        int q, x;
        cin >> q;
        vector<int> cnt(n);
        for (int i = 0; i < q; i++) {
            cin >> x;
            x--;
            int idx = lower_bound(r.begin(), r.end(), x) - r.begin();
            int mn = min(x, r[idx] + l[idx] - x), mx = max(x, r[idx] + l[idx] - x);
            cnt[mn]++;
        }
        for (int i = 0; i < k; i++) {
            int li = l[i], ri = r[i];
            int tt = 0;
            for (int j = li; j <= (ri+li)/2; j++) {
                tt += cnt[j];
                if (tt & 1) swap(s[j], s[li+ri-j]);
            }
        }
        cout << s << '\n';
    }
    return 0;
}
