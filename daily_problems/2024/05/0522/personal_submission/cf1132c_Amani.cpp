#include<bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 100;
int cnt[MAXN], l[MAXN], r[MAXN], pre[MAXN];

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l[i] >> r[i];
        for (int j = l[i]; j <= r[i]; j++) {
            cnt[j]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= q; i++) {
        int sum = 0;
        for (int j = l[i]; j <= r[i]; j++) {
            cnt[j]--;
        }
        memset(pre, 0, sizeof(pre));
        for (int j = 1; j <= n; j++) {
            if (cnt[j] == 1) {
                pre[j] += pre[j - 1] + cnt[j];
            } else {
                pre[j] = pre[j - 1];
            }
            if (cnt[j])sum++;
        }
        for (int k = i + 1; k <= q; k++) {
            ans = max(ans, sum - (pre[r[k]] - pre[l[k] - 1]));
        }
        for (int j = l[i]; j <= r[i]; j++) {
            cnt[j]++;
        }
    }
    cout << ans << endl;
}