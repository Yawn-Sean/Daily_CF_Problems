#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    int sum = 0;
    int cnt[3]{};
    for (int i = 0; i < n; i++) {
        sum += t[i] - '0';
        int x = s[i] - '0' + t[i] - '0';
        cnt[x]++;
    }
    for (int cnt1 = 0; cnt1 <= sum; cnt1++) {
        int cnt2 = sum - cnt1;
        if (cnt2 % 2 == 1) continue;
        cnt2 /= 2;
        int cnt0 = n / 2 - cnt1 - cnt2;
        if(cnt0 < 0) continue;
        int val[3] = {cnt0, cnt1, cnt2};
        if (cnt0 <= cnt[0] && cnt1 <= cnt[1] && cnt2 <= cnt[2]) {
            for (int i = 0; i < n; i++) {
                int x = s[i] - '0' + t[i] - '0';
                if (val[x]) {
                    val[x]--;
                    cout << i + 1 << " ";
                }
            }
            return;
        }
    }
    cout << -1;
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